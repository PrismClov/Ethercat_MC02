//
// Created by sri01 on 2025/10/11.
//

#include "WHW_IRQN.h"
#include "SEGGER_RTT.h"

/* ============ 17 轴 MIT PDO 布局 ============
   输出 196 B : 0x7000(176) + 0x7050(20)
   输入 416 B : 0x6000(204) + 0x60F0(212)
   全部小端；两段紧邻，没有 +2 空洞。 */
#define AXIS_COUNT            17u

#define OUT_TOTAL_LEN       196u
#define OUT_0x7000_LEN      176u
#define OUT_0x7050_LEN       20u
#define OUT_CTRL_OFF          0u
#define OUT_SEQ_OFF           1u
#define OUT_AXIS_OFF(n)     (4u + 10u * ((uint32_t)(n) - 1u))

#define IN_TOTAL_LEN        416u
#define IN_0x6000_LEN       204u
#define IN_0x60F0_LEN       212u
#define IN_AXIS_OFF(n)      (12u + 10u * ((uint32_t)(n) - 1u))

/* 控制字位定义 */
#define CTRL_ENABLE   0x01u
#define CTRL_ESTOP    0x02u
#define CTRL_HOMING   0x04u
#define CTRL_MODE_MASK 0xF8u

/* ===== 电机反馈模拟 =====
   没有实机时置 1：每个 1ms 往 0x6000 的 17 个反馈槽写入合成的
   位置/速度/状态，主站侧看到的就是"电机在动"。
   接上真实电机后改成 0（或删掉这段）。 */
#define MOTOR_SIM_ENABLE   1

#if MOTOR_SIM_ENABLE
/* 三角波：返回 -amp..+amp，周期 period(ms)，相位按轴错开 */
static int32_t Motor_SimTri(int32_t t, int32_t period, int32_t amp)
{
    int32_t ph = t % period;
    if (ph < 0) ph += period;
    if (ph < period / 2)
        return (ph * amp * 2) / period - amp;
    return amp - ((ph - period / 2) * amp * 2) / period;
}

static void Motor_Simulate(uint32_t tick_ms)
{
    uint32_t i;

    for (i = 0; i < AXIS_COUNT; i++)
    {
        uint32_t axis = i + 1u;
        int32_t  t   = (int32_t)tick_ms + (int32_t)(axis * 137u);   /* 相位错开 */
        int32_t  period = 2000;
        int32_t  amp = (int32_t)(2000u + axis * 200u);              /* 20.00~37.00 度 */
        int32_t  ph = t % period;
        int32_t  pos, vel;
        uint16_t st  = 0x0001u | 0x0020u;                           /* 使能 + 反馈有效 */
        uint8_t *slot = (uint8_t *)&PDIChannel0x6000.C1AID1
                      + (IN_AXIS_OFF(axis) - IN_AXIS_OFF(1u));

        if (ph < 0) ph += period;
        pos = Motor_SimTri(t, period, amp);
        /* 三角波斜率恒定，直接由相位给出速度，不用相邻帧差分
           （避免主站拷贝与 ISR 改写撞车造成的撕裂值） */
        vel = (ph < period / 2) ? (400 * amp / period) : -(400 * amp / period);

        if (vel > 32767)  vel = 32767;
        if (vel < -32768) vel = -32768;

        slot[0] = (uint8_t)(axis & 0xFF);          /* ID1 */
        slot[1] = 0;                               /* ID2 */
        slot[2] = (uint8_t)(pos & 0xFF);           /* 位置 int32，0.01 度 */
        slot[3] = (uint8_t)((pos >> 8) & 0xFF);
        slot[4] = (uint8_t)((pos >> 16) & 0xFF);
        slot[5] = (uint8_t)((pos >> 24) & 0xFF);
        slot[6] = (uint8_t)((int16_t)vel & 0xFF);  /* 速度 int16，0.1 度/秒 */
        slot[7] = (uint8_t)(((int16_t)vel >> 8) & 0xFF);
        slot[8] = (uint8_t)(st & 0xFF);            /* 状态字 */
        slot[9] = (uint8_t)(st >> 8);
    }
}
#endif

