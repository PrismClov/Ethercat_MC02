"""NOIR Web UI 的本地桥。

  * 静态文件：本目录
  * GET  /api/stream  以 SSE 推送共享内存状态（20 Hz）
  * POST /api/cmd     写命令到 ecat_ui_cmd
  * POST /api/master  启动/停止 ecat_live.exe（{"action":"start"|"stop","cycle":500000}）

用法: python serve.py [--port 8765]
"""

import json
import mmap
import os
import struct
import subprocess
import sys
import threading
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import urlparse

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)          # HostTools/
SERVE_DIR = HERE
IS_WINDOWS = os.name == "nt"
if IS_WINDOWS:
    EXE = os.path.join(ROOT, "bin", "ecat_live.exe")
    IFACE = r"\Device\NPF_{9269FBF0-8A17-4A3B-A238-90DF8FACBB09}"
    RT_PRIORITY = 0
    RT_CPU = -1
else:
    EXE = os.environ.get(
        "ECAT_MASTER",
        os.path.join(ROOT, "..", "build", "soem_master", "ecat_soem_master"),
    )
    IFACE = os.environ.get("ECAT_IFACE", "enP8p1s0")
    RT_PRIORITY = int(os.environ.get("ECAT_RT_PRIORITY", "80"))
    RT_CPU = int(os.environ.get("ECAT_CPU", "5"))
    DC_LEAD_US = int(os.environ.get("ECAT_DC_LEAD_US", "0"))
JLINK_SCRIPT = os.path.join(ROOT, "jlink", "reset_only.jlink")
LOG_DIR = os.path.join(ROOT, "logs")

AXES = 17
STATE_NAME, CMD_NAME = "ecat_ui_state", "ecat_ui_cmd"
STATE_MAGIC, CMD_MAGIC = 0x32545345, 0x32434D45

# 与 ecat_ui_shm.h 保持一致
STATE_FMT = "<IIIIQff3f3f3h3hHHHHHH" + "ffHHihH" * AXES + "ffffff"
CMD_FMT = "<III6B2B" + "fffff" * AXES
STATE_SIZE = struct.calcsize(STATE_FMT)
CMD_SIZE = struct.calcsize(CMD_FMT)
STREAM_HZ = 20

shared_handles = []


def _open_shared(name, size):
    if IS_WINDOWS:
        return mmap.mmap(-1, size, tagname=name, access=mmap.ACCESS_WRITE)

    from multiprocessing import shared_memory

    try:
        handle = shared_memory.SharedMemory(name=name, create=True, size=size)
    except FileExistsError:
        handle = shared_memory.SharedMemory(name=name)
    if handle.size < size:
        handle.close()
        raise OSError(f"shared memory {name} is too small")
    shared_handles.append(handle)
    return handle.buf


state_mm = _open_shared(STATE_NAME, STATE_SIZE)
cmd_mm = _open_shared(CMD_NAME, CMD_SIZE)
cmd_seq = 0
cmd_lock = threading.Lock()
master = None
master_lock = threading.Lock()
last_frame = -1
last_change = 0.0


def read_state():
    global last_frame, last_change
    try:
        raw = state_mm[:STATE_SIZE]
    except (ValueError, OSError):
        return {"online": False}
    seq1 = struct.unpack_from("<I", raw, 0)[0]
    if seq1 & 1:
        return None
    v = struct.unpack(STATE_FMT, raw)
    if struct.unpack_from("<I", raw, 0)[0] != seq1:
        return None
    if v[1] != STATE_MAGIC or v[2] != STATE_SIZE:
        return {"online": False}

    # 主站退出后共享内存还留着最后一帧，用帧号是否推进判断"是否真的还在跑"
    if v[3] != last_frame:
        last_frame = v[3]
        last_change = time.time()
    if last_change == 0.0 or time.time() - last_change > 0.6:
        return {"online": False}

    tail = 25 + AXES * 7
    axes = []
    for i in range(AXES):
        o = 25 + i * 7
        axes.append({
            "pos": v[o], "vel": v[o + 1], "status": v[o + 2],
            "id": v[o + 3],
        })
    return {
        "online": True,
        "frame": v[3],
        "t": v[4] / 1e6,
        "fps": v[5],
        "gap": v[6],
        "acc": list(v[7:10]),
        "gyro": list(v[10:13]),
        "wkc": v[19],
        "al": v[20],
        "alc": v[21],
        "phase": v[22],
        "phase_max": v[24],
        "rtt": v[tail], "rtt_min": v[tail + 1], "rtt_max": v[tail + 2],
        "mcu": v[tail + 3], "mcu_min": v[tail + 4], "mcu_max": v[tail + 5],
        "axes": axes,
    }


