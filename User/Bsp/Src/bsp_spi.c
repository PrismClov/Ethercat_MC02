/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : bsp_spi.c
 * @brief          : bsp spi functions
 * @author         : GrassFan Wang
 * @date           : 2025/01/22
 * @version        : v1.0
 ******************************************************************************
 * @attention      : None
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "bsp_spi.h"

/**
 * @brief returns the spi receive data after transmiting the specified data
 * @param Tx_Data: the specified data
 * @retval the spi receive data
 */
uint8_t BMI088_Read_Write_Byte(uint8_t Tx_Data)
{
    uint8_t Rx_Data = 0;

    HAL_SPI_TransmitReceive(&BMI088_SPI_UNIT, &Tx_Data, &Rx_Data, 1, 100);

    return Rx_Data;
}

uint8_t WS2812B_Write_Byte(uint8_t* Tx_Data, uint32_t size)
{
    return HAL_SPI_Transmit(&WS2812_SPI_UNIT, Tx_Data, size, 0xFFFF);
}

uint8_t WR_CMD(uint8_t cmd)
{
    uint8_t temp;

    HAL_SPI_TransmitReceive(&hspi3, &cmd, &temp, 1, 100);

    return temp;
}
