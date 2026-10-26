/* NOIR Web UI — 数据来自 /api/stream (SSE)，命令写回 /api/cmd */

const AX = 17;
const MONO = '"DM Mono", Consolas, monospace';
const CURVES = ['#ffffff', '#6ec8ff', '#ffb86b'];
const WINDOW = 30;              // 秒
const MAXPTS = 900;             // 30 Hz × 30 s

const $ = (s) => document.querySelector(s);
const clamp = (v, a, b) => Math.min(b, Math.max(a, v));

function notify(msg, ms = 2600) {
  let el = document.getElementById('nr-toast');
  if (!el) {
    el = document.createElement('div');
    el.id = 'nr-toast';
    el.className = 'toast';
    document.body.appendChild(el);
  }
  el.textContent = msg;
  el.classList.add('show');
  clearTimeout(el._t);
  el._t = setTimeout(() => el.classList.remove('show'), ms);
}

let state = null;
let masterRunning = false;
let cycle = 500000;
let ctrl = 0;
let led = [255, 255, 255];
let ledMode = 0;

/* ───────────────────────── 轴表 ───────────────────────── */

const axisInputs = [];
const axisFb = [];
const axisSt = [];

function buildAxisRows() {
  const body = $('#axis-rows');
  const frag = document.createDocumentFragment();
  for (let i = 0; i < AX; i++) {
    const row = document.createElement('div');
    row.className = 'axis-row';
    row.innerHTML = `<span class="idx">${String(i + 1).padStart(2, '0')}</span>`;
    const inputs = [];
    for (const [v, step] of [[0, 1], [0, 5], [0, 0.5], [0, 5], [0, 0.5]]) {
      const inp = document.createElement('input');
      inp.type = 'number';
      inp.value = v;
      inp.step = step;
      inp.addEventListener('input', scheduleCmd);
      row.appendChild(inp);
      inputs.push(inp);
    }
    const fb = document.createElement('span');
    fb.className = 'fb';
    fb.textContent = '-';
    const st = document.createElement('span');
    st.className = 'st';
    st.textContent = '-';
    row.appendChild(fb);
    row.appendChild(st);
    frag.appendChild(row);
    axisInputs.push(inputs);
    axisFb.push(fb);
    axisSt.push(st);
  }
  body.appendChild(frag);
}

function axesPayload() {
  return axisInputs.map((r) => r.map((el) => Number(el.value) || 0));
}

/* ───────────────────────── 命令 ───────────────────────── */

let cmdTimer = 0;
function scheduleCmd() {
  clearTimeout(cmdTimer);
  cmdTimer = setTimeout(pushCmd, 120);
}

async function post(path, body) {
  try {
    const r = await fetch(path, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(body),
    });
    return await r.json();
  } catch (e) {
    return null;
  }
}

function pushCmd() {
  $('#ctrl-label').textContent = 'ctrl=0x' + ctrl.toString(16).padStart(2, '0');
  post('/api/cmd', { ctrl, led, led_mode: ledMode, axes: axesPayload() });
}

function setBit(bit, on) {
  ctrl = on ? (ctrl | bit) : (ctrl & ~bit);
  pushCmd();
}

/* ───────────────────────── 数字滚动 ───────────────────────── */

const rollers = new WeakMap();
function roll(el, value, fmt) {
  let r = rollers.get(el);
  if (!r) {
    r = { cur: value, target: value, raf: 0, fmt };
    rollers.set(el, r);
    el.textContent = fmt(value);
    return;
  }
  r.target = value;
  r.fmt = fmt;
  if (!r.raf) r.raf = requestAnimationFrame(() => stepRoll(el, r));
}

function stepRoll(el, r) {
  const d = r.target - r.cur;
  if (Math.abs(d) < 0.05) {
    r.cur = r.target;
    r.raf = 0;
  } else {
    r.cur += d * 0.24;
    r.raf = requestAnimationFrame(() => stepRoll(el, r));
  }
  el.textContent = r.fmt(r.cur);
}

/* ───────────────────────── 分段控件 ───────────────────────── */

