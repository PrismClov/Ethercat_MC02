# EtherCAT 17 轴主站工具

PC 侧主站（C + SOEM 2.0.0）与实时控制界面（Python + PySide6 + pyqtgraph）。

本目录是固件仓库的 `HostTools/`，和从站固件（`User/`、`Core/`）在同一个 git 仓库里。

## 目录

```
HostTools/
├─ EcatUI.exe          双击启动 Qt 界面（原生启动器）
├─ EcatWeb.exe         双击启动 React Web 版（起桥 + 开浏览器）
├─ build.cmd           编译 C 主站工具 + 探针 + 启动器 -> bin\
├─ run_ui.cmd          命令行启动 Qt 界面
├─ run_web.cmd         零依赖 Web 版（8765）
├─ run_react.cmd       React 版（8766）
├─ build_react.cmd     构建 React 版
├─ bin\                ecat_live.exe / ecat_zero_probe.exe / ecat_dc_sync_1ms.exe
├─ src\                C 源码 + 共享内存头（ecat_live.c, ecat_ui_shm.h, launcher.c ...）
├─ ui\ecat_ui.py       PySide6 界面
├─ webui\              零依赖 Web（HTML/CSS/JS + serve.py 桥）
├─ webui-react\        React + noir-ui
├─ jlink\              J-Link 脚本（reset_only.jlink / flash_spi40.jlink 在用）
├─ scripts\            旧的 ps1 / gdb / py 辅助脚本
├─ docs\               截图
├─ logs\               运行日志（master.log 等，已忽略）
└─ legacy\             历史快照
```

`EcatUI.exe` 是 **66 KB 原生启动器**：找同目录的 `ui\ecat_ui.py`，用
`D:\clover\Environment\Python\pythonw.exe` 无控制台启动；可用环境变量
`ECAT_PYTHON` 指向别的 pythonw.exe。

## 打包 React 版

React 版没有"打包成 exe"这一步的必要——它本身就是静态文件：

```
build_react.cmd      # npm run build -> webui-react\dist
EcatWeb.exe          # 起 serve.py(8766) + 打开默认浏览器
```

`webui-react\dist\` 里只有 `index.html` + 一个 CSS + 一个 JS（gzip 约 96 KB），
可以整个目录拷到任何静态服务器；但**数据接口 `/api/*` 必须由 `webui/serve.py`
提供**（它读共享内存、转发命令），所以纯静态托管只能看界面、没有数据。

如果要的是"像原生程序一样的独立窗口"，而不是开浏览器：

| 方案 | 代价 |
|---|---|
| `EcatWeb.exe` + 浏览器（当前） | 67 KB，秒开；依赖已装好的 Python |
| Tauri 包装 | 需要 Rust 工具链，安装包约 3–5 MB；用系统 WebView2 |
| Electron 包装 | `npm i electron`，安装包 150 MB+；自带 Chromium |
| PyInstaller 打包 Qt 版 | 本机 PySide6 6.12 不可用（QtCore DLL 127），需降版本 |

其余 `ecat_ws2812*.c`、`diag.c`、`reg_read.c` 等是调试阶段的辅助程序，保留作参考。
`*.jlink` 是 J-Link 命令脚本，`reset_only.jlink` / `flash_spi40.jlink` 仍在使用。

## 三个界面

| 版本 | 入口 | 特点 |
|---|---|---|
| Qt / PySide6 | `run_ui.cmd` | 原生、最省资源；弹簧滑块 + 数字滚动，图表 10 fps |
| Web 零依赖 | `run_web.cmd` | HTML+CSS+JS，单个 Python 桥；用真 `mix-blend-mode: difference` 做指示块 |
| Web React | `run_react.cmd` | 直接 `npm i github:HanRabbit/NOIR-UI`，用它的 `Segmented / NumberFlow / Stat / toast` |

Web 版的数据通路：`ecat_live.exe` ↔ 共享内存 ↔ `webui/serve.py`（SSE 30 Hz）↔ 浏览器。
三个界面可以同时开着看同一份数据，但**同一时刻只能有一个主站进程**。

## 编译

依赖：
- SOEM 2.0.0：`C:\Users\Administrator\Projects\soem-2.0.0\SOEM-v2.0.0`
- MinGW gcc（WinLibs）、Npcap/WinPcap

```
build.cmd
```

## 运行

```
run_ui.cmd
```

界面里选周期（2 kHz / 1 kHz / 3 kHz）→「启动主站」。停止请用「停止主站」：
主站会关 SYNC0、把从站退回 INIT，之后可以直接再次启动。若主站被强杀，
点「复位从站」再启动。

纯命令行：

```
ecat_live.exe "\Device\NPF_{...}" 500000 --headless
ecat_zero_probe.exe "\Device\NPF_{...}" 15 500000
```

> 同一网卡同一时刻只能有一个主站。

## 共享内存

| 名字 | 方向 | 大小 | 用途 |
|---|---|---|---|
| `ecat_imu` | 主站 → 其他进程 | 60 B | IMU 原始值/换算值 + WKC + AL |
| `ecat_ui_state` | 主站 → 界面 | 444 B | 每周期发布：IMU、17 轴反馈、AL/WKC、FPS、延迟 |
| `ecat_ui_cmd` | 界面 → 主站 | 360 B | `seq` 变化时生效：ctrl、LED、17 轴 MIT 命令、stop |

约定：写方 `seq++` → 写 → `seq++`；读方读前后两次 `seq` 相同且为偶数才采用。

## 延迟探针

从站固件 `PDO_LATENCY_PROBE=1` 时：

| 位置 | 内容 |
|---|---|
| 输出 `0x7050 U4..U7`（偏移 180） | 主站 `now_us()` 低 32 位 |
| 输入 `VT1..VT4`（182） | 回显该时间戳 → **RTT（含 Windows 调度）** |
| 输入 `VT5..VT6`（186） | PDI 中断耗时（DWT）→ **MCU 处理（不含 Windows）** |
| 输入 `VT7..VT8`（188） | 输出事件 → 输入映射 的相位差 |

2 kHz 实测：MCU 中断 15 µs；RTT 均值约 640 µs（基线约 1 个 SYNC0 周期），
最大 1.2~1.9 ms，抖动来自 Windows 调度。

> 探针占用了原 USART7 透传区 `VT1..VT8`；要同时用 USART7 就把该宏置 0。

## 已知限制

- Windows 不是实时系统，2 kHz 下偶发 1~3 ms 发帧抖动，UI 的 `最大间隔` 能看到。
- 经典 CAN 1 Mbit/s 跑不下 7 轴 × 1 kHz（14 帧 ≈ 1.67 ms），需 FD-BRS 或降 CAN 侧控制率。
- 曲线窗口 30 s @ 50 Hz，界面刷新 10 fps（再高会拖慢事件循环）。
