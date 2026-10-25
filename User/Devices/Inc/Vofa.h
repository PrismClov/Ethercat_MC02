/* USER CODE END Header */

#ifndef VOFA_H
#define VOFA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp_uart.h"
	
extern void USART_Vofa_Justfloat_Transmit(float SendValue1,float SendValue2,float SendValue3);

#endif