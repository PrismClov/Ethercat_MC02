# EtherCAT LAN9252 从站稳定基线（2026-10-25）

## 来源与构建

- 工程（活跃副本）：`D:\ethercat\Horizon_EtherCAT-master\Slave\MC02_LAN9252\EcatDemoMC02`
- 构建：`cmake --build build-gcc`，随后
  `arm-none-eabi-objcopy -O ihex EcatDemoMC02.elf EcatDemoMC02.hex`
- 本目录内的 `EcatDemoMC02.hex` / `.elf` 即该次构建产物；同目录平铺了修改过的源码，便于回滚比对。
- 时钟：SYSCLK 640 MHz（PLLN=160，FLASH_LATENCY_2），HCLK 160 MHz；TIM6/TIM7 均 1 ms。
- 从站 SPI（hspi3）：10 MHz（PSC=8）。SYNC0 周期 2 ms、脉宽 50 µs。

## 本基线包含的修复

1. **主站**（ecat_ws2812_sm.c / ecat_ws2812_sm_mon.c）
   - PREOP 阶段、`ecx_config_map_group()` 之前写 `0x0420=0x03E8`；不再在 SAFE_OP 后写 0。
   - 状态迁移期间每 1 ms 连续发过程数据，非阻塞读 AL status；不再用阻塞 `ecx_statecheck`。
2. **从站 PDI/事件**
   - `PDI_Isr`：关中断 → 清 INT_STS(0x58) → 单次读 0x0220 → 开中断 → 分发。
   - `DISABLE/ENABLE_ESC_INT` 覆盖 PDI/SYNC0/SYNC1/TIM6，带嵌套计数；优先级 PDI 0 > SYNC 1 > Timer 2。
   - SYNC0/SYNC1 的 NVIC 使能（原来被注释）。
   - `ECAT_Main` 处理 `PROCESS_OUTPUT_EVENT`（原来读走事件却丢弃）。
3. **DC**
   - `configdc + dcsync0` 在 PREOP 阶段、`config_map_group` 之前完成。
   - `Sync0_Isr` 在 DC 模式下写 `0x0430` 触发过程数据看门狗。
   - `0x10F1:02`（sync error counter limit）由主站 DC 测试程序写 1000。
4. **SPI 驱动**
   - `SPIReadDWord`：8 字节批量（CMD+ADDRH+ADDRL+DUMMY+DATA0..3），一次 TSIZE/CSTART/CS。
   - `SPIWriteDWord`：7 字节批量（低字节优先）。
   - 整条命令 PRIMASK 原子；超时记录 SR/计数并复位 SPI 外设，整条命令最多重试 3 次。
   - `HW_Init` 的 0x0204 循环加 100000 次上限；超时置 `bHwInitTimeout`，`ALL_Init` 不再调用 `MainInit`，
     避免失败初始化被置为 `bInitFinished=1`。

## 验证结果

| 项目 | 结果 |
|---|---|
| SM-Sync 30 s | `ALSTAT=0x0008`、`ALCODE=0`、0 坏 ALSTAT/WKC、`WD=0x03E8` |
| DC 30 s | 进入 OP、`bad ALSTAT=0`、`bad WKC=0`、`missed 9→24`、`final ALSTAT=0x0008/ALCODE=0` |
| 主循环吞吐 | `aaa` ≈ 6,800 次/秒（优化前 DC 迁移期约 85 次/秒） |
| 初始化 | `bInitFinished=1`、`aaa` 持续增长 |

## 已知事项 / 后续

- `main.c`、`tim.c` 中部分中文注释因一次 PowerShell 编码往返出现乱码；代码数值与功能正确。
- 固件仍保留项目原有的调试输出（RTT 心跳、`ALC ctl=..`、`dbgEsmLog`、`ddd`），本轮临时诊断
  （EDGE/OPF/LOW/DCW/ddd_sync0/SPI TO 打印）已全部移除；`spiTimeoutCnt/SR` 仅保留为可读变量。
- DC 验证时主站以 1 ms 发帧、SYNC0 2 ms；`missed` 在 30 s 内仅增长 15 左右。
- 下一步：在 548 MHz（PLLN=137）下复测 SM-Sync 与 DC，回到"降频 + DC sync"目标。
