"""EtherCAT 17 轴实时监视 / 控制界面。

界面只做显示和人机交互；实时发帧仍由 ecat_live.exe --headless 负责。
两者通过命名共享内存交换数据：
    ecat_ui_state  主站 -> UI
    ecat_ui_cmd    UI -> 主站

启动：  python ecat_ui.py
"""

from __future__ import annotations

import mmap
import os
import struct
import subprocess
import sys
import time
import ctypes
import numpy as np

from PySide6.QtCore import QEasingCurve, QRectF, Qt, QTimer, QVariantAnimation, Signal
from PySide6.QtGui import QBrush, QColor, QFont, QPainter, QPen
from PySide6.QtWidgets import (
    QAbstractItemView,
    QApplication,
    QColorDialog,
    QComboBox,
    QDoubleSpinBox,
    QFrame,
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QHeaderView,
    QLabel,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QSplitter,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

import pyqtgraph as pg

# ---------------------------------------------------------------- 共享内存

AXES = 17
STATE_MAGIC = 0x32545345
CMD_MAGIC = 0x32434D45

# seq magic size frame_cnt t_us fps gap acc[3] gyro[3] raw_acc[3] raw_gyro[3]
# wkc alstat alcode temp ax_count pad0
STATE_FMT = "<IIIIQff3f3f3h3hHHHHHH" + "ffHHihH" * AXES + "ffffff"
CMD_FMT = "<III6B2B" + "fffff" * AXES

STATE_SIZE = struct.calcsize(STATE_FMT)
CMD_SIZE = struct.calcsize(CMD_FMT)
STATE_NAME = "ecat_ui_state"
CMD_NAME = "ecat_ui_cmd"

def _find_root(start: str) -> str:
    """源码运行 / PyInstaller 打包后都能找到 HostTools 根目录。"""
    d = os.path.abspath(start)
    for _ in range(5):
        if os.path.isdir(os.path.join(d, "bin")) and os.path.isdir(os.path.join(d, "webui")):
            return d
        parent = os.path.dirname(d)
        if parent == d:
            break
        d = parent
    return os.path.abspath(start)


if getattr(sys, "frozen", False):
    HERE = os.path.dirname(os.path.abspath(sys.executable))
else:
    HERE = os.path.dirname(os.path.abspath(__file__))

ROOT = _find_root(HERE)
BIN = os.path.join(ROOT, "bin")
SOEM_BIN = os.path.join(BIN, "ecat_live.exe")
JLINK_BIN = r"D:\clover\Embedded\SEGGER\JLink_V810b\JLink.exe"
JLINK_SCRIPT = os.path.join(ROOT, "jlink", "reset_only.jlink")
DEFAULT_IFACE = os.environ.get(
    "ECAT_IFACE", r"\Device\NPF_{9269FBF0-8A17-4A3B-A238-90DF8FACBB09}")

AL_STATES = {1: "INIT", 2: "PRE-OP", 3: "BOOT", 4: "SAFE-OP", 8: "OP"}


def set_process_priority(pid: int, priority_class: int) -> bool:
    """给子进程设优先级。主站设 HIGH，避免被界面刷新抢走 CPU 导致 DC 同步错误。"""
    PROCESS_SET_INFORMATION = 0x0200
    try:
        h = ctypes.windll.kernel32.OpenProcess(PROCESS_SET_INFORMATION, False, pid)
        if not h:
            return False
        ok = bool(ctypes.windll.kernel32.SetPriorityClass(h, priority_class))
        ctypes.windll.kernel32.CloseHandle(h)
        return ok
    except Exception:
        return False


HIGH_PRIORITY_CLASS = 0x00000080

# ---------------------------------------------------------------- NOIR 色板
# 只有黑白 + 透明度阶梯；红色仅用于急停/故障这类安全语义。
C_BG        = "#000000"
C_RAISED    = "#070707"
C_FG        = "#ffffff"
C_FG2       = QColor(255, 255, 255, 148)   # .58
C_FG3       = QColor(255, 255, 255, 97)    # .38
C_FG4       = QColor(255, 255, 255, 51)    # .20
C_LINE      = QColor(255, 255, 255, 41)    # .16
C_LINE_STR  = QColor(255, 255, 255, 71)    # .28
C_FILL      = QColor(255, 255, 255, 20)    # .08
C_DANGER    = "#ff6b6b"
C_WARN      = "#e0a35a"

# 界面保持单色，只给数据曲线留三个低饱和色，保证三条线能区分
CURVE_1 = (255, 255, 255)        # 白
CURVE_2 = (110, 200, 255)        # 青
CURVE_3 = (255, 184, 107)        # 琥珀

MONO = "Consolas"


class NoirSegmented(QWidget):
    """NOIR 分段控件：临界阻尼弹簧 + 速度拖影，墨块经过处文字逐格反色。"""

    changed = Signal(object)

    K = 520.0
    ZETA = 0.95
    DT = 1.0 / 60.0

    def __init__(self, items, parent=None):
        super().__init__(parent)
        self._items = list(items)          # [(label, value), ...]
        self._index = 0
        self._x = 2.0
        self._target = 2.0
        self._v = 0.0
        self._trail = 0.0
        self._timer = QTimer(self)
        self._timer.setInterval(16)
        self._timer.timeout.connect(self._step)
        self.setFixedHeight(32)
        self.setMinimumWidth(58 * len(self._items) + 8)
        self.setCursor(Qt.PointingHandCursor)

    def _seg_w(self) -> float:
        return (self.width() - 4) / max(1, len(self._items))

    def _target_x(self, i: int) -> float:
        return 2 + i * self._seg_w()

    def _step(self) -> None:
        c = 2.0 * (self.K ** 0.5) * self.ZETA
        a = self.K * (self._target - self._x) - c * self._v
        self._v += a * self.DT
        self._x += self._v * self.DT
        speed = abs(self._v)
        # NOIR 的虚拟快门：拖影 = 速度 × 48ms，且不超过剩余距离太多
        self._trail = min(speed * 0.048, abs(self._target - self._x) + 10.0)
        if abs(self._target - self._x) < 0.5 and speed < 8.0:
            self._x = self._target
            self._v = 0.0
            self._trail = 0.0
            self._timer.stop()
        self.update()

    def value(self):
        return self._items[self._index][1]

    def currentText(self) -> str:
        return self._items[self._index][0]

    def currentIndex(self) -> int:
        return self._index

    def setCurrentIndex(self, i: int, animate: bool = True) -> None:
        i = max(0, min(len(self._items) - 1, int(i)))
        if i == self._index:
            return
        self._index = i
        self._target = self._target_x(i)
        if animate and self.isVisible():
            if not self._timer.isActive():
                self._timer.start()
        else:
            self._x = self._target
            self._v = 0.0
            self._trail = 0.0
            self.update()
        self.changed.emit(self.value())

    def setValue(self, value) -> None:
        for i, (_, v) in enumerate(self._items):
            if v == value:
                self.setCurrentIndex(i, animate=False)
                return

    def resizeEvent(self, e):
        super().resizeEvent(e)
        self._target = self._target_x(self._index)
        self._x = self._target
        self._v = 0.0
        self._trail = 0.0

    def mousePressEvent(self, e):
        if not self.isEnabled():
            return
        i = int(max(0, min(len(self._items) - 1, (e.position().x() - 2) // self._seg_w())))
        self.setCurrentIndex(i)

    def paintEvent(self, _e):
        p = QPainter(self)
        p.setRenderHint(QPainter.Antialiasing, True)
        r = QRectF(self.rect()).adjusted(0.5, 0.5, -0.5, -0.5)

        p.setPen(QPen(C_LINE, 1))
        p.setBrush(QBrush(QColor(255, 255, 255, 10)))
        p.drawRoundedRect(r, 7, 7)

        seg_w = self._seg_w()
        h = self.height() - 4

        if self.isEnabled():
            stretch = 1.0 + min(0.42, self._trail / max(1.0, seg_w) * 0.55)
            w = seg_w * stretch
            if self._v >= 0:
                x0 = self._x - (w - seg_w)
            else:
                x0 = self._x

            # 两片拖影：透明度随速度衰减，读起来像 60fps 的快门残影
            if self._trail > 1.5:
                for k, alpha in ((0.012, 30), (0.026, 14)):
                    gx = x0 - self._v * k
                    p.setPen(Qt.NoPen)
                    p.setBrush(QBrush(QColor(255, 255, 255, alpha)))
                    p.drawRoundedRect(QRectF(gx, 2, w, h), 5.5, 5.5)

            p.setPen(Qt.NoPen)
            p.setBrush(QBrush(QColor(255, 255, 255)))
            thumb = QRectF(x0, 2, w, h)
            p.drawRoundedRect(thumb, 5.5, 5.5)
        else:
            thumb = QRectF(-100, 0, 0, 0)

        f = QFont(MONO, 9)
        f.setWeight(QFont.DemiBold)
        p.setFont(f)
        for i, (label, _) in enumerate(self._items):
            cell = QRectF(2 + i * seg_w, 0, seg_w, self.height())
            if not self.isEnabled():
                p.setPen(C_FG4)
            else:
                # 墨块覆盖超过一半就把这格文字反色
                inter = min(cell.right(), thumb.right()) - max(cell.left(), thumb.left())
                covered = inter > seg_w * 0.45
                p.setPen(QColor(0, 0, 0) if covered else C_FG2)
            p.drawText(cell, Qt.AlignCenter, label)
        p.end()


class RollingNumber(QLabel):
    """数值变化时按 60fps 指数逼近，像里程表一样滚过去，而不是直接跳。"""

    def __init__(self, fmt: str = "{:.0f}", parent=None):
        super().__init__("-", parent)
        self._fmt = fmt
        self._cur = None
        self._target = 0.0
        self._timer = QTimer(self)
        self._timer.setInterval(16)
        self._timer.timeout.connect(self._step)

    def setValue(self, v) -> None:
        v = float(v)
        if self._cur is None:
            self._cur = v
            self._target = v
            self.setText(self._fmt.format(v))
            return
        self._target = v
        if not self._timer.isActive():
            self._timer.start()

    def clear(self) -> None:
        self._timer.stop()
        self._cur = None
        self.setText("-")

    def _step(self) -> None:
        d = self._target - self._cur
        if abs(d) < 0.05:
            self._cur = self._target
            self._timer.stop()
        else:
            self._cur += d * 0.24
        self.setText(self._fmt.format(self._cur))


class SharedMem:
    """命名共享内存。主站没启动时读到的都是 0。"""

    def __init__(self) -> None:
        self.state_mm = None
        self.cmd_mm = None
        self.cmd_seq = 0
        try:
            # 必须用 ACCESS_WRITE 创建/打开：ACCESS_READ 会建成只读段，
            # C 侧再以 PAGE_READWRITE 打开会失败，主站就无法发布状态。
            self.state_mm = mmap.mmap(-1, STATE_SIZE, tagname=STATE_NAME,
                                      access=mmap.ACCESS_WRITE)
        except OSError:
            self.state_mm = None
        try:
            self.cmd_mm = mmap.mmap(-1, CMD_SIZE, tagname=CMD_NAME,
                                    access=mmap.ACCESS_WRITE)
        except OSError:
            self.cmd_mm = None

    def read_state(self):
        if self.state_mm is None:
            return None
        try:
            raw = self.state_mm[:STATE_SIZE]
        except (ValueError, OSError):
            return None
        seq1 = struct.unpack_from("<I", raw, 0)[0]
        if seq1 & 1:
            return None
        vals = struct.unpack(STATE_FMT, raw)
        if struct.unpack_from("<I", raw, 0)[0] != seq1:
            return None
        if vals[1] != STATE_MAGIC or vals[2] != STATE_SIZE:
            return None
        out = {
            "frame": vals[3],
            "t_us": vals[4],
            "fps": vals[5],
            "gap_ms": vals[6],
            "acc": np.array(vals[7:10], dtype=np.float64),
            "gyro": np.array(vals[10:13], dtype=np.float64),
            "wkc": vals[19],
            "alstat": vals[20],
            "alcode": vals[21],
            "temp": vals[22],
            "axis": [],
        }
        base = 25
        for i in range(AXES):
            o = base + i * 7
            out["axis"].append({
                "pos": vals[o + 0],
                "vel": vals[o + 1],
                "status": vals[o + 2],
                "id": vals[o + 3],
                "pos_raw": vals[o + 4],
                "vel_raw": vals[o + 5],
            })
        tail = 25 + AXES * 7
        out["rtt_avg"] = vals[tail + 0]
        out["rtt_min"] = vals[tail + 1]
        out["rtt_max"] = vals[tail + 2]
        out["mcu_avg"] = vals[tail + 3]
        out["mcu_min"] = vals[tail + 4]
        out["mcu_max"] = vals[tail + 5]
        return out

    def write_cmd(self, ctrl: int, led, led_mode: int, axes, stop: int = 0) -> None:
        if self.cmd_mm is None:
            return
        self.cmd_seq = (self.cmd_seq + 1) & 0x7FFFFFFF
        head = struct.pack("<III6B2B", self.cmd_seq, CMD_MAGIC, CMD_SIZE,
                           ctrl & 0xFF, led_mode & 0xFF,
                           led[0] & 0xFF, led[1] & 0xFF, led[2] & 0xFF,
                           stop & 0xFF, 0, 0)
        body = b"".join(struct.pack("<fffff", *a) for a in axes)
        try:
            self.cmd_mm[:len(head)] = head
            self.cmd_mm[len(head):len(head) + len(body)] = body
        except (ValueError, OSError):
            pass


# ---------------------------------------------------------------- Mahony

def quat_mul(a, b):
    w1, x1, y1, z1 = a
    w2, x2, y2, z2 = b
    return np.array([
        w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2,
        w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2,
        w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2,
        w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2,
    ])


def quat_rotate(q, v):
    qv = np.array([0.0, v[0], v[1], v[2]])
    qc = np.array([q[0], -q[1], -q[2], -q[3]])
    return quat_mul(quat_mul(q, qv), qc)[1:]


class Mahony:
    def __init__(self, kp: float = 2.0, ki: float = 0.05) -> None:
        self.kp = kp
        self.ki = ki
        self.q = np.array([1.0, 0.0, 0.0, 0.0])
        self.e_int = np.zeros(3)
        self.t_prev = None
        self.aligned = False

    def reset(self) -> None:
        self.q = np.array([1.0, 0.0, 0.0, 0.0])
        self.e_int = np.zeros(3)
        self.t_prev = None
        self.aligned = False

    def update(self, acc, gyro):
        now = time.perf_counter()
        dt = 0.02 if self.t_prev is None else now - self.t_prev
        self.t_prev = now
        dt = min(max(dt, 1e-4), 0.1)

        n = np.linalg.norm(acc)
        if n < 1e-3:
            return self.q
        a = acc / n

        if not self.aligned:
            roll = np.arctan2(a[1], a[2])
            pitch = np.arctan2(-a[0], np.hypot(a[1], a[2]))
            cp, sp = np.cos(pitch / 2), np.sin(pitch / 2)
            cr, sr = np.cos(roll / 2), np.sin(roll / 2)
            self.q = np.array([cr * cp, sr * cp, cr * sp, -sr * sp])
            self.aligned = True
            return self.q

        qc = np.array([self.q[0], -self.q[1], -self.q[2], -self.q[3]])
        v = quat_rotate(qc, np.array([0.0, 0.0, 1.0]))
        e = np.cross(a, v)
        self.e_int += self.ki * e * dt
        w = gyro + self.kp * e + self.e_int

        qdot = 0.5 * quat_mul(self.q, np.array([0.0, w[0], w[1], w[2]]))
        self.q = self.q + qdot * dt
        self.q /= np.linalg.norm(self.q)
        return self.q

    def euler_deg(self):
        w, x, y, z = self.q
        roll = np.arctan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y))
        pitch = np.arcsin(np.clip(2 * (w * y - z * x), -1.0, 1.0))
        yaw = np.arctan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z))
        return np.degrees([roll, pitch, yaw])


