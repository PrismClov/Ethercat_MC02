# SOEM EtherCAT 主站

这是一个面向 Linux 的 SOEM 2.0.0 EtherCAT 主站，可直接配合本仓库的
MC02/LAN9252 从站使用。它是独立于 STM32 固件的 PC 侧程序，不会编入 MCU。

默认行为是安全监视：输出 PDO 全部清零，只读取过程和状态数据，不会使能电机。

## 功能

- 枚举网卡、扫描从站并打印 Vendor/Product/Revision
- 完整的 INIT → Pre-Op → Safe-Op → Op 状态切换
- 周期发送/接收过程数据，检查 WKC
- Ctrl+C/SIGTERM 时关闭 SYNC0，并请求从站返回 INIT
- 可选 MC02 配置：`0x1C32/0x1C33`、`0x10F1:2`、SM 看门狗、DC/SYNC0
- 与 `webui/serve.py`、React NOIR 页面共享状态并接收 17 轴/LED 命令
- `--preop-only` 可用于首次接线和邮箱通信排查

这是普通 Linux 用户态主站，不等同于带实时调度的 IgH 主站。用于设备联调、
状态检查和低到中速过程数据没有问题；生产环境若要求硬实时和高抖动指标，
应使用 RT-Preempt 内核或 IgH EtherCAT Master，并实测周期抖动。

## 依赖

- Linux（Ubuntu/Debian 等）
- CMake 3.22+
- GCC/Clang
- SOEM 2.0.0
- 一块不配置 IP、专用于 EtherCAT 的以太网卡

安装编译依赖：

```bash
sudo apt install build-essential cmake libpcap-dev
```

本项目不在仓库中复制 SOEM 源码。可以安装 SOEM，或在构建时指定源码目录：

```bash
git clone --branch v2.0.0 https://github.com/OpenEtherCATsociety/SOEM.git
cmake -S HostTools/soem_master -B build/soem_master \
  -DSOEM_ROOT="$PWD/SOEM" -DCMAKE_BUILD_TYPE=Release
cmake --build build/soem_master -j
```

如果系统已经安装 SOEM 2.0.0，可以省略 `SOEM_ROOT`。也允许在联网环境下用
`-DECAT_FETCH_SOEM=ON` 自动下载固定版本。

SOEM 2.0.0 自身要求 CMake 3.28，因此指定 `SOEM_ROOT` 构建时也需要
CMake 3.28+。若系统 CMake 较旧，先把它安装的 SOEM 库和头文件配置好，再
使用 `find_package(soem CONFIG)` 路径。

## 运行

先列出网卡：

```bash
./build/soem_master/ecat_soem_master --list
```

只扫描和进入 Pre-Op，不交换过程数据：

```bash
sudo ./build/soem_master/ecat_soem_master -i eth1 --preop-only
```

以 2 ms 周期安全监视：

```bash
sudo ./build/soem_master/ecat_soem_master -i eth1 -c 2000
```

运行 10 秒：

```bash
sudo ./build/soem_master/ecat_soem_master -i eth1 -t 10
```

配置 MC02 的同步参数、启用 SYNC0，并把发送锁到 SYNC0 前 150 µs：

```bash
sudo ./build/soem_master/ecat_soem_master -i eth1 -c 500 --profile mc02 \
  --dc-lead-us 150 --cpu 5 --rt-priority 80 --lock-memory
```

需要周期性查看 PDO 原始字节时加 `--verbose`。

使用 React UI 时，先给主站授予一次网卡权限：

```bash
sudo setcap cap_net_raw,cap_net_admin,cap_sys_nice,cap_ipc_lock=eip \
  build/soem_master/ecat_soem_master
ECAT_IFACE=enP8p1s0 bash HostTools/run_react_linux.sh
```

浏览器打开 `http://127.0.0.1:8766/` 后，点击“启动主站”。页面会以所选周期
启动 `ecat_soem_master --profile mc02`，并通过 POSIX 共享内存交换状态和命令。
每次重新编译主站后都需要重新执行 `setcap`。

Linux Web UI 默认以 CPU5、`SCHED_FIFO` 优先级 80、锁定内存启动，并把发送
相位锁定在 SYNC0 前 150 µs。可以通过 `ECAT_CPU`、`ECAT_RT_PRIORITY` 和
`ECAT_DC_LEAD_US` 调整：

```bash
ECAT_CPU=5 ECAT_RT_PRIORITY=80 ECAT_DC_LEAD_US=150 \
  bash HostTools/run_react_linux.sh
```

设置 `ECAT_DC_LEAD_US=0` 可关闭主站发送相位锁定。

### DC 发送相位锁定

`--dc-lead-us <微秒>` 使用从站返回的 DC SysTime 调整主站的绝对发送时刻。
例如 `--dc-lead-us 150` 会把 2 kHz 发送锁在 SYNC0 前 150 µs：

```bash
sudo ./build/soem_master/ecat_soem_master -i enP8p1s0 \
  -c 500 --profile mc02 --dc-lead-us 150 \
  --cpu 5 --rt-priority 80 --lock-memory
```

实测 CPU0–4 全核满载 60 秒时，120,004 个周期 WKC 失败帧为 0，
PDI P50/P99 分别为 27/28 µs。测试汇总见
[`docs/ethercat_phase_lock_statistics.png`](../docs/ethercat_phase_lock_statistics.png)。

还可以将主站和网卡中断所在的 CPU 调频策略设为 `performance`：

```bash
for p in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do
  echo performance | sudo tee "$p" >/dev/null
done
```

调试完成后可改回 `schedutil`，避免设备长期高温。

### 延迟指标

- `RTT`：主站写时间戳到收到从站回显的总时间，包含 SYNC0 等待和主站调度。
- `PDI 相位`：从站输出映射到输入映射的时间，包含 SYNC0 相位等待。
- `MCU 处理`：PDI 中断执行时间，是纯从站计算开销。
- `最大间隔`：主站相邻两次发帧的最大间隔，是实时调度的首要指标。

因此不能把 `RTT − MCU 处理` 全部归因于 Linux 调度。需要结合 PDI 相位、
最小/最大 RTT 和最大间隔共同判断。

## 接线和设备注意

1. 主站网卡应专用于 EtherCAT，不要同时配置普通 TCP/IP 地址。
2. 从站应已完成 LAN9252 EEPROM 配置并运行本仓库固件。
3. 开始调试时先运行 `--preop-only`，确认 AL 状态正常后再进入 Safe-Op/Op。
4. 当前工具只做安全零输出和监视。真正控制 17 轴时，应在独立应用层按固件
   PDO 定义写入输出，并实现应用级急停、限位及看门狗。
5. Windows 下的现有 17 轴 UI 仍使用 `HostTools/src/ecat_live.c`；本目录是
   Linux 独立主站，两者不能同时操作同一网卡。

## 常见问题

`ecx_init failed`：确认使用的是实际 EtherCAT 网口名，并以 root 或具备
`CAP_NET_RAW` 的权限运行。

`no slaves found`：检查 EtherCAT 线与端口方向、从站供电、网卡对应关系，
并先用 `--preop-only` 排除 PDO 映射问题。

`SAFEOP failed`：查看固件 AL 状态码；常见原因是 PDO 映射大小、SM 配置或
看门狗不匹配。不要为了绕过错误而直接强制写入 OP。