/* ============ 电机配置表 ============
   id = 0 表示该轴未配置，不发送任何帧。
   PMAX/VMAX/TMAX/KT 必须与实际电机一致，否则位置/力矩会被错误量化。 */
typedef struct
{
    uint16_t id;
    float    pmax;
    float    vmax;
    float    tmax;
    float    kt;
} MotorCfg;

static const MotorCfg gMotorCfg[AXIS_COUNT] =
{
    /* CAN1: 轴 1..7 */
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f},
    /* CAN2: 轴 8..14 */
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f},
    /* CAN3: 轴 15..17 */
    {0, 0.0f, 0.0f, 0.0f, 0.0f}, {0, 0.0f, 0.0f, 0.0f, 0.0f},
    {0, 0.0f, 0.0f, 0.0f, 0.0f},
};

/* 供 J-Link 读取的监视变量 */
volatile uint8_t  dbgCtrlWord = 0;
volatile uint32_t dbgSeq      = 0;
volatile uint32_t dbgTxCnt    = 0;
volatile uint32_t dbgRxCnt    = 0;
volatile uint8_t  dbgAx1[10];
volatile uint16_t dbgImuTemp  = 0;
/* PDO 读取失败（SPI 超时导致读回 0）的次数：此时本帧不发布，沿用上一帧 */
volatile uint32_t dbgPdoFailCnt = 0;

/* 1ms 节拍：给主循环低速任务（IMU / WS2812）限速用 */
volatile uint32_t u32DeviceTickMs = 0;

