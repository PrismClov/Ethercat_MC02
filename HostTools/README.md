# EtherCAT 17 轴主站工具

PC 侧主站（C + SOEM 2.0.0）与实时控制界面（Python + PySide6 + pyqtgraph）。

本目录是固件仓库的 `HostTools/`，和从站固件（`User/`、`Core/`）在同一个 git 仓库里。

## 组成

| 文件 | 说明 |
|---|---|
| `ecat_live.c` | 主站：PDO 收发、DC SYNC0、共享内存、`--headless` 模式 |
| `ecat_ui_shm.h` | 主站 ↔ 界面共享内存结构（`ecat_ui_state` / `ecat_ui_cmd`） |
| `imu_shm.h` | IMU 共享内存 `ecat_imu`（给 Mahony 进程用） |
| `ecat_ui.py` | 界面：17 轴命令、使能/急停、LED、IMU/RPY/轴曲线、延迟卡片 |
| `ecat_zero_probe.c` | 回归工具：全速率统计全 0 帧、发帧间隔 |
| `ecat_dc_sync.c` | DC/周期压力测试工具 |
| `ecat_sdo_dump.c` | 只读 dump（SM/PDO 配置） |
| `mahony_ahrs.c` | 独立的 Mahony 姿态进程（读 `ecat_imu`） |
| `build.cmd` | 重新编译主站工具 |
| `run_ui.cmd` | 启动界面 |

其余 `ecat_ws2812*.c`、`diag.c`、`reg_read.c` 等是调试阶段的辅助程序，保留作参考。
`*.jlink` 是 J-Link 命令脚本，`reset_only.jlink` / `flash_spi40.jlink` 仍在使用。

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