# ---------------------------------------------------------------- 曲线控件

class RingBuf:
    """预分配环形缓冲：push 只写一行，refresh 用 numpy 视图，避免逐点 Python 循环。"""

    def __init__(self, cap: int, nch: int) -> None:
        self.cap = cap
        self.k = 0
        self.n = 0
        self.t = np.zeros(cap, dtype=np.float64)
        self.v = np.zeros((cap, nch), dtype=np.float64)

    def push(self, values, t: float) -> None:
        self.v[self.k] = values
        self.t[self.k] = t
        self.k = (self.k + 1) % self.cap
        if self.n < self.cap:
            self.n += 1

    def view(self):
        if self.n == 0:
            return None, None
        if self.n < self.cap:
            return self.t[:self.n], self.v[:self.n]
        return (np.concatenate((self.t[self.k:], self.t[:self.k])),
                np.concatenate((self.v[self.k:], self.v[:self.k])))

    def __len__(self) -> int:
        return self.n


WINDOW_S = 30.0


class HistoryPlot(pg.PlotWidget):
    def __init__(self, title, ylabel, colors, names, points: int = 1500):
        super().__init__()
        self.setBackground(C_BG)
        self.showGrid(x=True, y=True, alpha=0.12)
        self.setTitle(title, color="#9a9a9a", size="9pt")
        self.setLabel("left", ylabel)
        self.getAxis("left").setTextPen(C_FG3)
        self.getAxis("bottom").setTextPen(C_FG3)
        self.getAxis("left").setPen(C_LINE)
        self.getAxis("bottom").setPen(C_LINE)
        self.getAxis("left").setWidth(52)
        self.showAxis("top", False)
        self.showAxis("right", False)
        lg = self.addLegend(offset=(-10, 8), labelTextColor=C_FG2)
        lg.setBrush(pg.mkBrush(0, 0, 0, 0))
        lg.setPen(pg.mkPen(None))
        self.curves = [self.plot([], [], pen=pg.mkPen(c, width=1.6), name=n)
                       for c, n in zip(colors, names)]
        self.ring = RingBuf(points, len(names))
        self.hist = [self.ring.v[:, i] for i in range(len(names))]
        self.setClipToView(True)
        self.setDownsampling(auto=True, mode="peak")
        # 固定 X 窗口：每帧自动量程会强制整幅场景重绘，长时间运行会越来越卡
        self.enableAutoRange(axis="x", enable=False)
        self.setXRange(-WINDOW_S, 0.0, padding=0.0)
        self.setMouseEnabled(x=False, y=True)

    def push(self, values, t=None):
        self.ring.push(values, float(t) if t is not None else float(self.ring.n))

    def refresh(self):
        t, v = self.ring.view()
        if t is None:
            return
        lo, hi = self.viewRange()[0]
        if abs(lo + WINDOW_S) > 0.5 or abs(hi) > 0.5:
            self.setXRange(-WINDOW_S, 0.0, padding=0.0)
        x = t - t[-1]
        for i, c in enumerate(self.curves):
            c.setData(x, v[:, i], skipFiniteCheck=True)


