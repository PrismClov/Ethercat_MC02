//
// Created by sri01 on 2025/10/11.
//

#include "ALL_Init.h"
#include "WHW_IRQN.h"

void ALL_Init()
{
    extern volatile UINT8 bHwInitTimeout;
    MCU_Init();
#ifdef LAN9252
    HW_Init();
    /* 硬件初始化失败（如 0x0204 应答超时）时不进入 MainInit，
       避免 bInitFinished 被错误置 1、把失败初始化当成成功。 */
    if (bHwInitTimeout == 0)
        MainInit();
#endif
    BMI088_Init();
}

uint32_t aaa;
void default_task()
{
#ifdef LAN9252
    /* 先跑 EtherCAT 主循环，再跑低速外设；
       外设里的阻塞 SPI 会被 SYNC0/PDI 中断抢占，不会影响实时性。 */
    MainLoop();
    APPL_DeviceTask();
    aaa++;
#endif
}
