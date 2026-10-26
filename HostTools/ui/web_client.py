"""EcatClient —— 把 React 版装进一个原生窗口（QtWebEngine），不用浏览器。

内部流程：
  1. 在后台线程起 webui/serve.py 的 HTTP 桥（默认 8766）
  2. QWebEngineView 加载 http://127.0.0.1:8766/
  3. 关窗口时停主站、关桥
"""

import os
import sys


def find_root(start: str) -> str:
    d = os.path.abspath(start)
    for _ in range(5):
        if os.path.isdir(os.path.join(d, "bin")) and os.path.isdir(os.path.join(d, "webui")):
            return d
        parent = os.path.dirname(d)
        if parent == d:
            break
        d = parent
    return os.path.abspath(start)


HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = find_root(HERE)
sys.path.insert(0, os.path.join(ROOT, "webui"))

from PySide6.QtCore import QUrl, QTimer
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QApplication, QMainWindow, QMessageBox
from PySide6.QtWebEngineWidgets import QWebEngineView

import serve

PORT = 8766
DIST = os.path.join(ROOT, "webui-react", "dist")


def main() -> int:
    if not os.path.isfile(os.path.join(DIST, "index.html")):
        app = QApplication(sys.argv)
        QMessageBox.critical(None, "EcatClient",
                             "还没有构建产物 webui-react\\dist。\n请先运行 build_react.cmd。")
        return 1

    app = QApplication(sys.argv)
    app.setApplicationName("EcatClient")

    own_server = None
    try:
        own_server = serve.start_server(PORT, DIST)
    except OSError:
        pass          # 已经有一个客户端在跑，直接连它

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

    if own_server is not None:
        try:
            serve.master_action("stop", 0)
        except Exception:
            pass
        own_server.shutdown()
    return code


if __name__ == "__main__":
    raise SystemExit(main())
