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

    /* 指示灯：使能=绿，急停=红，未使能=灭 */
    if ((uint32_t)(now - ledTick) >= 20u)
    {
        ledTick = now;
        if (dbgCtrlWord & CTRL_ESTOP)
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
    uint8_t *d = (uint8_t *)pData;

    /* 0x6000: 204 B，紧邻其后是 0x60F0 的 212 B，共 416 B */
    memcpy(d, (uint8_t *)&PDIChannel0x6000 + sizeof(PDIChannel0x6000.u16SubIndex0), IN_0x6000_LEN);
    memset(&PDIChannel0x6000.AX1, 0, IN_0x6000_LEN);

    memcpy(d + IN_0x6000_LEN,
           (uint8_t *)&RMDAPDIChannel0x60F0 + sizeof(RMDAPDIChannel0x60F0.u16SubIndex0),
           IN_0x60F0_LEN);
    memset(&RMDAPDIChannel0x60F0.R1, 0, IN_0x60F0_LEN);
    eee++;
}

void APPL_OutputMapping(UINT16* pData)
{
    uint8_t *s = (uint8_t *)pData;

    memcpy((uint8_t *)&PDOChannel0x7000 + sizeof(PDOChannel0x7000.u16SubIndex0), s, OUT_0x7000_LEN);
    memcpy((uint8_t *)&RMUIPDOChannel0x7050 + sizeof(RMUIPDOChannel0x7050.u16SubIndex0),
           s + OUT_0x7000_LEN, OUT_0x7050_LEN);

    dbgCtrlWord = s[OUT_CTRL_OFF];
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

        PDI_Isr();

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