const seg = $('#seg');
const thumb = seg.querySelector('.seg-thumb');
const ink = seg.querySelector('.seg-ink');
const segBtns = [...seg.querySelectorAll('button')];

let segIndex = 0;
let segTarget = 0;
let segX = 0;
let segV = 0;
let segRaf = 0;

function segWidth() {
  return (seg.clientWidth - 4) / segBtns.length;
}

function segXAt(i) {
  return 2 + i * segWidth();
}

function segApply() {
  const w = segWidth();
  const trail = Math.min(Math.abs(segV) * 0.048, 16);
  const stretch = 1 + Math.min(0.42, (trail / Math.max(1, w)) * 0.55);
  const blur = Math.min(6, Math.sqrt(trail) * 0.85);
  const sx = segV >= 0 ? segX : segX + w * (1 - stretch);
  thumb.style.width = w + 'px';
  thumb.style.transform = `translate3d(${sx}px,0,0)`;
  ink.style.transformOrigin = segV >= 0 ? 'left center' : 'right center';
  ink.style.transform = `scaleX(${stretch})`;
  ink.style.filter = blur > 0.06 ? `blur(${blur}px)` : 'none';
}

function segTick() {
  const K = 520, Z = 0.95, dt = 1 / 60;
  const c = 2 * Math.sqrt(K) * Z;
  const a = K * (segTarget - segX) - c * segV;
  segV += a * dt;
  segX += segV * dt;
  segApply();
  if (Math.abs(segTarget - segX) < 0.5 && Math.abs(segV) < 8) {
    segX = segTarget;
    segV = 0;
    segApply();
    segRaf = 0;
    return;
  }
  segRaf = requestAnimationFrame(segTick);
}

function segSelect(i, animate = true) {
  if (i === segIndex && animate) return;
  segIndex = i;
  segTarget = segXAt(i);
  cycle = Number(segBtns[i].dataset.v);
  if (!animate) {
    segX = segTarget;
    segV = 0;
    segApply();
    return;
  }
  if (!segRaf) segRaf = requestAnimationFrame(segTick);
}

segBtns.forEach((b, i) => {
  b.addEventListener('click', async () => {
    if (i === segIndex) return;
    segSelect(i);
    if (masterRunning) {
      await post('/api/master', { action: 'stop' });
      await new Promise((r) => setTimeout(r, 400));
      const res = await post('/api/master', { action: 'start', cycle });
      masterRunning = !!(res && res.running);
    }
  });
});

/* ───────────────────────── Mahony ───────────────────────── */

const ahrs = { q: [1, 0, 0, 0], e: [0, 0, 0], t: 0, aligned: false };

function qmul(a, b) {
  const [w1, x1, y1, z1] = a, [w2, x2, y2, z2] = b;
  return [
    w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2,
    w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2,
    w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2,
    w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2,
  ];
}

function mahony(acc, gyro, now) {
  const dt = clamp(ahrxDt(now), 1e-4, 0.1);
  const n = Math.hypot(...acc);
  if (n < 1e-3) return [0, 0, 0];
  const a = acc.map((v) => v / n);
  let q = ahrs.q;

  if (!ahrs.aligned) {
    const roll = Math.atan2(a[1], a[2]);
    const pitch = Math.atan2(-a[0], Math.hypot(a[1], a[2]));
    const cp = Math.cos(pitch / 2), sp = Math.sin(pitch / 2);
    const cr = Math.cos(roll / 2), sr = Math.sin(roll / 2);
    ahrs.q = [cr * cp, sr * cp, cr * sp, -sr * sp];
    ahrs.aligned = true;
    return euler(ahrs.q);
  }

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
  q = q.map((v, i) => v + qd[i] * dt);
  const norm = Math.hypot(...q);
  ahrs.q = q.map((v) => v / norm);
  return euler(ahrs.q);
}

function ahrxDt(now) {
  const dt = ahrs.t ? now - ahrs.t : 0.033;
  ahrs.t = now;
  return dt;
}

