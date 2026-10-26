import {useEffect, useRef, useState} from 'react';
import {
  Button, Segmented, NumberFlow, Stat, Card, CardHeader, StatusDot,
  Toaster, toast,
} from 'noir-ui';

const AX = 17;
const WINDOW = 30;
const MAXPTS = 900;
const CURVES = ['#ffffff', '#6ec8ff', '#ffb86b'];
const MONO = '"DM Mono", Consolas, monospace';
const AL = {1: 'INIT', 2: 'PRE-OP', 3: 'BOOT', 4: 'SAFE-OP', 8: 'OP'};
const CAPTURE = typeof location !== 'undefined' && location.hash === '#capture';

const H = {
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
  for (let i = 0; i < 3; i++) {
    H.acc[i].push(s.acc[i]);
    H.gyro[i].push(s.gyro[i]);
    H.rpy[i].push(s.rpy[i]);
  }
  H.axis[0].push(s.axes[selIndex].pos);
  H.axis[1].push(s.axes[selIndex].vel);
  if (H.t.length > MAXPTS) {
    H.t.shift();
    for (const k of ['acc', 'gyro', 'rpy', 'axis']) H[k].forEach((a) => a.shift());
  }
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

function drawSeries(ctx, x, y, w, h, t, data, color, t0) {
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

const label = (ctx, text, x, y, color = 'rgba(255,255,255,.38)', align = 'left') => {
  ctx.fillStyle = color;
  ctx.font = `9px ${MONO}`;
  ctx.textAlign = align;
  ctx.fillText(text, x, y);
};

function renderFlat(canvas, title, chan, names) {
  const {ctx, w, h} = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const px = 46, py = 22, pw = w - px - 12, ph = h - py - 24;
  grid(ctx, px, py, pw, ph);
  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;
  names.forEach((_, i) => drawSeries(ctx, px, py, pw, ph, H.t, H[chan][i], CURVES[i], t0));
  label(ctx, title, 12, 15, 'rgba(255,255,255,.58)');
  label(ctx, `-${WINDOW}s`, px, h - 8, 'rgba(255,255,255,.30)');
  label(ctx, '0', px + pw, h - 8, 'rgba(255,255,255,.30)', 'right');
  names.forEach((nm, i) => {
    const lx = w - 14 - (names.length - 1 - i) * 42;
    ctx.fillStyle = CURVES[i];
    ctx.fillRect(lx - 14, 9, 9, 2);
    label(ctx, nm, lx, 14, 'rgba(255,255,255,.58)');
  });
}

function renderRpy(canvas) {
  const {ctx, w, h} = fit(canvas);
  ctx.clearRect(0, 0, w, h);
  const names = ['roll', 'pitch', 'yaw'];
  const px = 46, pw = w - px - 12;
  const band = (h - 24) / 3;
  const t0 = H.t.length ? H.t[H.t.length - 1] : 0;
  names.forEach((nm, i) => {
    const py = 18 + i * band;
    grid(ctx, px, py, pw, band - 10);
    drawSeries(ctx, px, py, pw, band - 10, H.t, H.rpy[i], CURVES[i], t0);
    label(ctx, nm, 12, py + 10, 'rgba(255,255,255,.58)');
  });
  label(ctx, '姿态 · Mahony', 12, 14, 'rgba(255,255,255,.58)');
  label(ctx, `-${WINDOW}s`, px, h - 6, 'rgba(255,255,255,.30)');
  label(ctx, '0', px + pw, h - 6, 'rgba(255,255,255,.30)', 'right');
}

function Plot({title, kind, names}) {
  const ref = useRef(null);
  useEffect(() => {
    let raf, last = 0;
    const tick = (ts) => {
      if (ts - last > 33) {
        last = ts;
        if (ref.current) {
          if (kind === 'rpy') renderRpy(ref.current);
          else renderFlat(ref.current, title, kind, names);
        }
      }
      raf = requestAnimationFrame(tick);
    };
    raf = requestAnimationFrame(tick);
    return () => cancelAnimationFrame(raf);
  }, [kind, title, names]);
  return (
    <Card className="plot-card">
      <canvas ref={ref} />
    </Card>
  );
}

/* ───────── 轴表 ───────── */
function AxisTable({onChange, axisRefs, fbRef, stRef}) {
  const rows = Array.from({length: AX}, (_, i) => i);
  return (
    <div className="axis">
      <div className="axis-head">
        <span>轴</span><span>位置 °</span><span>速度 °/s</span><span>力矩 A</span>
        <span>Kp</span><span>Kd</span><span>反馈 °</span><span>状态</span>
      </div>
      <div className="axis-body">
        {rows.map((i) => (
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
}

/* ───────── App ───────── */
export default function App() {
  const [ui, setUi] = useState(null);
  const [cycle, setCycle] = useState(500000);
  const [running, setRunning] = useState(false);
  const [ctrl, setCtrl] = useState(0);
  const [led, setLed] = useState('#ffffff');
  const [ledMode, setLedMode] = useState(0);
  const [sel, setSel] = useState(0);
  const [fbLine, setFbLine] = useState('等待主站数据…');

  const axisRefs = useRef([]);
  const fbRef = useRef([]);
  const stRef = useRef([]);
  const stateRef = useRef(null);
  const selRef = useRef(0);
  const ctrlRef = useRef(0);
  const ledRef = useRef([255, 255, 255]);
  const ledModeRef = useRef(0);
  const cmdTimer = useRef(0);

  useEffect(() => { ctrlRef.current = ctrl; }, [ctrl]);
  useEffect(() => { ledModeRef.current = ledMode; }, [ledMode]);
  useEffect(() => {
    const h = led.replace('#', '');
    ledRef.current = [parseInt(h.slice(0, 2), 16), parseInt(h.slice(2, 4), 16), parseInt(h.slice(4, 6), 16)];
  }, [led]);

  const post = (path, body) =>
    fetch(path, {method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify(body)})
      .then((r) => r.json()).catch(() => null);

  const sendCmd = () => {
    const axes = Array.from({length: AX}, (_, i) =>
      (axisRefs.current[i] || [0, 0, 0, 0, 0]).map((el) => Number(el?.value) || 0));
    post('/api/cmd', {ctrl: ctrlRef.current, led: ledRef.current, led_mode: ledModeRef.current, axes});
  };

  const scheduleCmd = () => {
    clearTimeout(cmdTimer.current);
    cmdTimer.current = setTimeout(sendCmd, 120);
  };

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

  useEffect(() => {
    let lastUi = 0;
    const es = new EventSource('/api/stream');
    es.onmessage = (ev) => {
      const s = JSON.parse(ev.data);
      if (!s.online) {
        setUi(null);
        return;
      }
      s.rpy = mahony(s.acc, s.gyro, s.t);
      stateRef.current = s;
      pushHist(s);
      const now = performance.now();
      s.axes.forEach((a, i) => {
        const f = fbRef.current[i];
        if (f) f.textContent = a.pos.toFixed(2);
        const t = stRef.current[i];
        if (t) {
          const en = a.status & 1, flt = a.status & 2, vld = a.status & 0x20;
          t.textContent = (en ? 'E' : '-') + (flt ? 'F' : '-') + (vld ? 'V' : '-');
          t.className = 'st' + (flt ? ' err' : en && vld ? ' on' : '');
        }
      });
      if (now - lastUi > 100) {
        lastUi = now;
        setUi(s);
        setRunning(true);
        const si = selRef.current;
        const a = s.axes[si];
        if (a) {
          setFbLine(
            `轴${String(si + 1).padStart(2, '0')}  id=${a.id}  ` +
            `pos=${a.pos.toFixed(2)}°  vel=${a.vel.toFixed(1)}°/s  ` +
            `status=0x${a.status.toString(16).padStart(4, '0')}`);
        }
      }
    };
    return () => es.close();
  }, []);

  const start = async () => {
    const r = await post('/api/master', {action: 'start', cycle});
    if (r?.running) { setRunning(true); toast.success('主站已启动'); }
    else toast.error('启动失败');
  };
  const stop = async () => {
    await post('/api/master', {action: 'stop'});
    setRunning(false);
    toast('主站已停止');
  };
  const reset = async () => {
    const r = await post('/api/master', {action: 'reset'});
    if (r?.reset) toast.success('从站已复位');
  };

  const alCode = ui ? ui.al & 0x0f : 0;
  const alText = ui ? (AL[alCode] || (alCode ? '0x' + alCode.toString(16) : '—')) : '—';
  const ok = ui && ui.al === 0x0008;

  return (
    <div className="app" style={CAPTURE ? {pointerEvents: 'none'} : undefined}>
      <header className="bar">
        <Button variant="primary" onClick={start} disabled={running}>启动主站</Button>
        <Button onClick={stop} disabled={!running}>停止主站</Button>
        <Button onClick={reset}>复位从站</Button>

        <span className="mono dim" style={{marginLeft: 8}}>周期</span>
        <Segmented
          value={cycle}
          onChange={setCycle}
          options={[
            {value: 500000, label: '2 kHz'},
            {value: 1000000, label: '1 kHz'},
            {value: 333333, label: '3 kHz'},
          ]}
        />

        <span className={'pill' + (ok ? ' ok' : ui ? ' warn' : '')}>
          <StatusDot status={ok ? 'live' : 'warn'} />
          {ui ? '主站：' + alText : '主站：未运行'}
        </span>
        <span className="mono dim">
          {ui ? `ALC 0x${ui.alc.toString(16).padStart(4, '0')}` : 'ALC -'}
        </span>

        <div className="stats">
          <Stat label="WKC" value={ui?.wkc ?? 0} format={(v) => String(Math.round(v))} />
          <Stat label="帧率" value={ui?.fps ?? 0} format={(v) => String(Math.round(v))} />
          <Stat label="最大间隔" value={ui?.gap ?? 0} format={(v) => v.toFixed(1) + ' ms'} />
          <Stat label="RTT 含调度" value={ui?.rtt ?? 0} format={(v) => Math.round(v) + 'us'}
                sub={ui ? `${Math.round(ui.rtt_min)} / ${Math.round(ui.rtt_max)}` : ''} />
          <Stat label="MCU 处理" value={ui?.mcu ?? 0} format={(v) => Math.round(v) + 'us'}
                sub={ui ? `${Math.round(ui.mcu_min)} / ${Math.round(ui.mcu_max)}` : ''} />
        </div>
      </header>

      <main>
        <section className="col">
          <Card className="panel">
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

          <Card className="panel grow">
            <CardHeader title="02 轴命令" />
            <AxisTable onChange={scheduleCmd} axisRefs={axisRefs}
                       fbRef={fbRef} stRef={stRef} />
          </Card>

          <Card className="panel">
            <CardHeader title="03 反馈" />
            <div className="mono dim">{fbLine}</div>
          </Card>
        </section>

        <section className="plots">
          <Plot title="加速度 (m/s²)" kind="acc" names={['ax', 'ay', 'az']} />
          <Plot title="角速度 (rad/s)" kind="gyro" names={['gx', 'gy', 'gz']} />
          <Plot title="姿态 · Mahony" kind="rpy" names={['roll', 'pitch', 'yaw']} />
          <div className="plot-wrap">
            <Plot title={`选中轴 ${String(sel + 1).padStart(2, '0')}`} kind="axis" names={['位置', '速度']} />
            <select
              className="axis-pick"
              value={sel}
              onChange={(e) => {
                selIndex = Number(e.target.value);
                selRef.current = selIndex;
                setSel(selIndex);
                H.axis[0].length = 0;
                H.axis[1].length = 0;
              }}
            >
              {Array.from({length: AX}, (_, i) => (
                <option key={i} value={i}>轴 {String(i + 1).padStart(2, '0')}</option>
              ))}
            </select>
          </div>
        </section>
      </main>
      <Toaster />
    </div>
  );
}
