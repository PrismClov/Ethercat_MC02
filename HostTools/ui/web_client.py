"""EcatClient —— 把 React 版装进一个原生桌面窗口，不打开外部浏览器。

内部流程：
  1. 在后台线程起 webui/serve.py 的 HTTP 桥（默认 8766）
  2. Windows 使用 QtWebEngine，Linux 使用 WebKit2GTK
  3. 关窗口时停主站、关桥
"""

import os
import sys


def find_root(start: str) -> str:
    d = os.path.abspath(start)
    for _ in range(5):
        if os.path.isdir(os.path.join(d, "webui")) and (
            os.path.isdir(os.path.join(d, "bin"))
            or os.path.isdir(os.path.join(d, "soem_master"))
        ):
            return d
        parent = os.path.dirname(d)
        if parent == d:
            break
        d = parent
    return os.path.abspath(start)


HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = find_root(HERE)
sys.path.insert(0, os.path.join(ROOT, "webui"))

import serve

PORT = 8766
DIST = os.path.join(ROOT, "webui-react", "dist")


def _start_bridge():
    try:
        return serve.start_server(PORT, DIST)
    except OSError:
        return None          # 已有桥在监听，直接连接


def _stop_bridge(server) -> None:
    if server is None:
        return
    try:
        serve.master_action("stop", 0)
    except Exception:
        pass
    server.shutdown()


def _run_qt() -> int:
    from PySide6.QtCore import QUrl, QTimer
    from PySide6.QtGui import QIcon
    from PySide6.QtWidgets import QApplication, QMainWindow, QMessageBox
    from PySide6.QtWebEngineWidgets import QWebEngineView

    app = QApplication(sys.argv)
    app.setApplicationName("EcatClient")

    own_server = _start_bridge()

    view = QWebEngineView()
    suffix = "#capture" if "--capture" in sys.argv else ""
    view.load(QUrl(f"http://127.0.0.1:{PORT}/{suffix}"))

    win = QMainWindow()
    win.setCentralWidget(view)
    win.resize(1620, 1000)
    win.setWindowTitle("EtherCAT · NOIR")
    icon = os.path.join(ROOT, "docs", "icon.png")
    if os.path.isfile(icon):
        win.setWindowIcon(QIcon(icon))
    win.show()

    # 页面加载完再把窗口抬到前面
    def bring_forward():
        win.raise_()
        win.activateWindow()
    QTimer.singleShot(1200, bring_forward)

    code = app.exec()
    _stop_bridge(own_server)
    return code


def _run_webkit() -> int:
    import gi

    gi.require_version("Gtk", "3.0")
    gi.require_version("WebKit2", "4.0")
    from gi.repository import Gtk, WebKit2

    own_server = _start_bridge()
    win = Gtk.Window(title="EtherCAT · NOIR")
    win.set_default_size(1620, 1000)
    win.set_position(Gtk.WindowPosition.CENTER)
    view = WebKit2.WebView()
    view.set_hexpand(True)
    view.set_vexpand(True)
    win.add(view)
    suffix = "#capture" if "--capture" in sys.argv else ""
    view.load_uri(f"http://127.0.0.1:{PORT}/{suffix}")
    win.connect("destroy", Gtk.main_quit)
    win.show_all()
    win.present()
    Gtk.main()
    _stop_bridge(own_server)
    return 0


def main() -> int:
    if not os.path.isfile(os.path.join(DIST, "index.html")):
        print("缺少 webui-react/dist，请先运行 HostTools/build_react_linux.sh",
              file=sys.stderr)
        return 1
    try:
        return _run_qt()
    except (ImportError, ModuleNotFoundError):
        return _run_webkit()


if __name__ == "__main__":
    raise SystemExit(main())