function euler([w, x, y, z]) {
  const r = Math.atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y));
  const p = Math.asin(clamp(2 * (w * y - z * x), -1, 1));
  const yw = Math.atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z));
  return [r, p, yw].map((v) => (v * 180) / Math.PI);
}

/* ───────────────────────── 历史缓冲 ───────────────────────── */

const H = {
  t: [],
  acc: [[], [], []],
  gyro: [[], [], []],
  rpy: [[], [], []],
  axis: [[], []],
};

function pushHist() {
  if (!state) return;
  const t = state.t;
  // 主站重启 / 页面刚打开时可能读到一段陈旧的 t，出现时间跳跃就清空重来
  if (H.t.length && (t - H.t[H.t.length - 1] > 1.0 || t < H.t[H.t.length - 1])) {
    H.t.length = 0;
    for (const k of ['acc', 'gyro', 'rpy', 'axis']) H[k].forEach((a) => (a.length = 0));
  }
  H.t.push(t);
  for (let i = 0; i < 3; i++) {
    H.acc[i].push(state.acc[i]);
    H.gyro[i].push(state.gyro[i]);
    H.rpy[i].push(state.rpy[i]);
  }
  H.axis[0].push(state.axes[selIndex].pos);
  H.axis[1].push(state.axes[selIndex].vel);
  if (H.t.length > MAXPTS) {
    H.t.shift();
    for (const k of ['acc', 'gyro', 'rpy', 'axis']) H[k].forEach((a) => a.shift());
  }
}

/* ───────────────────────── 画布 ───────────────────────── */

function fit(canvas) {
  const dpr = window.devicePixelRatio || 1;
  const w = canvas.clientWidth, h = canvas.clientHeight;
  if (canvas.width !== Math.round(w * dpr) || canvas.height !== Math.round(h * dpr)) {
    canvas.width = Math.round(w * dpr);
    canvas.height = Math.round(h * dpr);
  }
  const ctx = canvas.getContext('2d');
  ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
  return { ctx, w, h };
}

function grid(ctx, x, y, w, h) {
  ctx.strokeStyle = 'rgba(255,255,255,.06)';
  ctx.lineWidth = 1;
  for (let i = 1; i < 4; i++) {
    const yy = Math.round(y + (h * i) / 4) + 0.5;
    ctx.beginPath(); ctx.moveTo(x, yy); ctx.lineTo(x + w, yy); ctx.stroke();
  }
  for (let i = 1; i < 4; i++) {
    const xx = Math.round(x + (w * i) / 4) + 0.5;
    ctx.beginPath(); ctx.moveTo(xx, y); ctx.lineTo(xx, y + h); ctx.stroke();
  }
}

function series(ctx, x, y, w, h, t, data, color, t0) {
  const n = data.length;
  if (n < 2) return;
  let lo = Infinity, hi = -Infinity;
  for (let i = 0; i < n; i++) { if (data[i] < lo) lo = data[i]; if (data[i] > hi) hi = data[i]; }
  if (!isFinite(lo)) { lo = -1; hi = 1; }
  if (hi - lo < 1e-6) { lo -= 1; hi += 1; }
  const pad = (hi - lo) * 0.12;
  lo -= pad; hi += pad;
  ctx.strokeStyle = color;
  ctx.lineWidth = 1.2;
  ctx.lineJoin = 'round';
  ctx.beginPath();
  for (let i = 0; i < n; i++) {
    const px = x + w - ((t0 - t[i]) / WINDOW) * w;
    const py = y + h - ((data[i] - lo) / (hi - lo)) * h;
    i ? ctx.lineTo(px, py) : ctx.moveTo(px, py);
  }
  ctx.stroke();
}

function label(ctx, text, x, y, color = 'rgba(255,255,255,.38)', align = 'left') {
  ctx.fillStyle = color;
  ctx.font = `9px ${MONO}`;
  ctx.textAlign = align;
  ctx.fillText(text, x, y);
}

