# EtherCAT Slave Demo - EcatDemoMC02 (LAN9252)

这是一个基于达妙MC02开发板的EtherCAT从站演示项目，使用LAN9252 EtherCAT从站控制器 (ESC) 实现EtherCAT通信协议。

## 项目描述

EcatDemoMC02是Horizon EtherCAT Slave项目的演示应用，展示了如何在达妙MC02开发板上集成EtherCAT从站功能。该项目基于LAN9252 EtherCAT从站控制器和SSC (Slave Stack Code)协议栈，实现标准EtherCAT协议通信。

## 主要特性

- **EtherCAT从站通信**: 支持EtherCAT协议，实现实时工业以太网通信
- **多CAN接口**: 集成FDCAN1、FDCAN2、FDCAN3，支持高速CAN通信
- **丰富的外设**: ADC、SPI、UART、USB、定时器等
- **实时操作系统支持**: 基于FreeRTOS或裸机系统
- **调试接口**: 支持SWO、UART和USB CDC调试输出

## 硬件要求

### 开发板

- **开发板型号**: 达妙MC02 (Dami MC02)
- **微控制器**: STM32H723VGTx (LQFP100封装)
- **EtherCAT硬件模块**: LAN9252 EtherCAT从站控制器
- **EtherCAT PHY**: LAN9252集成，支持100Mbps Ethernet
- **电源**: 3.3V/5V供电
- **调试接口**: SWD/JTAG接口，USB OTG HS

### 外设配置

- **EtherCAT接口**: RJ45端口，连接到EtherCAT网络
- **CAN接口**: 3个FDCAN接口 (FDCAN1, FDCAN2, FDCAN3)，波特率1Mbps
- **SPI接口**: SPI2, SPI3, SPI6 (用于LAN9252通信)
- **UART接口**: UART7, USART1, USART2, USART3, USART10
  - USART1: 115200 baud (USB CDC桥接)
  - UART7/USART10: 921600 baud (高速调试)
  - USART2/USART3: 921600 baud (RS485模式)
- **USB**: USB OTG HS (CDC类，用于虚拟串口)
- **ADC**: ADC1和ADC3 (12位分辨率)
- **定时器**: TIM1, TIM2, TIM3, TIM6, TIM7, TIM12 (PWM输出)
- **DMA**: BDMA和DMA控制器 (数据传输加速)

### 时钟配置

- **外部晶振**: 24MHz HSE
- **系统时钟**: 640MHz (PLL倍频)
- **外设时钟**:
  - AHB: 160MHz
  - APB1/APB2/APB3/APB4: 80MHz/80MHz/80MHz/80MHz

## 软件要求

### 开发环境

- **操作系统**: Windows 10/11, Linux (Ubuntu 18.04+), macOS
- **IDE**: STM32CubeIDE, Keil MDK-ARM, VSCode
- **STM32CubeMX**: 6.12.0+
- **编译器**:
  - GCC ARM None EABI: 9.2.1+ (推荐)
  - ARM Compiler: 6.0+
- **构建工具**:
  - CMake: 3.16+
  - Make: 4.0+
- **调试工具**:
  - ST-Link V2/V3
  - J-Link (可选)
  - OpenOCD (可选)

### 依赖库

- **STM32Cube HAL**: STM32H7 HAL库 V1.11.2
- **EtherCAT Stack**: SSC EtherCAT Slave Stack Tool V5.11
- **中间件**:
  - CMSIS DSP: 数字信号处理库
  - SEGGER RTT: 实时传输库
  - STM32 USB Device Library: USB设备栈
- **其他**: FreeRTOS (如果使用RTOS版本)

### EtherCAT主站 (用于测试)

- TwinCAT 3
- SOEM (Simple Open EtherCAT Master)
- IgH EtherCAT Master

## 构建和运行

### 环境要求

- **编译器**: GCC ARM None EABI 9.2.1 或 ARM Compiler 6
- **构建工具**: CMake 3.16+
- **IDE**: VSCode + STM32CubeMX, 或 Keil MDK

