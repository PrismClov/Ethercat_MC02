/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : bsp_mcu.c
 * @brief          : MCU peripheral initialization functions
 * @author         : GrassFan Wang
 * @date           : 2025/01/22
 * @version        : v1.0
 ******************************************************************************
 * @attention      : none
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "bsp_mcu.h"
#include "bsp_adc.h"
#include "bsp_can.h"
#include "bsp_dwt.h"
#include "bsp_gpio.h"
#include "bsp_pwm.h"
#include "bsp_tim.h"
#include "bsp_uart.h"
#include "stm32h7xx_hal_tim.h"
#include "usb_device.h"
/**
 * @brief Initializes the MCU.
 */
void MCU_Init(void)
{
    /* ----------------------- BSP Init ----------------------- */
    //    BSP_PWM_IMU_Init();
    BSP_PWM_Buzzer_Init();
    BSP_PWM_CH1_Init();
    BSP_PWM_CH2_Init();
    BSP_PWM_CH3_Init();
    BSP_PWM_CH4_Init();
    BSP_GPIO_Init();
    BSP_FDCAN_Init();
    BSP_USART_Init();
    BSP_ADC_Init();
    BSP_Tim_Init();
    MX_USB_DEVICE_Init();
}
//------------------------------------------------------------------------------
