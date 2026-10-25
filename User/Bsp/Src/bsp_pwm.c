/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_pwm.c
  * @brief          : bsp pwm functions 
  * @author         : Yan Yuanbin
  * @date           : 2023/04/27
  * @version        : v1.0
  ******************************************************************************
  * @attention      : Pay attention to config the clock source of the advanced TIM
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "bsp_pwm.h"
#include "tim.h"

/**
  * @brief  Starts the PWM signal generation.
  * @param  None
  * @retval None
  */
void BSP_PWM_IMU_Init(void)
{
	//Heat_Power_Tim Start
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}

void BSP_PWM_Buzzer_Init(void)
{
    HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_2);
}

void BSP_PWM_CH1_Init(void)
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void BSP_PWM_CH2_Init(void)
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

void BSP_PWM_CH3_Init(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void BSP_PWM_CH4_Init(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
}
//------------------------------------------------------------------------------

/**
  * @brief  Set the BMI088 Heat_Power TIM Capture Compare Register value.
  * @param  compare specifies the Capture Compare register new value.
  * @retval None
  */
void Heat_Power_Control(uint16_t Compare)
{
	htim3.Instance->CCR4 = Compare;
}

void Buzzer_Power_Control(uint16_t Compare)
{
	htim12.Instance->CCR2 = Compare;
}

void PWM_CH1_Power_Control(uint16_t Compare)
{
	htim1.Instance->CCR1 = Compare;
}

void PWM_CH2_Power_Control(uint16_t Compare)
{
	htim1.Instance->CCR3 = Compare;
}

void PWM_CH3_Power_Control(uint16_t Compare)
{
	htim2.Instance->CCR1 = Compare;
}

void PWM_CH4_Power_Control(uint16_t Compare)
{
	htim2.Instance->CCR3 = Compare;
}
//------------------------------------------------------------------------------
