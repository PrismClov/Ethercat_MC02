//
// Created by sri01 on 2025/12/15.
//

#include "bsp_tim.h"

__weak void USER_TIM6_Callback() {}

__weak void USER_TIM7_Callback() {}

void BSP_Tim_Init(void)
{
    HAL_TIM_RegisterCallback(&htim6, HAL_TIM_PERIOD_ELAPSED_CB_ID, USER_TIM6_Callback);
    HAL_TIM_RegisterCallback(&htim7, HAL_TIM_PERIOD_ELAPSED_CB_ID, USER_TIM7_Callback);
    HAL_TIM_Base_Start_IT(&htim7);
}