### 环境设置

1. **安装工具链**:
   - 下载并安装 GCC ARM None EABI: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
   - 确保 `arm-none-eabi-gcc` 在系统PATH中

2. **安装CMake**:
   - 下载并安装CMake 3.16+ (https://cmake.org/download/)

3. **克隆项目**:
   ```bash
   git clone <repository-url>
   cd LAN9252/EcatDemoMC02
   ```

### 构建步骤

#### 方法1: 使用CMake + GCC (推荐)

1. **创建构建目录**:
   ```bash
   mkdir build
   cd build
   ```

2. **配置项目**:
   ```bash
   cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/gcc-arm-none-eabi.cmake -DCMAKE_BUILD_TYPE=Release
   ```

3. **构建项目**:
   ```bash
   make -j4
   ```

4. **生成文件**:
   - `EcatDemoMC02.elf`: ELF可执行文件
   - `EcatDemoMC02.hex`: Intel HEX文件
   - `EcatDemoMC02.bin`: 二进制文件

#### 方法2: 使用Keil MDK

1. **打开项目**:
   - 启动Keil MDK
   - File -> Open -> MDK-ARM/EcatDemoMC02.uvprojx

2. **选择目标**:
   - 在Project窗口中选择目标配置

3. **构建项目**:
   - Project -> Build target (F7)
   - 或 Project -> Rebuild all target files

#### 方法3: 使用STM32CubeIDE

1. **导入项目**:
   - File -> Import -> Existing Projects into Workspace
   - 选择项目根目录

2. **构建项目**:
   - Project -> Build Project

### 重要宏定义

项目中定义的关键宏 (在 CMakeLists.txt 中):
- `LAN9252`: 指定使用 LAN9252 ESC
- `USE_FULL_LL_DRIVER`: 使用完整的低层驱动
- `User_Debug`: 启用用户调试功能

### 烧录和运行

1. **连接调试器**:
   - 使用ST-Link连接到达妙MC02开发板的SWD接口
   - 确保开发板供电正常

2. **烧录固件**:
   - **使用STM32CubeProgrammer**:
     ```bash
     STM32_Programmer_CLI -c port=SWD -w build/EcatDemoMC02.hex
     ```
   - **使用OpenOCD**:
     ```bash
     openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c "program build/EcatDemoMC02.elf verify reset exit"
     ```
   - **使用Keil MDK**: 按Load按钮

3. **连接EtherCAT网络**:
   - 使用标准EtherCAT电缆连接开发板的EtherCAT端口到EtherCAT主站
   - 确保网络拓扑正确 (如果有多个从站)

4. **启动系统**:
   - 上电或复位开发板
   - 观察LED指示灯 (如果有)

5. **验证通信**:
   - 使用EtherCAT主站软件扫描网络
   - 检查从站是否被识别
   - 监控过程数据交换

## 项目结构

```
EcatDemoMC02/
├── CMakeLists.txt                 # 主 CMake 配置文件
├── CMakePresets.json             # CMake 预设配置
├── EcatDemoMC02.code-workspace    # VS Code 工作区配置
├── EcatDemoMC02.ioc              # STM32CubeMX 项目配置
├── README.md                     # 项目文档
├── startup_stm32h723xx.s         # STM32H7 启动文件
├── stm32h723vgtx_flash.ld        # 链接器脚本
├── .vscode/                      # VS Code 配置目录
├── Core/                         # STM32CubeMX 生成的核心代码
│   ├── Inc/                      # 核心头文件 (main.h, stm32h7xx_it.h 等)
│   └── Src/                      # 核心源文件 (main.c, stm32h7xx_it.c 等)
├── Drivers/                      # STM32 外设驱动库
│   ├── CMSIS/                    # ARM CMSIS 核心文件
│   │   ├── Include/              # CMSIS 头文件
│   │   └── Device/               # 设备特定文件
│   └── STM32H7xx_HAL_Driver/     # STM32H7 HAL 驱动
│       ├── Inc/                  # HAL 头文件
│       └── Src/                  # HAL 源文件
├── MDK-ARM/                      # Keil MDK 项目文件
│   ├── EcatDemoMC02.uvoptx       # MDK 项目选项
│   ├── EcatDemoMC02.uvprojx      # MDK 项目文件
│   ├── startup_stm32h723xx.s     # 启动文件
│   └── RTE/                      # RTE 配置
├── Middlewares/                  # 中间件库
│   ├── DSP_math/                 # CMSIS DSP 数学库
│   ├── SEGGER_RTT/               # SEGGER RTT 调试库
│   └── ST/                       # ST 中间件
│       └── STM32_USB_Device_Library/  # USB 设备库
├── USB_DEVICE/                   # USB 设备应用层代码
│   ├── App/                      # USB 应用代码
│   └── Target/                   # USB 目标代码
├── User/                         # 用户自定义代码
│   ├── Bsp/                      # 板级支持包
│   │   ├── Inc/                  # BSP 头文件 (ADC, CAN, GPIO等)
│   │   └── Src/                  # BSP 源文件
│   ├── Devices/                  # 外部设备驱动
│   │   ├── Inc/                  # 设备头文件
│   │   └── Src/                  # 设备源文件 (BMI088, Vofa, WS2812等)
│   └── EtherCAT/                 # EtherCAT 协议栈
│       ├── 9252_HW.c/h          # LAN9252 硬件接口驱动
│       ├── SPIDriver.c/h        # SPI 驱动
│       ├── applInterface.h      # 应用接口定义
│       ├── ecat_def.h           # SSC 配置定义 (版本 5.11)
│       ├── ecatappl.*           # EtherCAT 应用层
│       ├── ecatslv.*            # 从站协议栈核心
│       ├── mailbox.*            # 邮箱通信处理
│       ├── objdef.*             # 对象字典定义
│       ├── coeappl.*            # CoE 应用
│       ├── eoeappl.*            # EoE 应用
│       ├── foeappl.*            # FoE 应用
│       ├── emcy.*               # 紧急消息处理
│       └── sdoserv.*            # SDO 服务
└── User_Config/                  # 用户配置文件
    ├── daplink.cfg              # DAP-Link 配置
    ├── stlink.cfg               # ST-Link 配置
    └── desktop.ini              # Windows 文件夹配置
```

## EtherCAT 配置

### SSC 参数
- **SSC 版本**: 5.11
- **Vendor ID**: 0x000004D8
- **Product Code**: 0x00009252
- **Revision**: 0x00030111
- **Device Profile**: 0x00001389 (通用 I/O)

### 支持的功能
- [x] CoE (CANopen over EtherCAT)
- [x] EoE (Ethernet over EtherCAT)
- [x] FoE (File over EtherCAT)
- [x] SoE (Servo over EtherCAT) - 未启用
- [x] 分布式时钟 (DC)
- [x] 紧急消息
- [x] 诊断消息 - 未启用

### 过程数据
- **最大输入数据大小**: 432 字节
- **最大输出数据大小**: 207 字节
- **周期时间范围**: 100 μs 到 2 s

## 使用说明

### 硬件连接

1. 将 LAN9252 模块通过 SPI 接口连接到 达妙 MC02 板
2. 连接 EtherCAT 网络端口
3. 供电给开发板

### 软件配置

1. 下载固件到开发板
2. 配置 EtherCAT 主站识别从站
3. 设置 PDO 映射和对象字典参数
4. 启动 EtherCAT 通信

### 测试

- **使用TwinCAT**:
  - 创建EtherCAT项目
  - 扫描网络发现从站
  - 配置PDO映射
  - 运行PLC程序测试通信

- **使用SOEM**:
  - 编译和运行SOEM示例
  - 检查从站状态和数据交换

### 调试

- **USB CDC**: 串口调试 (115200 baud)
- **UART**: UART7/UART10 (921600 baud)
- **SEGGER RTT**: 实时调试输出 (通过J-Link或ST-Link)

项目集成了 SEGGER RTT 用于实时调试输出。可通过 J-Link 或 ST-Link 查看调试信息。

## 开发和定制

### 添加新的 PDO

1. 修改 `User/EtherCAT/objdef.c` 中的对象字典
2. 更新 PDO 映射配置
3. 实现相应的应用处理函数

### 硬件接口

LAN9252 的硬件接口实现在 `User/EtherCAT/9252_HW.c` 中，包括:
- SPI 通信
- 中断处理
- EEPROM 访问 (如果支持)

### BSP 组件

板级支持包位于 `User/Bsp/` 目录:
- `bsp_adc.*`: ADC 驱动
- `bsp_can.*`: CAN 总线驱动
- `bsp_gpio.*`: GPIO 控制
- `bsp_pwm.*`: PWM 输出
- `bsp_spi.*`: SPI 通信
- `bsp_tim.*`: 定时器驱动
- `bsp_uart.*`: UART 通信

## 故障排除

### 常见问题

1. **构建失败**:
   - 检查GCC ARM工具链是否正确安装
   - 确认CMake版本 >= 3.16
   - 检查路径中是否有空格

2. **烧录失败**:
   - 检查ST-Link连接
   - 确认开发板供电
   - 尝试重新连接调试器

3. **EtherCAT通信失败**:
   - 检查LAN9252 SPI连接
   - 验证EtherCAT主站配置
   - 检查从站固件版本和SSC参数

### 调试技巧

- 使用USB CDC串口监控启动日志
- 通过UART接口获取详细调试信息
- 使用EtherCAT诊断工具检查网络状态
- 检查SPI通信是否正常 (LAN9252初始化)

## EtherCAT Slave Stack

本项目使用LAN9252 EtherCAT从站控制器配合SSC (Slave Stack Code) EtherCAT Slave Stack Tool V5.11协议栈，实现EtherCAT通信。LAN9252提供了EtherCAT物理层和部分协议处理功能，SSC V5.11栈负责应用层协议实现。

### 主要功能

- **状态机**: Init, Pre-Operational, Safe-Operational, Operational
- **通信**: 过程数据交换 (PDO), 服务数据对象 (SDO)
- **同步**: 分布式时钟 (DC) 支持
- **诊断**: 错误计数和状态指示
- **硬件加速**: LAN9252提供EtherCAT帧处理加速

## 配置

项目使用STM32CubeMX配置硬件外设。可以通过修改 `EcatDemoMC02.ioc` 文件来调整引脚分配和外设配置。

## 许可证

本项目基于Apache License 2.0许可证开源。

EtherCAT技术受Beckhoff Automation GmbH的EtherCAT Technology商标保护。

## 贡献

欢迎提交Issue和Pull Request来改进项目。

### 开发指南

1. Fork本仓库
2. 创建功能分支: `git checkout -b feature/new-feature`
3. 提交更改: `git commit -am 'Add new feature'`
4. 推送分支: `git push origin feature/new-feature`
5. 创建Pull Request

## 联系方式

- **项目维护者**: [维护者姓名]
- **邮箱**: [联系邮箱]
- **GitHub**: [GitHub仓库URL]
- **文档**: [文档链接]

## 版本历史

- **v1.0.0**: 初始版本，支持基础EtherCAT从站功能
- **v1.1.0**: 添加FDCAN支持
- **v1.2.0**: 集成USB CDC调试接口

## 相关资源

- [EtherCAT官方网站](https://www.ethercat.org/)
- [STM32H7文档](https://www.st.com/en/microcontrollers-microprocessors/stm32h723-735.html)
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- [SSC EtherCAT Stack](https://www.ethercat.org/en/products.html)
- [LAN9252 数据手册](https://www.microchip.com/wwwproducts/en/LAN9252)