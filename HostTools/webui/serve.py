"""NOIR Web UI 的本地桥。

  * 静态文件：本目录
  * GET  /api/stream  以 SSE 推送共享内存状态（30 Hz）
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
EXE = os.path.join(ROOT, "ecat_live.exe")
IFACE = r"\Device\NPF_{9269FBF0-8A17-4A3B-A238-90DF8FACBB09}"

AXES = 17
STATE_NAME, CMD_NAME = "ecat_ui_state", "ecat_ui_cmd"
STATE_MAGIC, CMD_MAGIC = 0x32545345, 0x32434D45

# 与 ecat_ui_shm.h 保持一致
STATE_FMT = "<IIIIQff3f3f3h3hHHHHHH" + "ffHHihH" * AXES + "ffffff"
CMD_FMT = "<III6B2B" + "fffff" * AXES
STATE_SIZE = struct.calcsize(STATE_FMT)
CMD_SIZE = struct.calcsize(CMD_FMT)

state_mm = mmap.mmap(-1, STATE_SIZE, tagname=STATE_NAME, access=mmap.ACCESS_WRITE)
cmd_mm = mmap.mmap(-1, CMD_SIZE, tagname=CMD_NAME, access=mmap.ACCESS_WRITE)
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
        head = struct.pack(
            "<III6B2B", cmd_seq, CMD_MAGIC, CMD_SIZE,
            int(payload.get("ctrl", 0)) & 0xFF,
            int(payload.get("led_mode", 0)) & 0xFF,
            led[0] & 0xFF, led[1] & 0xFF, led[2] & 0xFF,
            0, 0, 0)
        body = b"".join(struct.pack("<fffff", *[float(x) for x in a]) for a in axes)
        cmd_mm[:len(head)] = head
        cmd_mm[len(head):len(head) + len(body)] = body


def master_action(action, cycle):
    global master
    with master_lock:
        running = master is not None and master.poll() is None
        if action == "reset":
            if running:
                return {"running": True, "error": "stop first"}
            jlink = r"D:\clover\Embedded\SEGGER\JLink_V810b\JLink.exe"
            script = os.path.join(ROOT, "reset_only.jlink")
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
                try:
                    master.wait(timeout=3.0)
                except subprocess.TimeoutExpired:
                    master.terminate()
            master = None
            return {"running": False}
        if running:
            return {"running": True}

        log = open(os.path.join(ROOT, "master.log"), "wb")
        master = subprocess.Popen(
            [EXE, IFACE, str(int(cycle)), "--headless"],
            cwd=ROOT, stdout=log, stderr=subprocess.STDOUT,
            creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            import ctypes
            h = ctypes.windll.kernel32.OpenProcess(0x0200, False, master.pid)
            if h:
                ctypes.windll.kernel32.SetPriorityClass(h, 0x80)
                ctypes.windll.kernel32.CloseHandle(h)
        except Exception:
            pass
        return {"running": True, "pid": master.pid}


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
                    self.wfile.write(b"data: " + json.dumps(st).encode() + b"\n\n")
                    self.wfile.flush()
                time.sleep(1 / 30)
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
    srv = ThreadingHTTPServer(("127.0.0.1", port), Handler)
    print(f"NOIR Web UI  ->  http://127.0.0.1:{port}/")
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        master_action("stop", 0)


if __name__ == "__main__":
    main()
