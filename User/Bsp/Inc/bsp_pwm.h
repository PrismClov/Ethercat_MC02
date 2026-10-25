/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_pwm.h
  * @brief          : The header file of bsp_pwm.h
  * @author         : GrassFan Wang
  * @date           : 2025/01/22
  * @version        : v1.0
  ******************************************************************************
  * @attention      : Pay attention to config the clock source of the advanced TIM
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_PWM_H
#define BSP_PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "tim.h"

/* Exported functions prototypes ---------------------------------------------*/
/**
  * @brief  Starts the PWM signal generation.
  */
	extern void BSP_PWM_IMU_Init(void);
	extern void BSP_PWM_Buzzer_Init(void);
	extern void BSP_PWM_CH1_Init(void);
	extern void BSP_PWM_CH2_Init(void);
	extern void BSP_PWM_CH3_Init(void);
	extern void BSP_PWM_CH4_Init(void);
/**
  * @brief  Set the BMI088 Heat_Power TIM Capture Compare Register value.
  */
	extern void Heat_Power_Control(uint16_t Compare);
	extern void Buzzer_Power_Control(uint16_t Compare);
	extern void PWM_CH1_Power_Control(uint16_t Compare);
	extern void PWM_CH2_Power_Control(uint16_t Compare);
	extern void PWM_CH3_Power_Control(uint16_t Compare);
	extern void PWM_CH4_Power_Control(uint16_t Compare);
#endif //BSP_PWM_H