static uint16_t rd_u16(const uint8_t *p)
{
    return (uint16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static int16_t rd_i16(const uint8_t *p)
{
    return (int16_t)rd_u16(p);
}

static uint32_t rd_u32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void wr_u16(uint8_t *p, uint16_t v)
{
    p[0] = (uint8_t)(v & 0xFFu);
    p[1] = (uint8_t)(v >> 8);
}

static void wr_u32(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)(v & 0xFFu);
    p[1] = (uint8_t)((v >> 8) & 0xFFu);
    p[2] = (uint8_t)((v >> 16) & 0xFFu);
    p[3] = (uint8_t)((v >> 24) & 0xFFu);
}

/* ============ PDO 延迟探针 ============
   占用输入 0x6000 的 VT1..VT8（原 USART7 透传区）。
   若要用 USART7 透传，把 PDO_LATENCY_PROBE 置 0。
   VT1..VT4: 主站写入的时间戳原样回显
   VT5..VT6: PDI 中断执行时间（µs，纯 MCU，不含 Windows）
   VT7..VT8: 输出事件 -> 输入映射 的相位差（µs，含 SYNC0 等待）
   输出侧时间戳位置: 0x7050 U4..U7 = 绝对偏移 180 */
#define PDO_LATENCY_PROBE   1
#define OUT_STAMP_OFF      180u
#define IN_ECHO_OFF        182u
#define IN_ISR_OFF         186u
#define IN_PHASE_OFF       188u

volatile uint32_t dbgEchoStamp = 0;
volatile uint16_t dbgPdiIsrUs  = 0;
volatile uint16_t dbgPdoPhaseUs = 0;

#if PDO_LATENCY_PROBE
static volatile uint32_t s_outCyc   = 0;
static volatile uint8_t  s_outValid = 0;

static uint32_t dwt_to_us(uint32_t cycles)
{
    uint32_t per_us = SystemCoreClock / 1000000u;
    return per_us ? (cycles / per_us) : 0u;
}
#endif

/* 线性量化：x -> [0, 2^bits-1] */
static uint16_t float_to_uint(float x, float x_min, float x_max, uint8_t bits)
{
    float span = x_max - x_min;
    if (x < x_min) x = x_min;
    if (x > x_max) x = x_max;
    if (span <= 0.0f) return 0;
    return (uint16_t)((x - x_min) * (float)((1u << bits) - 1u) / span);
}

/* 轴号(1..17) -> CAN 通道(0..2)，未使用返回 0xFF */
static uint8_t Motor_BusOf(uint32_t axis)
{
    if (axis <= 7u)  return 0;
    if (axis <= 14u) return 1;
    if (axis <= 17u) return 2;
    return 0xFF;
}

/* 单个轴的 MIT 帧打包并发送（规格 5.1） */
static void Motor_SendAxis(uint32_t axis)
{
    const MotorCfg *m = &gMotorCfg[axis - 1u];
    const uint8_t *c;
    float pos_rad, vel_rad, tor_nm, kp, kd;
    uint16_t pos_u, vel_u, tor_u, kp_u, kd_u;
    uint8_t d[8];
    uint8_t bus;

    if (m->id == 0u) return;                 /* 未配置 */
    bus = Motor_BusOf(axis);
    if (bus == 0xFFu) return;

    c = (const uint8_t *)&PDOChannel0x7000 + OUT_AXIS_OFF(axis);

    pos_rad = (float)rd_i16(c + 0) * 0.01f * 0.0174532925f;
    vel_rad = (float)rd_i16(c + 2) * 0.1f  * 0.0174532925f;
    tor_nm  = (float)rd_i16(c + 4) * 0.01f * m->kt;
    kp      = (float)rd_u16(c + 6);
    kd      = (float)rd_u16(c + 8) * 0.01f;

    /* 急停：零力矩、零增益，位置保持上一周期命令 */
    if (dbgCtrlWord & CTRL_ESTOP)
    {
        tor_nm = 0.0f;
        kp = 0.0f;
        kd = 0.0f;
    }

    if (kp > 500.0f) kp = 500.0f;
    if (kd > 5.0f)   kd = 5.0f;

    pos_u = float_to_uint(pos_rad, -m->pmax, m->pmax, 16);
    vel_u = float_to_uint(vel_rad, -m->vmax, m->vmax, 12);
    tor_u = float_to_uint(tor_nm,  -m->tmax, m->tmax, 12);
    kp_u  = (uint16_t)(kp * 4095.0f / 500.0f + 0.5f);
    kd_u  = (uint16_t)(kd * 4095.0f / 5.0f + 0.5f);

    d[0] = (uint8_t)(pos_u >> 8);
    d[1] = (uint8_t)(pos_u & 0xFF);
    d[2] = (uint8_t)(vel_u >> 4);
    d[3] = (uint8_t)(((vel_u & 0x0F) << 4) | ((kp_u >> 8) & 0x0F));
    d[4] = (uint8_t)(kp_u & 0xFF);
    d[5] = (uint8_t)(kd_u >> 4);
    d[6] = (uint8_t)(((kd_u & 0x0F) << 4) | ((tor_u >> 8) & 0x0F));
    d[7] = (uint8_t)(tor_u & 0xFF);

    USER_FDCAN_AddMessageToTxFifoQ(bus, m->id, d);
    dbgTxCnt++;
}

void USER_TIM7_Callback()
{
    uint32_t n;

    u32DeviceTickMs++;

    for (n = 1u; n <= AXIS_COUNT; n++)
        Motor_SendAxis(n);

#if MOTOR_SIM_ENABLE
    Motor_Simulate(u32DeviceTickMs);
#endif

    dbgSeq = (uint32_t)((uint8_t *)&PDOChannel0x7000)[OUT_SEQ_OFF]
           | ((uint32_t)((uint8_t *)&PDOChannel0x7000)[OUT_SEQ_OFF + 1u] << 8)
           | ((uint32_t)((uint8_t *)&PDOChannel0x7000)[OUT_SEQ_OFF + 2u] << 16);
}

/* 从 TIM7 中断里移出来的低速外设任务（阻塞式 SPI），在主循环调用 */
void APPL_DeviceTask(void)
{
    static uint32_t imuTick = 0;
    static uint32_t ledTick = 0;
    uint32_t now = u32DeviceTickMs;

    if ((uint32_t)(now - imuTick) >= 1u)
    {
        /* 驱动写 14 B：accel(0..5) + gyro(6..11) + 温度(12..13)。
           PDO 里 IMU 只留 12 B，温度不能直接写进 0x6000（会盖掉第 1 轴槽）。 */
        static uint8_t imuBuf[14];
        imuTick = now;
        BMI088_RawInfo_Update(imuBuf);
        memcpy(&PDIChannel0x6000.AX1, imuBuf, 12);
        dbgImuTemp = (uint16_t)((uint16_t)imuBuf[12] | ((uint16_t)imuBuf[13] << 8));
    }

    /* 指示灯：U20 bit0=1 时由主站用 U1/U2/U3 (RGB) 控制；
       否则回落到状态色（使能=绿，急停=红，未使能=灭）。 */
    if ((uint32_t)(now - ledTick) >= 20u)
    {
        ledTick = now;
        if (RMUIPDOChannel0x7050.U20 & 0x01u)
            WS2812_Ctrl(RMUIPDOChannel0x7050.U1,
                        RMUIPDOChannel0x7050.U2,
                        RMUIPDOChannel0x7050.U3);
        else if (dbgCtrlWord & CTRL_ESTOP)
            WS2812_Ctrl(60, 0, 0);
        else if (dbgCtrlWord & CTRL_ENABLE)
            WS2812_Ctrl(0, 60, 0);
        else
            WS2812_Ctrl(0, 0, 0);
    }
}

uint32_t eee;

void APPL_InputMapping(UINT16* pData)
{
    /* 上一帧成功的数据：SPI 偶发 RXP 超时时读回全 0，
       直接发出去主站就会看到"数据全 0"，所以这里用它兜底。 */
    static uint8_t lastGood[IN_TOTAL_LEN];
    extern volatile uint32_t spiTimeoutCnt;
    uint32_t t0 = spiTimeoutCnt;
    uint8_t *d = (uint8_t *)pData;
#if PDO_LATENCY_PROBE
    uint32_t now_cyc = DWT->CYCCNT;
    uint32_t phase_us = s_outValid ? dwt_to_us(now_cyc - s_outCyc) : 0u;
    if (phase_us > 0xFFFFu) phase_us = 0xFFFFu;
#endif

    /* 0x6000: 204 B，紧邻其后是 0x60F0 的 212 B，共 416 B */
    memcpy(d, (uint8_t *)&PDIChannel0x6000 + sizeof(PDIChannel0x6000.u16SubIndex0), IN_0x6000_LEN);

    memcpy(d + IN_0x6000_LEN,
           (uint8_t *)&RMDAPDIChannel0x60F0 + sizeof(RMDAPDIChannel0x60F0.u16SubIndex0),
           IN_0x60F0_LEN);

    /* 这里**不能**清空记录。
       数据生产者是 1 kHz（TIM7 的 CAN 反馈 / 模拟）和主循环（IMU），
       而本函数每个 SYNC0 都会执行；SYNC0 快于 1 kHz 时（2 kHz / 3 kHz），
       清空后还没等到新数据就发出去了，主站会看到全 0 的帧。
       改为保持上一次写入值：PDO 重复上一采样，符合 1 kHz 数据源的实际语义。 */

    if (spiTimeoutCnt != t0)
    {
        /* 本帧的 ESC 读取失败：丢掉这次结果，继续发上一帧有效数据 */
        memcpy(d, lastGood, IN_TOTAL_LEN);
        dbgPdoFailCnt++;
    }
    else
    {
        memcpy(lastGood, d, IN_TOTAL_LEN);
    }

#if PDO_LATENCY_PROBE
    /* 这几个字段与 SPI 读回无关，永远用本地值覆盖 */
    wr_u32(d + IN_ECHO_OFF, dbgEchoStamp);
    wr_u16(d + IN_ISR_OFF, dbgPdiIsrUs);
    wr_u16(d + IN_PHASE_OFF, (uint16_t)phase_us);
    dbgPdoPhaseUs = (uint16_t)phase_us;
#endif

    eee++;
}

void APPL_OutputMapping(UINT16* pData)
{
    uint8_t *s = (uint8_t *)pData;

    memcpy((uint8_t *)&PDOChannel0x7000 + sizeof(PDOChannel0x7000.u16SubIndex0), s, OUT_0x7000_LEN);
    memcpy((uint8_t *)&RMUIPDOChannel0x7050 + sizeof(RMUIPDOChannel0x7050.u16SubIndex0),
           s + OUT_0x7000_LEN, OUT_0x7050_LEN);

    dbgCtrlWord = s[OUT_CTRL_OFF];

#if PDO_LATENCY_PROBE
    dbgEchoStamp = rd_u32(s + OUT_STAMP_OFF);
    s_outCyc = DWT->CYCCNT;
    s_outValid = 1;
#endif
}

void APPL_Application(void) {}

/**
 * ESC related PDI_IRQ, SYNC0, SYNC1 interrupt callback
 * and others interrupt callback can be add to here
 */
uint32_t ccc;
void USER_TIM6_Callback()
{
#ifdef LAN9252
    ECAT_CheckTimer();
    ccc++;
#endif
}

uint32_t ddd;

/* ---- PD14 IRQ 纯软件"示波器"（DWT 周期计数） ---- */
volatile uint32_t dbgIrqCnt = 0;
volatile uint32_t dbgLastCycle = 0;
volatile uint32_t dbgDeltaMin = 0xFFFFFFFFu, dbgDeltaMax = 0, dbgDeltaLast = 0;
volatile uint32_t dbgLevelLow = 0, dbgLevelHigh = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /** handler PDI_IRQ interrupt */
    if(PDI_IRQ_Pin == GPIO_Pin)
    {
#ifdef LAN9252
        uint32_t now = DWT->CYCCNT;
        uint32_t lvl = HAL_GPIO_ReadPin(PDI_IRQ_GPIO_Port, PDI_IRQ_Pin);

        if (dbgIrqCnt > 0)
        {
            uint32_t d = now - dbgLastCycle;
            dbgDeltaLast = d;
            if (d < dbgDeltaMin) dbgDeltaMin = d;
            if (d > dbgDeltaMax) dbgDeltaMax = d;
        }
        dbgLastCycle = now;
        if (lvl == GPIO_PIN_RESET) dbgLevelLow++; else dbgLevelHigh++;
        dbgIrqCnt++;

#if PDO_LATENCY_PROBE
        {
            uint32_t isr0 = DWT->CYCCNT;
            PDI_Isr();
            {
                uint32_t us = dwt_to_us(DWT->CYCCNT - isr0);
                dbgPdiIsrUs = (us > 0xFFFFu) ? 0xFFFFu : (uint16_t)us;
            }
        }
#else
        PDI_Isr();
#endif

        ddd++;
#endif
    }
    /** handler SYNC0 interrupt */
    if(sync0_Pin == GPIO_Pin)
    {
#ifdef LAN9252
        DISABLE_ESC_INT();
        Sync0_Isr();
        ENABLE_ESC_INT();
#endif
    }
    /** handler SYNC1 interrupt */
    if(sync1_Pin == GPIO_Pin)
    {
#ifdef LAN9252
        DISABLE_ESC_INT();
        Sync1_Isr();
        ENABLE_ESC_INT();
#endif
    }
}