function drawFlat(canvas, title, chan, unit, names) {
  const { ctx, w, h } = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const px = 46, py = 20, pw = w - px - 12, ph = h - py - 22;
  grid(ctx, px, py, pw, ph);
  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;
  names.forEach((_, i) => series(ctx, px, py, pw, ph, H.t, H[chan][i], CURVES[i], t0));

  label(ctx, title, 12, 14, 'rgba(255,255,255,.58)');
  label(ctx, unit, 8, py + ph / 2, 'rgba(255,255,255,.38)');
  label(ctx, `-${WINDOW}s`, px, h - 6, 'rgba(255,255,255,.30)');
  label(ctx, '0', px + pw, h - 6, 'rgba(255,255,255,.30)', 'right');

  names.forEach((nm, i) => {
    const lx = w - 14 - (names.length - 1 - i) * 42;
    ctx.fillStyle = CURVES[i];
    ctx.fillRect(lx - 14, 8, 9, 2);
    label(ctx, nm, lx, 13, 'rgba(255,255,255,.58)');
  });
}

function drawRpy(canvas) {
  const { ctx, w, h } = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const names = ['roll', 'pitch', 'yaw'];
  const px = 46, pw = w - px - 12;
  const band = (h - 18) / 3;
  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;

  names.forEach((nm, i) => {
    const py = 14 + i * band;
    grid(ctx, px, py, pw, band - 8);
    series(ctx, px, py, pw, band - 8, H.t, H.rpy[i], CURVES[i], t0);
    label(ctx, nm, 12, py + 10, 'rgba(255,255,255,.58)');
  });
  label(ctx, '姿态 · Mahony', 12, 11, 'rgba(255,255,255,.58)');
  label(ctx, `-${WINDOW}s`, px, h - 4, 'rgba(255,255,255,.30)');
  label(ctx, '0', px + pw, h - 4, 'rgba(255,255,255,.30)', 'right');
}

let lastDraw = 0;
function loop(ts) {
  if (ts - lastDraw > 33) {
    lastDraw = ts;
    drawFlat($('#c-acc'), '加速度 (m/s²)', 'acc', 'm/s²', ['ax', 'ay', 'az']);
    drawFlat($('#c-gyro'), '角速度 (rad/s)', 'gyro', 'rad/s', ['gx', 'gy', 'gz']);
    drawRpy($('#c-rpy'));
    drawFlat($('#c-axis'), `选中轴 ${String(selIndex + 1).padStart(2, '0')}`,
             'axis', '° / °/s', ['位置', '速度']);
  }
  requestAnimationFrame(loop);
}

/* ───────────────────────── 选中轴 ───────────────────────── */

let selIndex = 0;

function buildAxisSelect() {
  const sel = $('#sel-axis');
  for (let i = 0; i < AX; i++) {
    const o = document.createElement('option');
    o.value = i;
    o.textContent = '轴 ' + String(i + 1).padStart(2, '0');
    sel.appendChild(o);
  }
  sel.onchange = () => {
    selIndex = Number(sel.value);
    H.axis[0].length = 0;
    H.axis[1].length = 0;
  };
}

/* ───────────────────────── SSE ───────────────────────── */

function connect() {
  const es = new EventSource('/api/stream');
  es.onmessage = (ev) => {
    const st = JSON.parse(ev.data);
    if (!st.online) {
      if (state) { state = null; setOffline(); }
      return;
    }
    st.rpy = mahony(st.acc, st.gyro, st.t);
    state = st;
    masterRunning = true;
    pushHist();
    render(st);
  };
  es.onerror = () => { es.close(); setTimeout(connect, 1000); };
}

function setOffline() {
  $('#pill').textContent = '主站：无数据';
  $('#pill').className = 'pill warn';
  $('#v-wkc').textContent = '-';
  $('#v-al').textContent = '-';
  $('#v-fps').textContent = '-';
  $('#v-gap').textContent = '-';
  $('#v-rtt').textContent = '-';
  $('#v-mcu').textContent = '-';
  $('#d-rtt').textContent = '';
  $('#d-mcu').textContent = '';
}

const AL = { 1: 'INIT', 2: 'PRE-OP', 3: 'BOOT', 4: 'SAFE-OP', 8: 'OP' };