class RpyPlots(QWidget):
    """roll / pitch / yaw 三个独立子图，各自独立 Y 轴。"""

    NAMES = [("roll", "#ffffff"), ("pitch", "#6ec8ff"), ("yaw", "#ffb86b")]

    def __init__(self, points: int = 1500):
        super().__init__()
        outer = QVBoxLayout(self)
        outer.setContentsMargins(0, 0, 0, 0)
        outer.setSpacing(0)

        head = QLabel("姿态 (Mahony) — 三轴分开显示")
        head.setStyleSheet(
            f"color:rgba(255,255,255,97); padding:3px 8px;"
            f"font-family:'{MONO}'; font-size:8pt;")
        outer.addWidget(head)

        glw = pg.GraphicsLayoutWidget()
        glw.setBackground(C_BG)
        outer.addWidget(glw, 1)

        self.plots = []
        self.curves = []
        self.ring = RingBuf(points, len(self.NAMES))
        self.hist = [self.ring.v[:, i] for i in range(len(self.NAMES))]

        for i, (name, color) in enumerate(self.NAMES):
            p = glw.addPlot(row=i, col=0)
            p.showGrid(x=True, y=True, alpha=0.12)
            p.setLabel("left", "°")
            p.getAxis("left").setTextPen(C_FG3)
            p.getAxis("bottom").setTextPen(C_FG3)
            p.getAxis("left").setPen(C_LINE)
            p.getAxis("bottom").setPen(C_LINE)
            p.getAxis("left").setWidth(46)
            p.showAxis("top", False)
            p.showAxis("right", False)
            p.setTitle(f"<span style='color:{color}'>{name}</span>",
                       size="8pt")
            p.setClipToView(True)
            p.setDownsampling(auto=True, mode="peak")
            p.enableAutoRange(axis="x", enable=False)
            p.setXRange(-WINDOW_S, 0.0, padding=0.0)
            p.setMouseEnabled(x=False, y=True)
            p.setContentsMargins(2, 2, 4, 2)
            if i < len(self.NAMES) - 1:
                p.getAxis("bottom").setStyle(showValues=False)
            else:
                p.setLabel("bottom", "t (s)")
            self.plots.append(p)
            self.curves.append(p.plot([], [], pen=pg.mkPen(color, width=1.5)))

    def push(self, values, t=None):
        self.ring.push(values, float(t) if t is not None else float(self.ring.n))

    def refresh(self):
        t, v = self.ring.view()
        if t is None:
            return
        lo, hi = self.plots[-1].viewRange()[0]
        if abs(lo + WINDOW_S) > 0.5 or abs(hi) > 0.5:
            for p in self.plots:
                p.setXRange(-WINDOW_S, 0.0, padding=0.0)
        x = t - t[-1]
        for i, c in enumerate(self.curves):
            c.setData(x, v[:, i], skipFiniteCheck=True)


