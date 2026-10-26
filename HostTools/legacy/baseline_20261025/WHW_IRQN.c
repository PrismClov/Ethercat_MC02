//
// Created by sri01 on 2025/10/11.
//

#include "WHW_IRQN.h"
#include "SEGGER_RTT.h"

#define Data2PC_NUM      216
#define Data2PCRMDA_NUM  200
#define Data2MCU_NUM     68
#define Data2MCURMUI_NUM 128

/* 供 J-Link 读取的数据监视变量 */
volatile uint8_t  dbgOutR = 0, dbgOutG = 0, dbgOutB = 0;
volatile uint32_t dbgOutCnt = 0;
volatile uint8_t  dbgIn[8];
volatile uint32_t dbgInCnt = 0;

void USER_TIM7_Callback()
{
    /* RTT 心跳 + 过程数据监视 */
    {
        static uint32_t rttHb = 0;
        static uint8_t  lastR = 0, lastG = 0, lastB = 0;
        extern uint32_t aaa;
        extern uint32_t ccc, ddd;
        uint8_t r = PDOChannel0x7000.R;
        uint8_t g = PDOChannel0x7000.G;
        uint8_t b = PDOChannel0x7000.B;

        /* 主站 -> 从站 输出数据：记录变化次数/当前值（打印放到心跳里） */
        if ((r != lastR) || (g != lastG) || (b != lastB))
        {
            lastR = r; lastG = g; lastB = b;
            dbgOutR = r; dbgOutG = g; dbgOutB = b;
            dbgOutCnt++;
        }

        if ((rttHb++ % 400u) == 0u)
        {
            /* 从站 -> 主站 输入数据：取 0x6000 对象前几个字节 */
            uint8_t *pi = (uint8_t *)&PDIChannel0x6000;
            int k;
            for (k = 0; k < 8; k++)
                dbgIn[k] = pi[2 + k];
            dbgInCnt++;

            SEGGER_RTT_printf(0, "hb=%u loop=%u OUT=%3u,%3u,%3u CHG=%u IN=%02X %02X %02X %02X\n",
                              (unsigned)rttHb, (unsigned)aaa,
                              (unsigned)r, (unsigned)g, (unsigned)b,
                              (unsigned)dbgOutCnt,
                              (unsigned)pi[2], (unsigned)pi[3],
                              (unsigned)pi[4], (unsigned)pi[5]);
        }
    }

    // CAN1A发送
    uint32_t ID0A = PDOChannel0x7000.C1ID1A | (PDOChannel0x7000.C1ID2A << 8);
    USER_FDCAN_AddMessageToTxFifoQ(0, ID0A, &PDOChannel0x7000.C11A);

    // CAN2A发送
    uint32_t ID1A = PDOChannel0x7000.C2ID1A | (PDOChannel0x7000.C2ID2A << 8);
    USER_FDCAN_AddMessageToTxFifoQ(1, ID1A, &PDOChannel0x7000.C21A);

    // CAN3发送
    uint32_t ID2A = PDOChannel0x7000.C3ID1A | (PDOChannel0x7000.C3ID2A << 8);
    USER_FDCAN_AddMessageToTxFifoQ(2, ID2A, &PDOChannel0x7000.C31A);

    // IMU读取
    BMI088_RawInfo_Update(&PDIChannel0x6000.AX1);

    // 状态指示灯
    WS2812_Ctrl(PDOChannel0x7000.R, PDOChannel0x7000.G, PDOChannel0x7000.B);
    //	WS2812_Ctrl(70, 70, 70);

    // IMU温控
    uint16_t Temp_Ctrl = PDOChannel0x7000.T1 | (PDOChannel0x7000.T2 << 8);
    TIM3->CCR4 = Temp_Ctrl;
    TIM3->CCR4 = 0;

    // CAN1B发送
    uint32_t ID0B = PDOChannel0x7000.C1ID1B | (PDOChannel0x7000.C1ID2B << 8);
    USER_FDCAN_AddMessageToTxFifoQ(0, ID0B, &PDOChannel0x7000.C11B);

    // CAN2B发送
    uint32_t ID1B = PDOChannel0x7000.C2ID1B | (PDOChannel0x7000.C2ID2B << 8);
    USER_FDCAN_AddMessageToTxFifoQ(1, ID1B, &PDOChannel0x7000.C21B);

    // CAN3B发送
    uint32_t ID2B = PDOChannel0x7000.C3ID1B | (PDOChannel0x7000.C3ID2B << 8);
    USER_FDCAN_AddMessageToTxFifoQ(2, ID2B, &PDOChannel0x7000.C31B);
}