function render(st) {
  const code = st.al & 0x0f;
  const al = AL[code] || (code ? '0x' + code.toString(16) : '—');
  const ok = st.al === 0x0008;

  $('#pill').textContent = '主站：' + al;
  $('#pill').className = ok ? 'pill ok' : 'pill warn';
  $('#alc').textContent = `ALC 0x${st.alc.toString(16).padStart(4, '0')}`;

  roll($('#v-wkc'), st.wkc, (v) => String(Math.round(v)));
  $('#v-al').textContent = al;
  $('#v-al').style.color = ok ? '#fff' : '#e0a35a';
  roll($('#v-fps'), st.fps, (v) => String(Math.round(v)));
  roll($('#v-gap'), st.gap, (v) => v.toFixed(1) + ' ms');
  roll($('#v-rtt'), st.rtt, (v) => Math.round(v) + 'us');
  roll($('#v-mcu'), st.mcu, (v) => Math.round(v) + 'us');
  $('#d-rtt').textContent = `${Math.round(st.rtt_min)} / ${Math.round(st.rtt_max)}`;
  $('#d-mcu').textContent = `${Math.round(st.mcu_min)} / ${Math.round(st.mcu_max)}`;

  for (let i = 0; i < AX; i++) {
    const a = st.axes[i];
    if (!a) continue;
    axisFb[i].textContent = a.pos.toFixed(2);
    const en = a.status & 1, flt = a.status & 2, vld = a.status & 0x20;
    axisSt[i].textContent = (en ? 'E' : '-') + (flt ? 'F' : '-') + (vld ? 'V' : '-');
    axisSt[i].className = 'st' + (flt ? ' err' : (en && vld ? ' on' : ''));
  }

  const a = st.axes[selIndex];
  if (a) {
    $('#fb').textContent =
      `轴${String(selIndex + 1).padStart(2, '0')}  id=${a.id}  ` +
      `pos=${a.pos.toFixed(2)}°  vel=${a.vel.toFixed(1)}°/s  ` +
      `status=0x${a.status.toString(16).padStart(4, '0')}`;
  }
}

/* ───────────────────────── 按钮 ───────────────────────── */

function wireButtons() {
  $('#btn-start').onclick = async () => {
    const res = await post('/api/master', { action: 'start', cycle });
    if (res && res.running) {
      masterRunning = true;
      $('#btn-start').disabled = true;
      $('#btn-stop').disabled = false;
      if (!res.online) notify('主站没进 OP：请先点「复位从站」');
    } else {
      notify('启动失败' + (res && res.error ? '：' + res.error : ''));
    }
  };
  $('#btn-stop').onclick = async () => {
    await post('/api/master', { action: 'stop' });
    masterRunning = false;
    $('#btn-start').disabled = false;
    $('#btn-stop').disabled = true;
  };
  $('#btn-reset').onclick = () => post('/api/master', { action: 'reset' });

  $('#btn-enable').onclick = () => setBit(1, true);
  $('#btn-disable').onclick = () => setBit(1, false);
  $('#btn-estop').onclick = () => setBit(2, true);
  $('#btn-clear').onclick = () => setBit(2, false);
  $('#btn-zero').onclick = () => {
    axisInputs.forEach((r) => r.forEach((el) => (el.value = 0)));
    pushCmd();
  };

  $('#btn-ledpick').onclick = () => $('#led').click();
  $('#led').oninput = (e) => {
    const h = e.target.value;
    led = [parseInt(h.slice(1, 3), 16), parseInt(h.slice(3, 5), 16), parseInt(h.slice(5, 7), 16)];
  };
  $('#btn-ledapply').onclick = () => { ledMode = 1; pushCmd(); };
  $('#btn-ledstatus').onclick = () => { ledMode = 0; pushCmd(); };
}

/* ───────────────────────── 启动 ───────────────────────── */

window.addEventListener('resize', () => { segSelect(segIndex, false); });

buildAxisRows();
buildAxisSelect();
wireButtons();
requestAnimationFrame(() => {
  segSelect(0, false);
  connect();
  requestAnimationFrame(loop);
});