def write_cmd(payload):
    global cmd_seq
    axes = payload.get("axes") or [[0, 0, 0, 0, 0]] * AXES
    led = payload.get("led") or [0, 0, 0]
    with cmd_lock:
        cmd_seq = (cmd_seq + 1) & 0x7FFFFFFF
        # 奇数表示正在写入。C 主站会忽略奇数 seq，写完后必须提交为偶数，
        # 否则第一次命令会被当成“仍在更新”而丢弃。
        head = struct.pack(
            "<III6B2B", cmd_seq, CMD_MAGIC, CMD_SIZE,
            int(payload.get("ctrl", 0)) & 0xFF,
            int(payload.get("led_mode", 0)) & 0xFF,
            led[0] & 0xFF, led[1] & 0xFF, led[2] & 0xFF,
            int(payload.get("stop", 0)) & 0xFF, 0, 0)
        body = b"".join(struct.pack("<fffff", *[float(x) for x in a]) for a in axes)
        cmd_mm[:len(head)] = head
        cmd_mm[len(head):len(head) + len(body)] = body
        cmd_seq = (cmd_seq + 1) & 0x7FFFFFFF
        struct.pack_into("<I", cmd_mm, 0, cmd_seq)


def _reap_master(process):
    """Reap a stopped master without delaying the HTTP response."""
    try:
        process.wait(timeout=1.0)
    except subprocess.TimeoutExpired:
        process.terminate()
        try:
            process.wait(timeout=0.5)
        except subprocess.TimeoutExpired:
            process.kill()


def master_action(action, cycle):
    global master
    with master_lock:
        running = master is not None and master.poll() is None
        if action == "reset":
            if running:
                return {"running": True, "error": "stop first"}
            if not IS_WINDOWS:
                return {
                    "running": False,
                    "error": "Linux 下请重启从站电源或使用 J-Link，然后重新启动主站",
                }
            jlink = r"D:\clover\Embedded\SEGGER\JLink_V810b\JLink.exe"
            script = JLINK_SCRIPT
            try:
                subprocess.run([jlink, "-CommanderScript", script], cwd=ROOT,
                               stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                               creationflags=subprocess.CREATE_NO_WINDOW, timeout=15)
                time.sleep(1.0)
            except Exception as exc:
                return {"running": False, "error": str(exc)}
            return {"running": False, "reset": True}
        if action == "stop":
            if running:
                write_cmd({"ctrl": 0, "stop": 1})
                process = master
                master = None
                threading.Thread(
                    target=_reap_master,
                    args=(process,),
                    daemon=False,
                ).start()
                return {"running": False, "stopping": True}
            master = None
            return {"running": False}
        if running:
            return {"running": True}

        if not os.path.isfile(EXE):
            return {"running": False, "error": "ecat_live.exe not found: " + EXE}

        os.makedirs(LOG_DIR, exist_ok=True)
        try:
            log = open(os.path.join(LOG_DIR, "master.log"), "wb")
            if IS_WINDOWS:
                args = [EXE, IFACE, str(int(cycle)), "--headless"]
                popen_kwargs = {"creationflags": subprocess.CREATE_NO_WINDOW}
            else:
                args = [EXE, "-i", IFACE, "--cycle-ns", str(int(cycle)),
                        "--profile", "mc02", "--lock-memory"]
                if DC_LEAD_US > 0:
                    args += ["--dc-lead-us", str(DC_LEAD_US)]
                if RT_PRIORITY > 0:
                    args += ["--rt-priority", str(RT_PRIORITY)]
                if RT_CPU >= 0:
                    args += ["--cpu", str(RT_CPU)]
                popen_kwargs = {}
            master = subprocess.Popen(
                args, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT,
                **popen_kwargs)
        except OSError as exc:
            return {"running": False, "error": str(exc)}

        if IS_WINDOWS:
            try:
                import ctypes
                h = ctypes.windll.kernel32.OpenProcess(0x0200, False, master.pid)
                if h:
                    ctypes.windll.kernel32.SetPriorityClass(h, 0x80)
                    ctypes.windll.kernel32.CloseHandle(h)
            except Exception:
                pass

        # 启动命令立即返回。界面通过 SSE 状态确认是否真正进入 OP，
        # 避免 EtherCAT 初始化期间按钮长时间没有任何反馈。
        time.sleep(0.2)
        running = master.poll() is None
        st = read_state()
        online = bool(
            running and st and st.get("online")
            and (st.get("al", 0) & 0x0F) == 0x08
        )
        result = {
            "running": running,
            "starting": running and not online,
            "online": online,
            "pid": master.pid,
        }
        if not result["running"]:
            try:
                with open(os.path.join(LOG_DIR, "master.log"), "rb") as fh:
                    tail = fh.read()[-1600:].decode("utf-8", "replace")
                result["error"] = tail.strip().splitlines()[-1] if tail.strip() else ""
            except OSError:
                pass
        return result