uint32_t eee;
void APPL_InputMapping(UINT16* pData)
{
    uint8_t* pDIStart = (uint8_t*)(&PDIChannel0x6000) + sizeof(PDIChannel0x6000.u16SubIndex0);
    memcpy(pData, pDIStart, Data2PC_NUM);
    memset(&PDIChannel0x6000.AX1, 0, Data2PC_NUM);
    uint8_t* pDIRMDAStart = (uint8_t*)(&RMDAPDIChannel0x60F0) + sizeof(RMDAPDIChannel0x60F0.u16SubIndex0);
    /* pData 是 UINT16*，这里必须按字节偏移，否则会越界覆盖 SSC 的内部变量 */
    memcpy((uint8_t *)pData + Data2PC_NUM + 2, pDIRMDAStart, Data2PCRMDA_NUM);
    memset(&RMDAPDIChannel0x60F0.R1, 0, Data2PCRMDA_NUM);
    eee++;
}

void APPL_OutputMapping(UINT16* pData)
{
    memset(&PDOChannel0x7000.R, 0, Data2MCU_NUM);
    uint8_t* pDOStart = (uint8_t*)(&PDOChannel0x7000.u16SubIndex0) + sizeof(PDOChannel0x7000.u16SubIndex0);
    memcpy(pDOStart, pData, Data2MCU_NUM);
    memset(&RMUIPDOChannel0x7050.U1, 0, Data2MCURMUI_NUM);
    uint8_t* pDOSRMUIStart = (uint8_t*)(&RMUIPDOChannel0x7050.u16SubIndex0) + sizeof(RMUIPDOChannel0x7050.u16SubIndex0);
    /* 同样按字节偏移，避免越界 */
    memcpy(pDOSRMUIStart, (uint8_t *)pData + Data2MCU_NUM + 2, Data2MCURMUI_NUM);
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

        /* 官方 SSC 约定：INT_STS 由读取 AL Event(0x0220) 自动清除，
           不再手动写 0x58（写 1 清除会吞掉此间新到的事件）。
           若实测 IRQ 线卡死/风暴，再评估恢复手动清除。 */

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

void FDCAN1_RxFifo0RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    switch(Identifier)
    {
        case 0x201:
            PDIChannel0x6000.C1AID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1AID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1A1, Data, 8);
            break;

        case 0x202:
            PDIChannel0x6000.C1BID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1BID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1B1, Data, 8);
            break;

        case 0x203:
            PDIChannel0x6000.C1CID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1CID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1C1, Data, 8);
            break;

        case 0x204:
            PDIChannel0x6000.C1DID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1DID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1D1, Data, 8);
            break;

        case 0x205:
            PDIChannel0x6000.C1EID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1EID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1E1, Data, 8);
            break;

        case 0x206:
            PDIChannel0x6000.C1FID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C1FID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C1F1, Data, 8);
            break;
        default:
            break;
    }
}

void FDCAN3_RxFifo0RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    switch(Identifier)
    {
        case 0x201:
            PDIChannel0x6000.C3AID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3AID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3A1, Data, 8);
            break;

        case 0x202:
            PDIChannel0x6000.C3BID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3BID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3B1, Data, 8);
            break;

        case 0x203:
            PDIChannel0x6000.C3CID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3CID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3C1, Data, 8);
            break;

        case 0x204:
            PDIChannel0x6000.C3DID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3DID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3D1, Data, 8);
            break;

        case 0x205:
            PDIChannel0x6000.C3EID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3EID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3E1, Data, 8);
            break;

        case 0x206:
            PDIChannel0x6000.C3FID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C3FID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C3F1, Data, 8);
            break;
        default:
            break;
    }
}

void FDCAN2_RxFifo1RxHandler(uint32_t Identifier, uint8_t Data[8])
{
    switch(Identifier)
    {
        case 0x201:
            PDIChannel0x6000.C2AID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2AID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2A1, Data, 8);
            break;

        case 0x202:
            PDIChannel0x6000.C2BID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2BID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2B1, Data, 8);
            break;

        case 0x203:
            PDIChannel0x6000.C2CID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2CID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2C1, Data, 8);
            break;

        case 0x204:
            PDIChannel0x6000.C2DID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2DID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2D1, Data, 8);
            break;

        case 0x205:
            PDIChannel0x6000.C2EID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2EID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2E1, Data, 8);
            break;

        case 0x206:
            PDIChannel0x6000.C2FID1 = (uint16_t)Identifier & 0x00ff;
            PDIChannel0x6000.C2FID2 = (uint16_t)(Identifier >> 8) & 0x00ff;
            memcpy(&PDIChannel0x6000.C2F1, Data, 8);
            break;
        default:
            break;
    }
}

void USER_USART7_RxCallback(uint8_t* data, uint16_t Size)
{
    memcpy(&PDIChannel0x6000.VT1, data, Size);
}

void USER_USART1_RxCallback(uint8_t* data, uint16_t Size)
{
    memcpy(&RMDAPDIChannel0x60F0.R1, data, Size);
}
