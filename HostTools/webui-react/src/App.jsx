import {memo, useCallback, useEffect, useLayoutEffect, useRef, useState} from 'react';
import {
  Button, Card, CardHeader,
  Toaster, toast,
} from 'noir-ui';

const AX = 17;
const DEF_WIN = 30;
const STREAM_HZ = 20;                // 与 webui/serve.py 一致
const MAXPTS = 60 * STREAM_HZ;
const PLOT_DRAW_MS = 50;             // 图表最多 20 fps
const STATS_UPDATE_MS = 200;         // 顶栏数字 5 Hz
const AXIS_UPDATE_MS = 100;          // 轴反馈 10 Hz
const CURVES = ['#ffffff', '#6ec8ff', '#ffb86b'];
const MONO = '"DM Mono", Consolas, monospace';
const AL = {1: 'INIT', 2: 'PRE-OP', 3: 'BOOT', 4: 'SAFE-OP', 8: 'OP'};
const CAPTURE = typeof location !== 'undefined' && location.hash === '#capture';
const ACC_NAMES = ['ax', 'ay', 'az'];
const GYRO_NAMES = ['gx', 'gy', 'gz'];
const RPY_NAMES = ['roll', 'pitch', 'yaw'];
const AXIS_NAMES = ['位置', '速度'];
const AXIS_ROWS = Array.from({length: AX}, (_, i) => i);
const CYCLE_OPTIONS = [
  {value: 500000, label: '2 kHz'},
  {value: 1000000, label: '1 kHz'},
  {value: 333333, label: '3 kHz'},
];
const nowMs = () =>
  (typeof performance !== 'undefined' ? performance.now() : Date.now());

const H = {
  rev: 0,
  t: [],
  acc: [[], [], []],
  gyro: [[], [], []],
  rpy: [[], [], []],
  axis: [[], []],
};

const ahrs = {q: [1, 0, 0, 0], e: [0, 0, 0], t: 0, aligned: false};
let selIndex = 0;

/* ───────── Mahony ───────── */
const qmul = (a, b) => {
  const [w1, x1, y1, z1] = a, [w2, x2, y2, z2] = b;
  return [
    w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2,
    w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2,
    w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2,
    w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2,
  ];
};
const euler = ([w, x, y, z]) => [
  Math.atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y)),
  Math.asin(Math.max(-1, Math.min(1, 2 * (w * y - z * x)))),
  Math.atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z)),
].map((v) => (v * 180) / Math.PI);

function mahony(acc, gyro, now) {
  const dt = Math.min(0.1, Math.max(1e-4, ahrs.t ? now - ahrs.t : 0.033));
  ahrs.t = now;
  const n = Math.hypot(...acc);
  if (n < 1e-3) return [0, 0, 0];
  const a = acc.map((v) => v / n);
  if (!ahrs.aligned) {
    const roll = Math.atan2(a[1], a[2]);
    const pitch = Math.atan2(-a[0], Math.hypot(a[1], a[2]));
    const cp = Math.cos(pitch / 2), sp = Math.sin(pitch / 2);
    const cr = Math.cos(roll / 2), sr = Math.sin(roll / 2);
    ahrs.q = [cr * cp, sr * cp, cr * sp, -sr * sp];
    ahrs.aligned = true;
    return euler(ahrs.q);
  }
  const q = ahrs.q;
  const qc = [q[0], -q[1], -q[2], -q[3]];
  const g = qmul(qmul(qc, [0, 0, 0, 1]), q).slice(1);
  const e = [
    a[1] * g[2] - a[2] * g[1],
    a[2] * g[0] - a[0] * g[2],
    a[0] * g[1] - a[1] * g[0],
  ];
  for (let i = 0; i < 3; i++) ahrs.e[i] += 0.05 * e[i] * dt;
  const w = [0, 1, 2].map((i) => gyro[i] + 2.0 * e[i] + ahrs.e[i]);
  const qd = qmul(q, [0, w[0], w[1], w[2]]).map((v) => v * 0.5);
  const nq = q.map((v, i) => v + qd[i] * dt);
  const norm = Math.hypot(...nq);
  ahrs.q = nq.map((v) => v / norm);
  return euler(ahrs.q);
}

/* ───────── 历史 ───────── */
function pushHist(s) {
  const t = s.t;
  if (H.t.length && (t - H.t[H.t.length - 1] > 1.0 || t < H.t[H.t.length - 1])) {
    H.t.length = 0;
    for (const k of ['acc', 'gyro', 'rpy', 'axis']) H[k].forEach((a) => (a.length = 0));
  }
  H.t.push(t);
  H.rev++;
  for (let i = 0; i < 3; i++) {
    H.acc[i].push(s.acc[i]);
    H.gyro[i].push(s.gyro[i]);
    H.rpy[i].push(s.rpy[i]);
  }
  const axis = s.axes[selIndex];
  H.axis[0].push(axis ? axis.pos : 0);
  H.axis[1].push(axis ? axis.vel : 0);
  if (H.t.length > MAXPTS) {
    H.t.shift();
    for (const k of ['acc', 'gyro', 'rpy', 'axis']) H[k].forEach((a) => a.shift());
  }
  schedulePlotPump();
}

