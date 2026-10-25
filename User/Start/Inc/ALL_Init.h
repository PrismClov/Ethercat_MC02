//
// Created by sri01 on 2025/10/11.
//

#ifndef ECATDEMOMC02_ALL_INIT_H
#define ECATDEMOMC02_ALL_INIT_H


#include "bsp_can.h"
#include "bsp_mcu.h"
#include "bsp_pwm.h"
#include "ws2812.h"
#include "Bmi088.h"

#ifdef LAN9252
    #include "applInterface.h"
    #include "SSC_DeviceObjects.h"
#endif

void ALL_Init();
void default_task();

#endif  // ECATDEMOMC02_ALL_INIT_H