# ---------------------------------------------------------------- 主窗口

class MainWindow(QMainWindow):
    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle("EtherCAT 17 轴实时控制台")
        self.resize(1560, 980)

        self.shm = SharedMem()
        self.master = None
        self.master_log = None
        self.mahony = Mahony()
        self.last_frame = -1
        self.last_state_t = 0.0
        self.last_fresh_t = 0.0
        self.cmd_ctrl = 0
        self.led = (0, 0, 0)
        self.led_mode = 0
        self.dirty = True
        self.poll_div = 0

        self._build_ui()
        self._build_timers()
        self._refresh_master_ui()

    def _build_ui(self) -> None:
        root = QWidget()
        self.setCentralWidget(root)
        outer = QVBoxLayout(root)
        outer.setContentsMargins(10, 8, 10, 8)
        outer.setSpacing(8)
        outer.addWidget(self._build_topbar())

        split = QSplitter(Qt.Horizontal)
        split.addWidget(self._build_left_panel())
        split.addWidget(self._build_plots())
        split.setStretchFactor(0, 0)
        split.setStretchFactor(1, 1)
        split.setSizes([700, 860])
        outer.addWidget(split, 1)

        self.statusBar().showMessage("就绪")

    def _build_topbar(self) -> QWidget:
        box = QFrame()
        box.setObjectName("topbar")
        box.setFrameShape(QFrame.StyledPanel)
        lay = QHBoxLayout(box)
        lay.setContentsMargins(10, 8, 10, 8)
        lay.setSpacing(8)

        self.btn_start = QPushButton("启动主站")
        self.btn_start.setObjectName("primary")
        self.btn_start.setMinimumWidth(96)
        self.btn_start.clicked.connect(self.start_master)
        self.btn_stop = QPushButton("停止主站")
        self.btn_stop.clicked.connect(self.stop_master)
        self.btn_reset = QPushButton("复位从站")
        self.btn_reset.clicked.connect(self.reset_slave)

        self.cmb_cycle = NoirSegmented([
            ("2 kHz", 500000),
            ("1 kHz", 1000000),
            ("3 kHz", 333333),
        ])
        self.cmb_cycle.changed.connect(self.on_cycle_changed)

        self.lbl_state = QLabel("主站：未运行")
        self._set_pill("主站：未运行", "rgba(255,255,255,148)")

        self.card_wkc, self.lbl_wkc, _ = self._stat_card("WKC")
        self.card_al, self.lbl_al, _ = self._stat_card("AL 状态", numeric=False)
        self.card_fps, self.lbl_fps, _ = self._stat_card("帧率")
        self.card_gap, self.lbl_gap, _ = self._stat_card("最大间隔", "{:.1f} ms")
        self.card_rtt, self.lbl_rtt, self.det_rtt = self._stat_card("RTT 含调度", "{:.0f}us")
        self.card_mcu, self.lbl_mcu, self.det_mcu = self._stat_card("MCU 处理", "{:.0f}us")
        self.lbl_alc = QLabel("ALC -")
        self.lbl_alc.setStyleSheet(
            f"color:rgba(255,255,255,97); font-family:'{MONO}'; font-size:8pt;")

        lay.addWidget(self.btn_start)
        lay.addWidget(self.btn_stop)
        lay.addWidget(self.btn_reset)
        lay.addSpacing(6)
        lbl_cycle = QLabel("周期")
        lbl_cycle.setStyleSheet(
            f"color:rgba(255,255,255,97); font-family:'{MONO}'; font-size:8pt;")
        lay.addWidget(lbl_cycle)
        lay.addWidget(self.cmb_cycle)
        lay.addSpacing(14)
        lay.addWidget(self.lbl_state)
        lay.addWidget(self.lbl_alc)
        lay.addSpacing(8)
        lay.addWidget(self.card_wkc)
        lay.addWidget(self.card_al)
        lay.addWidget(self.card_fps)
        lay.addWidget(self.card_gap)
        lay.addWidget(self.card_rtt)
        lay.addWidget(self.card_mcu)
        lay.addStretch(1)
        return box

    def _stat_card(self, title: str, fmt: str = "{:.0f}", numeric: bool = True):
        frame = QFrame()
        frame.setObjectName("stat")
        frame.setMinimumHeight(64)
        frame.setMinimumWidth(116)
        v = QVBoxLayout(frame)
        v.setContentsMargins(12, 7, 12, 7)
        v.setSpacing(1)

        mono = QFont(MONO, 8)
        mono.setLetterSpacing(QFont.AbsoluteSpacing, 1.1)
        cap = QLabel(title)
        cap.setFont(mono)
        cap.setStyleSheet("color:rgba(255,255,255,97); background:transparent;")
        val = RollingNumber(fmt) if numeric else QLabel("-")
        f = QFont("Segoe UI", 19)
        f.setWeight(QFont.DemiBold)
        val.setFont(f)
        val.setStyleSheet("color:#ffffff; background:transparent;")
        det = QLabel("")
        det.setFont(QFont(MONO, 8))
        det.setStyleSheet("color:rgba(255,255,255,97); background:transparent;")
        v.addWidget(cap)
        v.addWidget(val)
        v.addWidget(det)
        return frame, val, det

    def _build_left_panel(self) -> QWidget:
        panel = QWidget()
        lay = QVBoxLayout(panel)
        lay.setContentsMargins(0, 0, 0, 0)
        lay.setSpacing(8)

        ctl = QGroupBox("01   控制")
        g = QGridLayout(ctl)
        g.setSpacing(6)

        self.btn_enable = QPushButton("全部使能")
        self.btn_disable = QPushButton("全部失能")
        self.btn_estop = QPushButton("急停")
        self.btn_estop.setObjectName("danger")
        self.btn_clear_estop = QPushButton("解除急停")
        self.btn_zero = QPushButton("命令清零")

        self.btn_enable.clicked.connect(lambda: self.set_ctrl_bit(0x01, True))
        self.btn_disable.clicked.connect(lambda: self.set_ctrl_bit(0x01, False))
        self.btn_estop.clicked.connect(self.do_estop)
        self.btn_clear_estop.clicked.connect(self.clear_estop)
        self.btn_zero.clicked.connect(self.zero_commands)

        g.addWidget(self.btn_enable, 0, 0)
        g.addWidget(self.btn_disable, 0, 1)
        g.addWidget(self.btn_estop, 1, 0)
        g.addWidget(self.btn_clear_estop, 1, 1)
        g.addWidget(self.btn_zero, 2, 0, 1, 2)

        led_row = QHBoxLayout()
        self.btn_led_pick = QPushButton("选颜色")
        self.btn_led_apply = QPushButton("应用到 LED")
        self.btn_led_status = QPushButton("状态色")
        self.led_swatch = QLabel()
        self.led_swatch.setFixedSize(56, 24)
        self._paint_swatch()
        self.btn_led_pick.clicked.connect(self.pick_led)
        self.btn_led_apply.clicked.connect(self.apply_led)
        self.btn_led_status.clicked.connect(self.led_status_mode)
        led_row.addWidget(self.btn_led_pick)
        led_row.addWidget(self.led_swatch)
        led_row.addWidget(self.btn_led_apply)
        led_row.addWidget(self.btn_led_status)
        g.addLayout(led_row, 3, 0, 1, 2)

        self.lbl_ctrl = QLabel("ctrl=0x00")
        self.lbl_ctrl.setStyleSheet(
            f"color:rgba(255,255,255,97); font-family:'{MONO}'; font-size:8pt;")
        g.addWidget(self.lbl_ctrl, 4, 0, 1, 2)
        lay.addWidget(ctl)

        axbox = QGroupBox("02   轴命令")
        av = QVBoxLayout(axbox)
        av.setContentsMargins(6, 6, 6, 6)

        self.table = QTableWidget(AXES, 8)
        self.table.setHorizontalHeaderLabels(
            ["轴", "位置 °", "速度 °/s", "力矩 A", "Kp", "Kd", "反馈 °", "状态"])
        self.table.verticalHeader().setVisible(False)
        self.table.verticalHeader().setDefaultSectionSize(26)
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setSelectionMode(QAbstractItemView.NoSelection)
        self.table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.table.horizontalHeader().setSectionResizeMode(0, QHeaderView.ResizeToContents)
        self.spins = []
        self.fb_items = []
        self.st_items = []

        for r in range(AXES):
            item = QTableWidgetItem(f"{r + 1:02d}")
            item.setTextAlignment(Qt.AlignCenter)
            item.setFont(QFont(MONO, 9))
            item.setForeground(C_FG3)
            self.table.setItem(r, 0, item)
            row = []
            for c, (lo, hi, dec, step) in enumerate([
                (-3600.0, 3600.0, 2, 1.0),
                (-3000.0, 3000.0, 1, 5.0),
                (-100.0, 100.0, 2, 0.5),
                (0.0, 500.0, 0, 5.0),
                (0.0, 500.0, 2, 0.5),
            ], start=1):
                sp = QDoubleSpinBox()
                sp.setRange(lo, hi)
                sp.setDecimals(dec)
                sp.setSingleStep(step)
                sp.setValue(0.0)
                sp.setFont(QFont(MONO, 9))
                sp.setAlignment(Qt.AlignRight | Qt.AlignVCenter)
                sp.valueChanged.connect(self.mark_dirty)
                self.table.setCellWidget(r, c, sp)
                row.append(sp)
            self.spins.append(tuple(row))

            fbi = QTableWidgetItem("-")
            fbi.setTextAlignment(Qt.AlignRight | Qt.AlignVCenter)
            fbi.setFont(QFont(MONO, 9))
            fbi.setForeground(C_FG2)
            self.table.setItem(r, 6, fbi)
            sti = QTableWidgetItem("-")
            sti.setTextAlignment(Qt.AlignCenter)
            sti.setFont(QFont(MONO, 8))
            self.table.setItem(r, 7, sti)
            self.fb_items.append(fbi)
            self.st_items.append(sti)

        av.addWidget(self.table)
        lay.addWidget(axbox, 1)

        fb = QGroupBox("03   反馈")
        fv = QVBoxLayout(fb)
        fb.setFixedHeight(92)
        self.lbl_fb = QLabel("等待主站数据…")
        self.lbl_fb.setFont(QFont("Consolas", 9))
        self.lbl_fb.setStyleSheet("color:rgba(255,255,255,148);")
        self.lbl_fb.setMinimumHeight(56)
        fv.addWidget(self.lbl_fb)
        lay.addWidget(fb)
        return panel

    def _build_plots(self) -> QWidget:
        box = QWidget()
        grid = QGridLayout(box)
        grid.setContentsMargins(0, 0, 0, 0)
        grid.setSpacing(6)

        self.p_acc = HistoryPlot("加速度 (m/s²)", "m/s²",
                                 [CURVE_1, CURVE_2, CURVE_3],
                                 ["ax", "ay", "az"])
        self.p_gyro = HistoryPlot("角速度 (rad/s)", "rad/s",
                                  [CURVE_1, CURVE_2, CURVE_3],
                                  ["gx", "gy", "gz"])
        self.p_rpy = RpyPlots()
        self.p_axis = HistoryPlot("选中轴", "° / °/s",
                                  [CURVE_1, CURVE_2],
                                  ["位置 °", "速度 °/s"])

        sel = QWidget()
        h = QHBoxLayout(sel)
        h.setContentsMargins(0, 0, 0, 0)
        h.addWidget(QLabel("轴"))
        self.cmb_axis = QComboBox()
        self.cmb_axis.addItems([f"轴 {i:02d}" for i in range(1, AXES + 1)])
        h.addWidget(self.cmb_axis)
        h.addWidget(QLabel(f"  曲线窗口 {WINDOW_S:.0f} s @ 50 Hz"))
        h.addStretch(1)

        axis_wrap = QWidget()
        wv = QVBoxLayout(axis_wrap)
        wv.setContentsMargins(0, 0, 0, 0)
        wv.setSpacing(2)
        wv.addWidget(sel)
        wv.addWidget(self.p_axis)

        grid.addWidget(self.p_acc, 0, 0)
        grid.addWidget(self.p_gyro, 0, 1)
        grid.addWidget(self.p_rpy, 1, 0)
        grid.addWidget(axis_wrap, 1, 1)
        return box

    def _build_timers(self) -> None:
        self.t_poll = QTimer(self)
        self.t_poll.timeout.connect(self.poll)
        self.t_poll.start(20)

        self.t_plot = QTimer(self)
        self.t_plot.timeout.connect(self.refresh_plots)
        self.t_plot.start(100)

    # ---------------- 主站进程 ----------------
    def start_master(self) -> None:
        if self.master and self.master.poll() is None:
            return
        if self.last_state_t and time.time() - self.last_state_t < 1.0:
            # 刚停止主站时旧状态也还是"新鲜"的，用帧号是否推进来区分
            a = self.shm.read_state()
            time.sleep(0.15)
            b = self.shm.read_state()
            if a and b and b["frame"] != a["frame"]:
                QMessageBox.warning(
                    self, "已有主站",
                    "检测到正在运行的主站（可能是从命令行启动的）。\n"
                    "同一网卡只能有一个主站，请先关闭它。")
                return
        cycle = self.cmb_cycle.value()
        try:
            os.makedirs(os.path.join(ROOT, "logs"), exist_ok=True)
            self.master_log = open(os.path.join(ROOT, "logs", "master.log"), "wb")
            self.master = subprocess.Popen(
                [SOEM_BIN, DEFAULT_IFACE, str(cycle), "--headless"],
                cwd=ROOT,
                stdout=self.master_log,
                stderr=subprocess.STDOUT,
                creationflags=subprocess.CREATE_NO_WINDOW,
            )
        except OSError as exc:
            if self.master_log:
                self.master_log.close()
                self.master_log = None
            QMessageBox.critical(self, "启动失败", str(exc))
            return
        set_process_priority(self.master.pid, HIGH_PRIORITY_CLASS)
        self.statusBar().showMessage(
            f"主站启动中… pid={self.master.pid}  cycle={cycle} ns")
        self.last_frame = -1
        self.shm.write_cmd(self.cmd_ctrl, self.led, self.led_mode,
                           self.axis_values(), stop=0)
        QTimer.singleShot(1500, self._refresh_master_ui)

    def stop_master(self) -> None:
        if self.master and self.master.poll() is None:
            # 先请求优雅退出：关 SYNC0 + 从站回 INIT，下次启动无需复位 MCU
            self.shm.write_cmd(self.cmd_ctrl, self.led, self.led_mode,
                               self.axis_values(), stop=1)
            try:
                self.master.wait(timeout=3.0)
            except subprocess.TimeoutExpired:
                self.master.terminate()
                try:
                    self.master.wait(timeout=1.0)
                except subprocess.TimeoutExpired:
                    self.master.kill()
        self.master = None
        if self.master_log:
            self.master_log.close()
            self.master_log = None
        self._refresh_master_ui()
        self.statusBar().showMessage("主站已停止（从站已回到 INIT），可直接再次启动")

    def on_cycle_changed(self, _value) -> None:
        """运行中改周期：停主站 -> 重新按新周期启动。"""
        if not (self.master and self.master.poll() is None):
            return
        self.statusBar().showMessage("周期已改，正在按新周期重启主站…")
        self.stop_master()
        QTimer.singleShot(400, self.start_master)

    def reset_slave(self) -> None:
        if self.master and self.master.poll() is None:
            QMessageBox.information(self, "先停主站", "请先停止主站，再复位从站。")
            return
        try:
            subprocess.run(
                [JLINK_BIN, "-CommanderScript", JLINK_SCRIPT],
                cwd=HERE,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                creationflags=subprocess.CREATE_NO_WINDOW,
                timeout=15,
            )
        except (OSError, subprocess.TimeoutExpired) as exc:
            QMessageBox.warning(self, "复位失败", str(exc))
            return
        time.sleep(1.0)          # 等 MCU 启动、SSC 栈初始化完成
        self.statusBar().showMessage("从站已复位，可以重新启动主站")

    def _refresh_master_ui(self) -> None:
        running = bool(self.master and self.master.poll() is None)
        self.btn_start.setEnabled(not running)
        self.btn_stop.setEnabled(running)
        if running:
            self._set_pill("主站：运行中", "rgba(255,255,255,148)")
        else:
            self._set_pill("主站：未运行", "rgba(255,255,255,97)")

    def _set_pill(self, text: str, fg: str, bg: str = "", border: str = "") -> None:
        self.lbl_state.setText(text)
        self.lbl_state.setStyleSheet(
            f"color:{fg}; font-weight:600; padding:4px 12px;"
            f"background:transparent; border:1px solid rgba(255,255,255,71);"
            f"border-radius:999px; font-family:'{MONO}'; font-size:9pt;")

    # ---------------- 数据轮询 ----------------
    def poll(self) -> None:
        self._refresh_master_ui()

        st = self.shm.read_state()
        if st is None:
            if self.last_state_t and time.time() - self.last_state_t > 1.0:
                self._set_pill("主站：无数据", C_WARN)
            return

        fresh = st["frame"] != self.last_frame
        self.last_frame = st["frame"]
        self.last_state_t = time.time()

        al = AL_STATES.get(st["alstat"] & 0x0F, f"0x{st['alstat'] & 0x0F:02X}")
        self.lbl_wkc.setValue(st["wkc"])
        self.lbl_al.setText(al)
        self.lbl_al.setStyleSheet(
            "color:#ffffff; background:transparent;"
            if st["alstat"] == 0x0008 else
            "color:#e0a35a; background:transparent;")
        self.lbl_alc.setText(f"ALC 0x{st['alcode']:04X}   (0x{st['alstat']:04X})")
        self.lbl_fps.setValue(st["fps"])
        self.lbl_gap.setValue(st["gap_ms"])
        self.lbl_rtt.setValue(st["rtt_avg"])
        self.det_rtt.setText(f"{st['rtt_min']:.0f} / {st['rtt_max']:.0f}")
        self.lbl_mcu.setValue(st["mcu_avg"])
        self.det_mcu.setText(f"{st['mcu_min']:.0f} / {st['mcu_max']:.0f}")

        if not fresh:
            if self.last_fresh_t and time.time() - self.last_fresh_t > 1.0:
                if "无数据" not in self.lbl_state.text():
                    self._set_pill("主站：无数据（已停止）", C_WARN)
                    self.lbl_wkc.clear()
                    self.lbl_al.setText("-")
                    self.lbl_alc.setText("ALC -")
                    self.lbl_fps.clear()
                    self.lbl_gap.clear()
                    self.lbl_rtt.clear()
                    self.det_rtt.setText("")
                    self.lbl_mcu.clear()
                    self.det_mcu.setText("")
            return
        self.last_fresh_t = time.time()
        if st["frame"] <= 3:
            self.dirty = True

        if st["alstat"] != 0x0008:
            self._set_pill(f"主站：{al}", C_WARN)
        else:
            self._set_pill("主站：OP", "#ffffff")
            if "启动中" in self.statusBar().currentMessage():
                self.statusBar().showMessage(
                    f"主站运行中 · 周期 {self.cmb_cycle.value()} ns · "
                    f"{self.cmb_cycle.currentText()}")

        sel = self.cmb_axis.currentIndex()
        ax = st["axis"][sel]
        self.lbl_fb.setText(
            f"轴{sel + 1:02d}  id={ax['id']}  pos={ax['pos']:9.2f}°  "
            f"vel={ax['vel']:8.1f}°/s  status=0x{ax['status']:04X}\n"
            f"使能 {'Y' if ax['status'] & 0x01 else '-'}  "
            f"故障 {'Y' if ax['status'] & 0x02 else '-'}  "
            f"有效 {'Y' if ax['status'] & 0x20 else '-'}   "
            f"温度 {st['temp']}")

        self.mahony.update(st["acc"], st["gyro"])
        rpy = self.mahony.euler_deg()

        t = st["t_us"] * 1e-6
        self.p_acc.push(st["acc"], t)
        self.p_gyro.push(st["gyro"], t)
        self.p_rpy.push(rpy, t)
        self.p_axis.push([ax["pos"], ax["vel"]], t)

        self.poll_div += 1
        if self.poll_div % 5 == 0:
            self.update_feedback(st["axis"])

        if self.dirty:
            self.push_cmd()

    def update_feedback(self, axes) -> None:
        for i, a in enumerate(axes):
            self.fb_items[i].setText(f"{a['pos']:.2f}")
            en = bool(a["status"] & 0x01)
            flt = bool(a["status"] & 0x02)
            vld = bool(a["status"] & 0x20)
            self.st_items[i].setText(
                ("E" if en else "-") + ("F" if flt else "-") + ("V" if vld else "-"))
            if flt:
                self.st_items[i].setForeground(QColor(C_DANGER))
            elif en and vld:
                self.st_items[i].setForeground(QColor("#ffffff"))
            else:
                self.st_items[i].setForeground(C_FG3)

    def refresh_plots(self) -> None:
        for p in (self.p_acc, self.p_gyro, self.p_rpy, self.p_axis):
            p.refresh()

    # ---------------- 命令 ----------------
    def axis_values(self):
        return [tuple(sp.value() for sp in row) for row in self.spins]

    def push_cmd(self) -> None:
        self.shm.write_cmd(self.cmd_ctrl, self.led, self.led_mode,
                           self.axis_values())
        self.dirty = False
        self.lbl_ctrl.setText(f"ctrl=0x{self.cmd_ctrl:02X}")

    def mark_dirty(self, *_args) -> None:
        self.dirty = True

    def set_ctrl_bit(self, bit: int, on: bool) -> None:
        if on:
            self.cmd_ctrl |= bit
        else:
            self.cmd_ctrl &= ~bit
        self.dirty = True
        self.push_cmd()

    def do_estop(self) -> None:
        self.set_ctrl_bit(0x02, True)
        self.statusBar().showMessage("已发送急停：ctrl bit1 = 1")

    def clear_estop(self) -> None:
        self.set_ctrl_bit(0x02, False)
        self.statusBar().showMessage("急停位已清除")

    def zero_commands(self) -> None:
        for row in self.spins:
            for sp in row:
                sp.blockSignals(True)
                sp.setValue(0.0)
                sp.blockSignals(False)
        self.dirty = True
        self.push_cmd()
        self.statusBar().showMessage("17 轴命令已清零")

    def _paint_swatch(self) -> None:
        r, g, b = self.led
        self.led_swatch.setStyleSheet(
            f"background: rgb({r},{g},{b}); border:1px solid #555;")

    def pick_led(self) -> None:
        c = QColorDialog.getColor(QColor(*self.led), self, "选择 LED 颜色")
        if c.isValid():
            self.led = (c.red(), c.green(), c.blue())
            self._paint_swatch()

    def apply_led(self) -> None:
        self.led_mode = 1
        self.dirty = True
        self.push_cmd()
        self.statusBar().showMessage(f"LED = RGB{self.led}")

    def led_status_mode(self) -> None:
        self.led_mode = 0
        self.dirty = True
        self.push_cmd()
        self.statusBar().showMessage("LED 恢复状态色模式")

    def closeEvent(self, event) -> None:
        self.stop_master()
        event.accept()