class Bridge(ThreadingHTTPServer):
    # Windows 上 SO_REUSEADDR 允许重复绑定同一个端口，会导致两个桥抢请求；
    # Linux 需要它来避免重启时被 TIME_WAIT 占住。
    allow_reuse_address = not IS_WINDOWS
    daemon_threads = True


class Handler(SimpleHTTPRequestHandler):
    def __init__(self, *a, **kw):
        super().__init__(*a, directory=SERVE_DIR, **kw)

    def log_message(self, *_a):
        pass

    def do_GET(self):
        if urlparse(self.path).path == "/api/stream":
            return self.stream()
        return super().do_GET()

    def stream(self):
        self.send_response(200)
        self.send_header("Content-Type", "text/event-stream")
        self.send_header("Cache-Control", "no-cache")
        self.end_headers()
        try:
            while True:
                st = read_state()
                if st is not None:
                    payload = json.dumps(st, separators=(",", ":")).encode()
                    self.wfile.write(b"data: " + payload + b"\n\n")
                    self.wfile.flush()
                time.sleep(1 / STREAM_HZ)
        except (BrokenPipeError, ConnectionResetError, OSError):
            pass

    def do_POST(self):
        path = urlparse(self.path).path
        n = int(self.headers.get("Content-Length") or 0)
        try:
            body = json.loads(self.rfile.read(n) or b"{}")
        except json.JSONDecodeError:
            body = {}
        if path == "/api/cmd":
            write_cmd(body)
        elif path == "/api/master":
            body = master_action(body.get("action", "start"), body.get("cycle", 500000))
        else:
            self.send_error(404)
            return
        out = json.dumps(body).encode()
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(out)))
        self.end_headers()
        self.wfile.write(out)


def main():
    global SERVE_DIR
    port = 8765
    if "--port" in sys.argv:
        port = int(sys.argv[sys.argv.index("--port") + 1])
    if "--root" in sys.argv:
        SERVE_DIR = os.path.abspath(sys.argv[sys.argv.index("--root") + 1])
    try:
        srv = Bridge(("127.0.0.1", port), Handler)
    except OSError as exc:
        print(f"port {port} already in use ({exc}); another bridge is running")
        return
    print(f"NOIR Web UI  ->  http://127.0.0.1:{port}/")
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        master_action("stop", 0)


def start_server(port=8766, root=None):
    """给 web_client.py 用：后台线程起桥，返回 server 对象。"""
    global SERVE_DIR
    if root:
        SERVE_DIR = os.path.abspath(root)
    srv = Bridge(("127.0.0.1", port), Handler)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    return srv


if __name__ == "__main__":
    main()