function lowerBound(times, target) {
  let lo = 0, hi = times.length;
  while (lo < hi) {
    const mid = (lo + hi) >>> 1;
    if (times[mid] < target) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}

/* ───────── 画布 ───────── */
function fit(canvas) {
  const dpr = window.devicePixelRatio || 1;
  const w = canvas.clientWidth, h = canvas.clientHeight;
  if (canvas.width !== Math.round(w * dpr) || canvas.height !== Math.round(h * dpr)) {
    canvas.width = Math.round(w * dpr);
    canvas.height = Math.round(h * dpr);
  }
  const ctx = canvas.getContext('2d');
  ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
  return {ctx, w, h};
}

function grid(ctx, x, y, w, h) {
  ctx.strokeStyle = 'rgba(255,255,255,.06)';
  ctx.lineWidth = 1;
  for (let i = 1; i < 4; i++) {
    const yy = Math.round(y + (h * i) / 4) + 0.5;
    ctx.beginPath(); ctx.moveTo(x, yy); ctx.lineTo(x + w, yy); ctx.stroke();
    const xx = Math.round(x + (w * i) / 4) + 0.5;
    ctx.beginPath(); ctx.moveTo(xx, y); ctx.lineTo(xx, y + h); ctx.stroke();
  }
}

function drawSeries(ctx, x, y, w, h, t, data, color, t0, win, lo, hi, start) {
  if (data.length - start < 2) return;
  ctx.strokeStyle = color;
  ctx.lineWidth = 1.2;
  ctx.lineJoin = 'round';
  ctx.beginPath();
  for (let i = start; i < data.length; i++) {
    const px = x + w - ((t0 - t[i]) / win) * w;
    const py = y + h - ((data[i] - lo) / (hi - lo)) * h;
    i === start ? ctx.moveTo(px, py) : ctx.lineTo(px, py);
  }
  ctx.stroke();
}

/* 每张图的交互状态：null = 自动量程，否则锁定 [y0,y1] */
const views = new WeakMap();
function viewOf(c) {
  let v = views.get(c);
  if (!v) {
    v = {auto: true, y0: -1, y1: 1, cur0: -1, cur1: 1,
         px: 0, py: 0, pw: 1, ph: 1, win: DEF_WIN};
    views.set(c, v);
  }
  return v;
}

/* 鼠标悬停位置（CSS 像素） */
const hover = new WeakMap();

/* 所有图表共用一个绘制循环，避免 4 个 rAF 彼此竞争。 */
const plotJobs = new Set();
let plotFrame = 0;
let plotTimer = 0;
let plotLastDraw = 0;

function drawPlots() {
  plotFrame = 0;
  if (!plotJobs.size || document.visibilityState !== 'visible') return;
  plotLastDraw = nowMs();
  for (const job of plotJobs) {
    if (job.force || job.rev !== H.rev) {
      job.draw();
      job.rev = H.rev;
      job.force = false;
    }
  }
}

function schedulePlotPump() {
  if (plotFrame || plotTimer || !plotJobs.size) return;
  const wait = Math.max(0, PLOT_DRAW_MS - (nowMs() - plotLastDraw));
  plotTimer = setTimeout(() => {
    plotTimer = 0;
    plotFrame = requestAnimationFrame(drawPlots);
  }, wait);
}

function invalidatePlots() {
  for (const job of plotJobs) job.force = true;
  schedulePlotPump();
}

document.addEventListener('visibilitychange', () => {
  if (document.visibilityState === 'visible') invalidatePlots();
});

const label = (ctx, text, x, y, color = 'rgba(255,255,255,.38)', align = 'left') => {
  ctx.fillStyle = color;
  ctx.font = `9px ${MONO}`;
  ctx.textAlign = align;
  ctx.fillText(text, x, y);
};

function renderFlat(canvas, title, chan, names, unit, win) {
  const {ctx, w, h} = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const px = 54, py = 24, pw = w - px - 14, ph = h - py - 26;
  grid(ctx, px, py, pw, ph);
  const v = viewOf(canvas);
  Object.assign(v, {px, py, pw, ph, win});

  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;
  const start = lowerBound(H.t, t0 - win);

  // 只统计窗口内的数据，用于自动量程
  let lo = Infinity, hi = -Infinity;
  const n = H.t.length;
  for (let i = start; i < n; i++) {
    for (let k = 0; k < names.length; k++) {
      const y = H[chan][k][i];
      if (y < lo) lo = y;
      if (y > hi) hi = y;
    }
  }
  if (!isFinite(lo)) { lo = -1; hi = 1; }
  if (hi - lo < 1e-6) { lo -= 1; hi += 1; }
  const pad = (hi - lo) * 0.12;
  lo -= pad; hi += pad;

  if (v.auto) {
    v.cur0 = lo; v.cur1 = hi;
  } else {
    lo = v.y0; hi = v.y1; v.cur0 = lo; v.cur1 = hi;
  }

  names.forEach((_, i) =>
    drawSeries(ctx, px, py, pw, ph, H.t, H[chan][i], CURVES[i],
               t0, win, lo, hi, start));

  // 标题居中（pyqtgraph 默认居中）
  label(ctx, title, px + pw / 2, 15, 'rgba(255,255,255,.58)', 'center');

  // Y 轴单位竖排
  if (unit) {
    ctx.save();
    ctx.translate(11, py + ph / 2);
    ctx.rotate(-Math.PI / 2);
    label(ctx, unit, 0, 0, 'rgba(255,255,255,.38)', 'center');
    ctx.restore();
  }

  // X 轴刻度（-win .. 0），5~10 格
  const step = win <= 12 ? 2 : win <= 35 ? 5 : 10;
  for (let s = 0; s <= win; s += step) {
    const x = px + (pw * s) / win;
    ctx.strokeStyle = 'rgba(255,255,255,.12)';
    ctx.beginPath();
    ctx.moveTo(Math.round(x) + 0.5, py + ph);
    ctx.lineTo(Math.round(x) + 0.5, py + ph + 3);
    ctx.stroke();
    label(ctx, String(s - win), x, h - 8, 'rgba(255,255,255,.30)', 'center');
  }

  // Y 轴范围提示（左上角，避开 X 刻度）
  const tag = v.auto ? 'AUTO' : 'LOCK';
  label(ctx, `${tag}  ${lo.toFixed(1)}~${hi.toFixed(1)}`, px + 4, py + 11,
        'rgba(255,255,255,.22)', 'left');

  // 十字准星 + 数值
  const m = hover.get(canvas);
  if (m && m.x >= px && m.x <= px + pw && m.y >= py && m.y <= py + ph && n > 1) {
    const tWant = t0 - ((px + pw - m.x) / pw) * win;
    let idx = n - 1;
    for (let i = n - 1; i >= 0; i--) { if (H.t[i] <= tWant) { idx = i; break; } }
    const cx = px + pw - ((t0 - H.t[idx]) / win) * pw;
    ctx.strokeStyle = 'rgba(255,255,255,.42)';
    ctx.lineWidth = 1;
    ctx.beginPath();
    ctx.moveTo(Math.round(cx) + 0.5, py);
    ctx.lineTo(Math.round(cx) + 0.5, py + ph);
    ctx.stroke();

    const parts = names.map((nm, k) => {
      const y = H[chan][k][idx];
      return `${nm} ${Number.isFinite(y) ? y.toFixed(2) : '-'}`;
    });
    const text = `${(H.t[idx] - t0).toFixed(1)}s   ` + parts.join('   ');
    ctx.font = `10px ${MONO}`;
    const tw = ctx.measureText(text).width;
    const bx = Math.min(Math.max(px + 4, m.x + 12), px + pw - tw - 10);
    ctx.fillStyle = 'rgba(10,10,11,.92)';
    ctx.fillRect(bx - 5, py + 4, tw + 10, 18);
    ctx.strokeStyle = 'rgba(255,255,255,.18)';
    ctx.strokeRect(bx - 5, py + 4, tw + 10, 18);
    label(ctx, text, bx, py + 17, 'rgba(255,255,255,.88)', 'left');
  }

  names.forEach((nm, i) => {
    const lx = w - 14 - (names.length - 1 - i) * 42;
    ctx.fillStyle = CURVES[i];
    ctx.fillRect(lx - 14, 9, 9, 2);
    label(ctx, nm, lx, 14, 'rgba(255,255,255,.58)');
  });
}

function renderRpy(canvas, win) {
  const {ctx, w, h} = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const names = ['roll', 'pitch', 'yaw'];
  const px = 46, pw = w - px - 12;
  const band = (h - 24) / 3;
  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;
  const start = lowerBound(H.t, t0 - win);
  names.forEach((nm, i) => {
    const py = 18 + i * band;
    grid(ctx, px, py, pw, band - 10);
    let lo = Infinity, hi = -Infinity;
    for (let k = start; k < H.t.length; k++) {
      const y = H.rpy[i][k];
      if (y < lo) lo = y;
      if (y > hi) hi = y;
    }
    if (!isFinite(lo)) { lo = -1; hi = 1; }
    if (hi - lo < 1e-6) { lo -= 1; hi += 1; }
    const pad = (hi - lo) * 0.12;
    drawSeries(ctx, px, py, pw, band - 10, H.t, H.rpy[i], CURVES[i], t0,
               win, lo - pad, hi + pad, start);
    label(ctx, nm, 12, py + 10, 'rgba(255,255,255,.58)');
  });
  label(ctx, '姿态 · Mahony', 12, 14, 'rgba(255,255,255,.58)');
  label(ctx, `-${win}s`, px, h - 6, 'rgba(255,255,255,.30)');
  label(ctx, '0', px + pw, h - 6, 'rgba(255,255,255,.30)', 'right');
}

const Plot = memo(function Plot({title, kind, names, unit, header, win, onWin}) {
  const ref = useRef(null);
  const winRef = useRef(win);
  winRef.current = win;

  useEffect(() => {
    const canvas = ref.current;
    if (!canvas) return undefined;
    const draw = () => {
      if (kind === 'rpy') renderRpy(canvas, winRef.current);
      else renderFlat(canvas, title, kind, names, unit, winRef.current);
    };
    const job = {draw, rev: -1, force: true};
    plotJobs.add(job);
    schedulePlotPump();

    const c = canvas;
    const v = viewOf(c);
    const inside = (mx, my) =>
      mx >= v.px && mx <= v.px + v.pw && my >= v.py && my <= v.py + v.ph;

    const onMove = (e) => {
      const r = c.getBoundingClientRect();
      hover.set(c, {x: e.clientX - r.left, y: e.clientY - r.top});
      job.force = true;
    };
    const onLeave = () => {
      hover.delete(c);
      job.force = true;
    };
    const onWheel = (e) => {
      e.preventDefault();
      const r = c.getBoundingClientRect();
      const mx = e.clientX - r.left, my = e.clientY - r.top;
      if (e.shiftKey) {
        const opts = [10, 20, 30, 60];
        const i = opts.indexOf(winRef.current);
        const ni = Math.max(0, Math.min(opts.length - 1, i + (e.deltaY > 0 ? 1 : -1)));
        if (opts[ni] !== winRef.current) onWin?.(opts[ni]);
        return;
      }
      if (!inside(mx, my)) return;
      const cy = (my - v.py) / v.ph;
      const yAt = v.cur1 - cy * (v.cur1 - v.cur0);
      const f = e.deltaY > 0 ? 1.18 : 0.85;
      v.auto = false;
      v.y0 = yAt - (yAt - v.cur0) * f;
      v.y1 = yAt + (v.cur1 - yAt) * f;
      job.force = true;
    };

    let drag = null;
    const onDown = (e) => {
      const r = c.getBoundingClientRect();
      if (!inside(e.clientX - r.left, e.clientY - r.top)) return;
      drag = {y: e.clientY, y0: v.cur0, y1: v.cur1};
      try { c.setPointerCapture(e.pointerId); } catch (_) {}
    };
    const onDrag = (e) => {
      if (!drag) return;
      const span = drag.y1 - drag.y0;
      const d = (-(e.clientY - drag.y) / v.ph) * span;
      v.auto = false;
      v.y0 = drag.y0 + d;
      v.y1 = drag.y1 + d;
      job.force = true;
    };
    const onUp = (e) => {
      drag = null;
      try { c.releasePointerCapture(e.pointerId); } catch (_) {}
    };
    const onDbl = () => { v.auto = true; job.force = true; };
    const observer = new ResizeObserver(() => { job.force = true; });
    observer.observe(c);

    c.addEventListener('mousemove', onMove);
    c.addEventListener('mouseleave', onLeave);
    c.addEventListener('wheel', onWheel, {passive: false});
    c.addEventListener('pointerdown', onDown);
    c.addEventListener('pointermove', onDrag);
    c.addEventListener('pointerup', onUp);
    c.addEventListener('dblclick', onDbl);
    return () => {
      c.removeEventListener('mousemove', onMove);
      c.removeEventListener('mouseleave', onLeave);
      c.removeEventListener('wheel', onWheel);
      c.removeEventListener('pointerdown', onDown);
      c.removeEventListener('pointermove', onDrag);
      c.removeEventListener('pointerup', onUp);
      c.removeEventListener('dblclick', onDbl);
      observer.disconnect();
      plotJobs.delete(job);
      if (!plotJobs.size && plotFrame) {
        cancelAnimationFrame(plotFrame);
        plotFrame = 0;
      }
      if (!plotJobs.size && plotTimer) {
        clearTimeout(plotTimer);
        plotTimer = 0;
      }
    };
  }, [kind, title, names, unit, onWin]);
  return (
    <div className="plot-wrap">
      {header && <div className="plot-head">{header}</div>}
      <Card className="plot-card">
        <canvas ref={ref} />
      </Card>
    </div>
  );
});

/* ───────── 轴表 ───────── */
const AxisTable = memo(function AxisTable({onChange, axisRefs, fbRef, stRef}) {
  return (
    <div className="axis">
      <div className="axis-head">
        <span>轴</span><span>位置 °</span><span>速度 °/s</span><span>力矩 A</span>
        <span>Kp</span><span>Kd</span><span>反馈 °</span><span>状态</span>
      </div>
      <div className="axis-body">
        {AXIS_ROWS.map((i) => (
          <div className="axis-row" key={i}>
            <span className="idx">{String(i + 1).padStart(2, '0')}</span>
            {[0, 1, 2, 3, 4].map((c) => (
              <input
                key={c}
                type="number"
                step={c === 1 ? 5 : c === 2 ? 0.5 : c === 4 ? 0.5 : 1}
                defaultValue="0"
                ref={(el) => { (axisRefs.current[i] ||= [])[c] = el; }}
                onChange={onChange}
              />
            ))}
            <span className="fb" ref={(el) => (fbRef.current[i] = el)}>-</span>
            <span className="st" ref={(el) => (stRef.current[i] = el)}>-</span>
          </div>
        ))}
      </div>
    </div>
  );
});

function setElementText(element, value) {
  const text = String(value);
  if (element && element.textContent !== text) element.textContent = text;
}

function setText(ref, value) {
  setElementText(ref?.current, value);
}

const FastStat = memo(function FastStat({label, id, refs, sub = false}) {
  return (
    <div className="nr-stat fast-stat">
      <div className="nr-stat-top">
        <span className="nr-stat-label">{label}</span>
      </div>
      <div className="nr-stat-value" ref={(el) => { refs.current[id] = el; }}>-</div>
      {sub && <div className="nr-stat-sub" ref={(el) => { refs.current[id + 'Sub'] = el; }} />}
    </div>
  );
});

const CycleSwitch = memo(function CycleSwitch({value, onChange}) {
  const selectedIndex = Math.max(
    0,
    CYCLE_OPTIONS.findIndex((option) => option.value === value),
  );
  const rootRef = useRef(null);
  const thumbRef = useRef(null);
  const inkRef = useRef(null);
  const motionRef = useRef({
    x: 0, v: 0, target: 0, width: 0, ready: false, frame: 0, last: 0,
  });

  useLayoutEffect(() => {
    const root = rootRef.current;
    const thumb = thumbRef.current;
    const ink = inkRef.current;
    if (!root || !thumb || !ink) return undefined;

    const buttons = [...root.querySelectorAll('button')];
    const selected = buttons[selectedIndex];
    if (!selected) return undefined;
    const motion = motionRef.current;
    motion.target = selected.offsetLeft;
    motion.width = selected.offsetWidth;

    const place = () => {
      const speed = Math.abs(motion.v);
      const stretch = Math.min(.22, speed * 0.00032);
      thumb.style.width = `${motion.width}px`;
      thumb.style.transform = `translate3d(${motion.x.toFixed(2)}px,0,0)`;
      ink.style.transformOrigin = motion.v >= 0 ? '100% 50%' : '0% 50%';
      ink.style.transform = `scaleX(${1 + stretch})`;
    };

    const settle = () => {
      cancelAnimationFrame(motion.frame);
      motion.frame = 0;
      motion.x = motion.target;
      motion.v = 0;
      motion.ready = true;
      thumb.style.willChange = 'auto';
      ink.style.willChange = 'auto';
      ink.style.filter = 'none';
      ink.style.transform = 'none';
      place();
    };

    const reduceMotion = window.matchMedia?.(
      '(prefers-reduced-motion: reduce)',
    ).matches;
    if (!motion.ready || reduceMotion) {
      settle();
    } else {
      thumb.style.willChange = 'transform';
      ink.style.willChange = 'transform, filter';
      motion.last = nowMs();
      const step = (now) => {
        const dt = Math.min(.034, Math.max(.001, (now - motion.last) / 1000));
        motion.last = now;
        const parts = Math.max(1, Math.ceil(dt / .004));
        const h = dt / parts;
        for (let i = 0; i < parts; i++) {
          const force = -520 * (motion.x - motion.target) - 38 * motion.v;
          motion.v += force * h;
          motion.x += motion.v * h;
        }
        if (Math.abs(motion.target - motion.x) < .15 &&
            Math.abs(motion.v) < 4) {
          settle();
          return;
        }
        place();
        motion.frame = requestAnimationFrame(step);
      };
      motion.frame = requestAnimationFrame(step);
    }

    let observedWidth = root.clientWidth;
    const observer = new ResizeObserver(() => {
      if (root.clientWidth === observedWidth) return;
      observedWidth = root.clientWidth;
      const current = buttons[selectedIndex];
      if (!current) return;
      motion.target = current.offsetLeft;
      motion.width = current.offsetWidth;
      motion.x = motion.target;
      motion.v = 0;
      settle();
    });
    observer.observe(root);

    return () => {
      observer.disconnect();
      cancelAnimationFrame(motion.frame);
      motion.frame = 0;
    };
  }, [selectedIndex]);

  const choose = (nextIndex) => {
    if (nextIndex !== selectedIndex) onChange(CYCLE_OPTIONS[nextIndex].value);
  };

  return (
    <div
      ref={rootRef}
      className="cycle-switch"
      role="radiogroup"
      aria-label="主站周期"
      style={{'--cycle-index': String(selectedIndex)}}
    >
      <span className="cycle-thumb" ref={thumbRef} aria-hidden="true">
        <span className="cycle-ink" ref={inkRef} />
      </span>
      {CYCLE_OPTIONS.map((option, index) => {
        const selected = option.value === value;
        return (
          <button
            key={option.value}
            type="button"
            role="radio"
            aria-checked={selected}
            className={selected ? 'on' : ''}
            onClick={() => choose(index)}
          >
            {option.label}
          </button>
        );
      })}
    </div>
  );
});

/* ───────── App ───────── */
export default function App() {
  const [cycle, setCycle] = useState(500000);
  const [running, setRunning] = useState(false);
  const [masterAction, setMasterAction] = useState(null);
  const [ctrl, setCtrl] = useState(0);
  const [led, setLed] = useState('#ffffff');
  const [ledMode, setLedMode] = useState(0);
  const [sel, setSel] = useState(0);
  const [winSec, setWinSec] = useState(DEF_WIN);

  const axisRefs = useRef([]);
  const fbRef = useRef([]);
  const stRef = useRef([]);
  const statRefs = useRef({});
  const stateRef = useRef(null);
  const pillRef = useRef(null);
  const statusRef = useRef(null);
  const statusTextRef = useRef(null);
  const alcRef = useRef(null);
  const fbLineRef = useRef(null);
  const onlineRef = useRef(false);
  const selRef = useRef(0);
  const ctrlRef = useRef(0);
  const ledRef = useRef([255, 255, 255]);
  const ledModeRef = useRef(0);
  const cmdTimer = useRef(0);
  const actionRef = useRef(null);
  const startupTimer = useRef(0);

  useEffect(() => { ctrlRef.current = ctrl; }, [ctrl]);
  useEffect(() => { ledModeRef.current = ledMode; }, [ledMode]);
  useEffect(() => {
    const h = led.replace('#', '');
    ledRef.current = [parseInt(h.slice(0, 2), 16), parseInt(h.slice(2, 4), 16), parseInt(h.slice(4, 6), 16)];
  }, [led]);

  const post = useCallback((path, body) =>
    fetch(path, {method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify(body)})
      .then((r) => r.json()).catch(() => null), []);

  const sendCmd = useCallback(() => {
    const axes = Array.from({length: AX}, (_, i) =>
      (axisRefs.current[i] || [0, 0, 0, 0, 0]).map((el) => Number(el?.value) || 0));
    post('/api/cmd', {ctrl: ctrlRef.current, led: ledRef.current, led_mode: ledModeRef.current, axes});
  }, [post]);

  const scheduleCmd = useCallback(() => {
    clearTimeout(cmdTimer.current);
    cmdTimer.current = setTimeout(sendCmd, 120);
  }, [sendCmd]);

  const applyCtrl = (next) => {
    ctrlRef.current = next;
    setCtrl(next);
    sendCmd();
  };

  const applyLedMode = (mode) => {
    ledModeRef.current = mode;
    setLedMode(mode);
    sendCmd();
  };

  const handlePlotWindow = useCallback((next) => {
    setWinSec(next);
    invalidatePlots();
  }, []);

  const clearTelemetry = useCallback(() => {
    for (const [key, element] of Object.entries(statRefs.current)) {
      setElementText(element, key.endsWith('Sub') ? '' : '-');
    }
    setText(fbLineRef, '等待主站数据…');
  }, []);

  const paintLinkState = useCallback((text, state) => {
    const statusClass = `nr-status nr-status-${state}`;
    if (statusRef.current && statusRef.current.className !== statusClass) {
      statusRef.current.className = statusClass;
    }
    setText(statusTextRef, text);
    if (pillRef.current) {
      const pillClass = 'pill' +
        (state === 'live' ? ' ok' : state === 'busy' ? ' warn' : '');
      if (pillRef.current.className !== pillClass) pillRef.current.className = pillClass;
    }
  }, []);

  const paintOffline = useCallback((force = false) => {
    if (actionRef.current && !force) return;
    onlineRef.current = false;
    setText(alcRef, 'ALC -');
    paintLinkState('主站：未运行', 'off');
    setRunning(false);
    clearTelemetry();
  }, [clearTelemetry, paintLinkState]);

  useEffect(() => {
    let lastStats = 0;
    let lastAxes = 0;

    const updateStatus = (s) => {
      const alCode = s.al & 0x0f;
      const alText = AL[alCode] || (alCode ? '0x' + alCode.toString(16) : '—');
      const ok = s.al === 0x0008;

      paintLinkState('主站：' + alText, ok ? 'live' : 'busy');
      setText(alcRef, `ALC 0x${s.alc.toString(16).padStart(4, '0')}`);

      setElementText(statRefs.current.wkc, Math.round(s.wkc));
      setElementText(statRefs.current.fps, Math.round(s.fps));
      setElementText(statRefs.current.gap, s.gap.toFixed(1) + ' ms');
      setElementText(statRefs.current.rtt, Math.round(s.rtt) + 'us');
      setElementText(
        statRefs.current.rttSub,
        `${Math.round(s.rtt_min)} / ${Math.round(s.rtt_max)}`,
      );
      setElementText(statRefs.current.phase, Math.round(s.phase) + 'us');
      setElementText(
        statRefs.current.phaseSub,
        `max ${Math.round(s.phase_max ?? 0)}`,
      );
      setElementText(statRefs.current.mcu, Math.round(s.mcu) + 'us');
      setElementText(
        statRefs.current.mcuSub,
        `${Math.round(s.mcu_min)} / ${Math.round(s.mcu_max)}`,
      );
    };

    const updateAxes = (s) => {
      s.axes.forEach((a, i) => {
        setElementText(fbRef.current[i], a.pos.toFixed(2));
        const status = stRef.current[i];
        if (!status) return;
        const enabled = a.status & 1;
        const fault = a.status & 2;
        const valid = a.status & 0x20;
        setElementText(
          status,
          (enabled ? 'E' : '-') + (fault ? 'F' : '-') + (valid ? 'V' : '-'),
        );
        status.className = 'st' + (fault ? ' err' : enabled && valid ? ' on' : '');
      });

      const si = selRef.current;
      const selected = s.axes[si];
      if (selected) {
        setText(
          fbLineRef,
          `轴${String(si + 1).padStart(2, '0')}  id=${selected.id}  ` +
          `pos=${selected.pos.toFixed(2)}°  vel=${selected.vel.toFixed(1)}°/s  ` +
          `status=0x${selected.status.toString(16).padStart(4, '0')}\n` +
          `使能 ${selected.status & 1 ? 'Y' : '-'}   ` +
          `故障 ${selected.status & 2 ? 'Y' : '-'}   ` +
          `有效 ${selected.status & 0x20 ? 'Y' : '-'}`,
        );
      }
    };

    const es = new EventSource('/api/stream');
    es.onmessage = (ev) => {
      const s = JSON.parse(ev.data);
      if (!s.online) {
        paintOffline();
        return;
      }
      if (!onlineRef.current) {
        onlineRef.current = true;
        setRunning(true);
        if (actionRef.current === 'starting') {
          clearTimeout(startupTimer.current);
          actionRef.current = null;
          setMasterAction(null);
          toast.success('主站已启动');
        }
      }
      s.rpy = mahony(s.acc, s.gyro, s.t);
      stateRef.current = s;
      pushHist(s);
      const now = performance.now();
      if (now - lastAxes >= AXIS_UPDATE_MS) {
        lastAxes = now;
        updateAxes(s);
      }
      if (now - lastStats >= STATS_UPDATE_MS) {
        lastStats = now;
        updateStatus(s);
      }
    };
    es.onerror = () => paintOffline();
    return () => es.close();
  }, [paintLinkState, paintOffline]);

  useEffect(() => () => clearTimeout(startupTimer.current), []);

  const start = useCallback(async () => {
    if (actionRef.current) return;
    actionRef.current = 'starting';
    setMasterAction('starting');
    setRunning(true);
    onlineRef.current = false;
    clearTelemetry();
    paintLinkState('主站：启动中…', 'busy');

    const r = await post('/api/master', {action: 'start', cycle});
    if (actionRef.current !== 'starting') return;
    if (!r?.running) {
      actionRef.current = null;
      setMasterAction(null);
      paintOffline(true);
      toast.error('启动失败' + (r?.error ? '：' + r.error : ''));
      return;
    }
    if (r.online) {
      actionRef.current = null;
      setMasterAction(null);
      toast.success('主站已启动');
      return;
    }

    clearTimeout(startupTimer.current);
    startupTimer.current = setTimeout(() => {
      if (actionRef.current !== 'starting' || onlineRef.current) return;
      actionRef.current = null;
      setMasterAction(null);
      paintLinkState('主站：未进入 OP', 'busy');
      toast.error('主站 8 秒内未进入 OP，请检查从站状态或日志');
    }, 8000);
  }, [clearTelemetry, cycle, paintLinkState, paintOffline, post]);

  const stop = useCallback(async () => {
    if (actionRef.current === 'stopping') return;
    clearTimeout(startupTimer.current);
    actionRef.current = 'stopping';
    setMasterAction('stopping');
    setRunning(false);
    paintLinkState('主站：停止中…', 'busy');

    const r = await post('/api/master', {action: 'stop'});
    actionRef.current = null;
    setMasterAction(null);
    paintOffline(true);
    if (r) toast('主站已停止');
    else toast.error('停止命令未送达，请重试');
  }, [paintLinkState, paintOffline, post]);

  const reset = useCallback(async () => {
    if (actionRef.current) return;
    actionRef.current = 'resetting';
    setMasterAction('resetting');
    paintLinkState('从站：复位中…', 'busy');
    const r = await post('/api/master', {action: 'reset'});
    actionRef.current = null;
    setMasterAction(null);
    paintOffline(true);
    if (r?.reset) toast.success('从站已复位');
    else toast.error('复位失败' + (r?.error ? '：' + r.error : ''));
  }, [paintLinkState, paintOffline, post]);

  return (
    <div className="app" style={CAPTURE ? {pointerEvents: 'none'} : undefined}>
      <header className="bar">
        <Button variant="primary" onClick={start}
                disabled={running || masterAction !== null}>
          {masterAction === 'starting' ? '启动中…' : '启动主站'}
        </Button>
        <Button onClick={stop}
                disabled={!running || masterAction === 'stopping' ||
                          masterAction === 'resetting'}>
          {masterAction === 'stopping' ? '停止中…' : '停止主站'}
        </Button>
        <Button onClick={reset}
                disabled={running || masterAction !== null}>
          {masterAction === 'resetting' ? '复位中…' : '复位从站'}
        </Button>

        <span className="mono dim" style={{marginLeft: 8}}>周期</span>
        <CycleSwitch value={cycle} onChange={setCycle} />

        <span className="pill" ref={pillRef}>
          <span className="nr-status nr-status-off" ref={statusRef}>
            <i className="nr-status-dot" />
            <span ref={statusTextRef}>主站：未运行</span>
          </span>
        </span>
        <span className="mono dim" ref={alcRef}>ALC -</span>

        <div className="stats">
          <FastStat label="WKC" id="wkc" refs={statRefs} />
          <FastStat label="帧率" id="fps" refs={statRefs} />
          <FastStat label="最大间隔" id="gap" refs={statRefs} />
          <FastStat label="RTT 含调度" id="rtt" refs={statRefs} sub />
          <FastStat label="PDI 相位" id="phase" refs={statRefs} sub />
          <FastStat label="MCU 处理" id="mcu" refs={statRefs} sub />
        </div>
      </header>

      <main>
        <section className="col">
          <Card className="panel" spotlight={false}>
            <CardHeader title="01 控制" />
            <div className="row">
              <Button onClick={() => applyCtrl(ctrlRef.current | 1)}>全部使能</Button>
              <Button onClick={() => applyCtrl(ctrlRef.current & ~1)}>全部失能</Button>
            </div>
            <div className="row">
              <Button className="danger" onClick={() => applyCtrl(ctrlRef.current | 2)}>急停</Button>
              <Button onClick={() => applyCtrl(ctrlRef.current & ~2)}>解除急停</Button>
            </div>
            <div className="row">
              <Button block onClick={() => { toast('命令已清零'); scheduleCmd(); }}>命令清零</Button>
            </div>
            <div className="row">
              <span className="mono dim">LED</span>
              <input type="color" value={led} onChange={(e) => setLed(e.target.value)} />
              <Button onClick={() => { applyLedMode(1); toast.success('LED 已应用'); }}>应用到 LED</Button>
              <Button onClick={() => applyLedMode(0)}>状态色</Button>
            </div>
            <div className="mono dim">ctrl=0x{ctrl.toString(16).padStart(2, '0')}</div>
          </Card>

          <Card className="panel grow" spotlight={false}>
            <CardHeader title="02 轴命令" />
            <AxisTable onChange={scheduleCmd} axisRefs={axisRefs}
                       fbRef={fbRef} stRef={stRef} />
          </Card>

          <Card className="panel" spotlight={false}>
            <CardHeader title="03 反馈" />
            <div className="mono dim" ref={fbLineRef}>等待主站数据…</div>
          </Card>
        </section>

        <div className="plots-wrap">
          <div className="charts-ctl">
            <span>窗口</span>
            {[10, 20, 30, 60].map((s) => (
              <button
                key={s}
                className={'chip' + (winSec === s ? ' on' : '')}
                onClick={() => setWinSec(s)}
              >{s}s</button>
            ))}
            <button
              className="chip"
              onClick={() => {
                document.querySelectorAll('.plot-card canvas').forEach((c) => {
                  const v = views.get(c);
                  if (v) v.auto = true;
                });
                invalidatePlots();
              }}
            >全部自动</button>
            <span className="hint">滚轮缩 Y · 拖动平移 · 双击自动 · Shift+滚轮改窗口</span>
          </div>

          <section className="plots">
          <Plot title="加速度 (m/s²)" kind="acc" names={ACC_NAMES} unit="m/s²"
                win={winSec} onWin={handlePlotWindow} />
          <Plot title="角速度 (rad/s)" kind="gyro" names={GYRO_NAMES} unit="rad/s"
                win={winSec} onWin={handlePlotWindow} />
          <Plot title="姿态 · Mahony" kind="rpy" names={RPY_NAMES}
                win={winSec} onWin={handlePlotWindow} />
          <Plot
            title={`选中轴 ${String(sel + 1).padStart(2, '0')}`}
            kind="axis"
            names={AXIS_NAMES}
            unit="° / °/s"
            win={winSec}
            onWin={handlePlotWindow}
            header={
              <>
                <span>轴</span>
                <select
                  value={sel}
                  onChange={(e) => {
                    selIndex = Number(e.target.value);
                    selRef.current = selIndex;
                    setSel(selIndex);
                    H.axis[0].length = 0;
                    H.axis[1].length = 0;
                    H.rev++;
                    invalidatePlots();
                  }}
                >
                  {Array.from({length: AX}, (_, i) => (
                    <option key={i} value={i}>轴 {String(i + 1).padStart(2, '0')}</option>
                  ))}
                </select>
                <span>曲线窗口 {winSec} s @ {STREAM_HZ} Hz</span>
              </>
            }
          />
          </section>
        </div>
      </main>
      <Toaster />
    </div>
  );
}