/* 电机反馈（达妙 MIT 8 字节）：
   D0=ID, D1=ERR<<4|pos[15:12], D2=pos[11:4], D3=pos[3:0]<<4|vel[11:8],
   D4=vel[7:0], D5=tor[11:4], D6=tor[3:0]<<4|Tmos[11:8], D7=Tmos[7:0] */
static void Motor_OnFeedback(uint8_t bus, uint32_t id, const uint8_t *d)
{
    uint32_t i, axis = 0;
    uint16_t pos_u, vel_u, tor_u, status;
    float pos_rad, vel_rad;
    int32_t pos_centi_deg;
    uint8_t *slot;

    for (i = 0; i < AXIS_COUNT; i++)
    {
        if (gMotorCfg[i].id != 0u && Motor_BusOf(i + 1u) == bus && gMotorCfg[i].id == id)
        {
            axis = i + 1u;
            break;
        }
    }
    if (axis == 0u) return;

    pos_u = (uint16_t)(((uint16_t)(d[1] & 0x0Fu) << 12) | ((uint16_t)d[2] << 4) | ((uint16_t)d[3] >> 4));
    vel_u = (uint16_t)(((uint16_t)(d[3] & 0x0Fu) << 8) | d[4]);
    tor_u = (uint16_t)(((uint16_t)d[5] << 4) | ((uint16_t)d[6] >> 4));

    {
        const MotorCfg *m = &gMotorCfg[axis - 1u];
        pos_rad = (float)pos_u * (2.0f * m->pmax) / 65535.0f - m->pmax;
        vel_rad = (float)vel_u * (2.0f * m->vmax) / 4095.0f - m->vmax;
        (void)tor_u;
    }

    /* 弧度 -> 0.01 度 / 0.1 度每秒 */
    pos_centi_deg = (int32_t)(pos_rad * 57.2957795f * 100.0f);

    status = 0x0020u;                            /* bit5: 本周期反馈有效 */
    if (d[0] == id) status |= 0x0001u;           /* bit0: 使能（回读到自身 ID） */
    if ((d[1] >> 4) == 0x0Fu) status |= 0x0002u; /* bit1: 故障（ERR=0xF） */

    /* C1AID1 位于 PDO 偏移 12（轴 1 的槽首），其余轴按 10 B 步进 */
    slot = (uint8_t *)&PDIChannel0x6000.C1AID1 + (IN_AXIS_OFF(axis) - IN_AXIS_OFF(1u));
    slot[0] = (uint8_t)(id & 0xFF);
    slot[1] = (uint8_t)((id >> 8) & 0xFF);
    slot[2] = (uint8_t)(pos_centi_deg & 0xFF);
    slot[3] = (uint8_t)((pos_centi_deg >> 8) & 0xFF);
    slot[4] = (uint8_t)((pos_centi_deg >> 16) & 0xFF);
    slot[5] = (uint8_t)((pos_centi_deg >> 24) & 0xFF);
    slot[6] = (uint8_t)((int16_t)(vel_rad * 57.2957795f * 10.0f) & 0xFF);
    slot[7] = (uint8_t)(((int16_t)(vel_rad * 57.2957795f * 10.0f) >> 8) & 0xFF);
    slot[8] = (uint8_t)(status & 0xFF);
    slot[9] = (uint8_t)(status >> 8);

    dbgRxCnt++;
    if (axis == 1u) memcpy((void *)dbgAx1, slot, 10);
}

void FDCAN1_RxFifo0RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    Motor_OnFeedback(0, Identifier, Data);
}

void FDCAN2_RxFifo1RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    Motor_OnFeedback(1, Identifier, Data);
}

void FDCAN3_RxFifo0RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    Motor_OnFeedback(2, Identifier, Data);
}

void USER_USART7_RxCallback(uint8_t* data, uint16_t Size)
{
    if (Size > 21u) Size = 21u;
    memcpy(&PDIChannel0x6000.VT1, data, Size);
}

void USER_USART1_RxCallback(uint8_t* data, uint16_t Size)
{
    if (Size > IN_0x60F0_LEN) Size = IN_0x60F0_LEN;
    memcpy(&RMDAPDIChannel0x60F0.R1, data, Size);
}
