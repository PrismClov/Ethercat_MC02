/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_uart.h
  * @brief          : The header file of bsp_can.h 
  * @author         : GrassFan Wang
  * @date           : 2025/01/22
  * @version        : v1.0
  ******************************************************************************
  * @attention      : Pay attention to extern the functions and structure
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef BSP_UART_H
#define BSP_UART_H

/* Include------------------------------------------------------------------*/
#include "stm32h7xx.h"
	
extern UART_HandleTypeDef huart7;

extern void BSP_USART_Init(void);
	   		 
#endif