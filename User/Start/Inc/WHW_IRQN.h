//
// Created by sri01 on 2025/10/11.
//

#ifndef ECATDEMOMC02_WHW_IRQN_H
#define ECATDEMOMC02_WHW_IRQN_H

#include "ALL_Init.h"

/* 低速外设任务（IMU / WS2812，阻塞式 SPI）：必须在主循环调用，
   不能放在 TIM7 中断里，否则会侵占 SYNC0/PDI 实时中断的时间。 */
void APPL_DeviceTask(void);

#endif  // ECATDEMOMC02_WHW_IRQN_H