APP_QSS = """
QMainWindow, QDialog { background: #000000; }
QWidget { background: transparent; color: #ffffff;
          font-family: "Microsoft YaHei UI"; font-size: 10pt; }

QFrame#topbar, QFrame#stat {
    background: #070707;
    border: 1px solid rgba(255,255,255,41);
    border-radius: 12px;
}

QGroupBox {
    background: #070707;
    border: 1px solid rgba(255,255,255,41);
    border-radius: 12px;
    margin-top: 0px;
    padding: 26px 10px 10px 10px;
}
QGroupBox::title {
    subcontrol-origin: padding;
    subcontrol-position: top left;
    left: 12px; top: 8px; padding: 0 4px;
    color: rgba(255,255,255,97);
    font-family: "Consolas"; font-size: 8pt;
}

QPushButton {
    background: transparent;
    border: 1px solid rgba(255,255,255,71);
    border-radius: 7px;
    padding: 6px 14px;
    color: #ffffff;
}
QPushButton:hover { border-color: rgba(255,255,255,148); background: rgba(255,255,255,15); }
QPushButton:pressed { background: rgba(255,255,255,20); }
QPushButton:disabled { color: rgba(255,255,255,51); border-color: rgba(255,255,255,26); }
QPushButton#primary { background: #ffffff; border-color: #ffffff; color: #000000; font-weight: 600; }
QPushButton#primary:hover { background: #e6e6e6; }
QPushButton#primary:disabled { background: transparent; color: rgba(255,255,255,51);
                               border-color: rgba(255,255,255,26); }
QPushButton#danger { background: #b3261e; border-color: #b3261e; color: #ffffff; font-weight: 600; }
QPushButton#danger:hover { background: #c9332a; }

QComboBox {
    background: transparent;
    border: 1px solid rgba(255,255,255,41);
    border-radius: 7px;
    padding: 3px 8px;
    color: #ffffff;
    font-family: "Consolas"; font-size: 9pt;
}
QComboBox:hover { border-color: rgba(255,255,255,71); }
QComboBox::drop-down { border: none; width: 18px; }
QComboBox QAbstractItemView {
    background: #070707;
    border: 1px solid rgba(255,255,255,41);
    selection-background-color: rgba(255,255,255,36);
    color: #ffffff; outline: 0;
}

QDoubleSpinBox {
    background: transparent; border: none; color: #ffffff;
    font-family: "Consolas"; font-size: 9pt; padding: 1px 2px;
}
QDoubleSpinBox:focus { border: 1px solid rgba(255,255,255,71); border-radius: 4px; }
QDoubleSpinBox::up-button, QDoubleSpinBox::down-button { width: 0px; border: none; }

QTableWidget {
    background: #000000;
    border: none;
    gridline-color: rgba(255,255,255,20);
    selection-background-color: transparent;
}
QTableWidget::item { padding: 2px 4px; border: none; }
QHeaderView::section {
    background: #000000;
    color: rgba(255,255,255,97);
    border: none;
    border-bottom: 1px solid rgba(255,255,255,41);
    padding: 6px 4px;
    font-family: "Consolas"; font-size: 8pt;
}
QTableCornerButton::section { background: #000000; border: none; }

QStatusBar { color: rgba(255,255,255,97); font-family: "Consolas"; font-size: 8pt; }

QScrollBar:vertical { width: 9px; background: transparent; margin: 0; }
QScrollBar::handle:vertical { background: rgba(255,255,255,36); border-radius: 4px; min-height: 24px; }
QScrollBar::add-line, QScrollBar::sub-line { height: 0; }
QScrollBar::add-page, QScrollBar::sub-page { background: transparent; }

QToolTip { background: #070707; color: #ffffff; border: 1px solid rgba(255,255,255,41); }
"""


def main() -> int:
    pg.setConfigOptions(antialias=True, useOpenGL=False)
    app = QApplication(sys.argv)
    app.setStyle("Fusion")
    app.setFont(QFont("Microsoft YaHei UI", 10))
    app.setStyleSheet(APP_QSS)
    w = MainWindow()
    w.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
