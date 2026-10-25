/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : bsp_spi.h
 * @brief          : The header file of bsp_spi.h
 * @author         : GrassFan Wang
 * @date           : 2025/01/22
 * @version        : v1.0
 ******************************************************************************
 * @attention      : Pay attention to extern the functions and structure
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_SPI_H
#define BSP_SPI_H

/* Include------------------------------------------------------------------*/
#include "spi.h"
#include "stm32h7xx.h"

#define WS2812_SPI_UNIT hspi6
extern SPI_HandleTypeDef WS2812_SPI_UNIT;

#define BMI088_SPI_UNIT hspi2
extern SPI_HandleTypeDef BMI088_SPI_UNIT;

/* Externs ------------------------------------------------------------------*/
extern uint8_t BMI088_Read_Write_Byte(uint8_t Tx_Data);
extern uint8_t WS2812B_Write_Byte(uint8_t* Tx_Data, uint32_t size);
extern uint8_t WR_CMD(uint8_t cmd);

/**
 * @brief  高效的SPI轮询收发函数 (针对STM32H7优化)
 * @param  hspi: SPI句柄
 * @param  pTxData: 发送缓冲区指针
 * @param  pRxData: 接收缓冲区指针
 * @param  Size: 数据长度 (字节)
 * @param  Timeout: 超时时间 (单位: 循环次数或毫秒)
 * @retval HAL_StatusTypeDef
 */
/* SPI 超时诊断/恢复：命令层在每条命令起点清标志，超时出口记 SR 与计数 */
extern volatile uint8_t  spiTimeoutFlag;
extern volatile uint32_t spiTimeoutCnt;
extern volatile uint32_t spiTimeoutSR;

static inline HAL_StatusTypeDef SPI_PollExchange_Fast(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData,
                                               uint32_t Size, uint32_t Timeout)
{
    /* 一次 SPI 传输必须原子完成：否则 ESC 的 PDI 中断会在传输中间插入
       自己的 SPI 访问，破坏总线状态（表现为 CTSIZE 卡住/RX 收不到）。
       用 PRIMASK 保存/恢复，既能保护主循环，也能安全地在 ISR 中调用。
       超时用纯循环计数，不依赖 SysTick（中断关闭时 HAL_GetTick 不走）。 */
    uint32_t primask = __get_PRIMASK();
    uint32_t txCount = Size;
    uint32_t rxCount = Size;
    uint32_t guard   = Timeout * 200u;   /* 约 1~2ms @640MHz，足够单字节事务 */

    __disable_irq();

    /* 1. 检查并等待SPI准备就绪 */
    if(hspi->State != HAL_SPI_STATE_READY)
    {
        __set_PRIMASK(primask);
        return HAL_BUSY;
    }

    /* 2. 禁止SPI并配置传输层 */
    __HAL_SPI_DISABLE(hspi);

    // 设置传输数据量 (TSIZE)
    MODIFY_REG(hspi->Instance->CR2, SPI_CR2_TSIZE, Size);

    /* 3. 开启SPI */
    __HAL_SPI_ENABLE(hspi);

    // 启动传输 (CSTART)
    SET_BIT(hspi->Instance->CR1, SPI_CR1_CSTART);

    /* 4. 循环处理数据 */
    while(txCount > 0 || rxCount > 0)
    {
        // --- 发送部分 ---
        // 检查TXP标志 (Transmit Packet Space Available)
        if((txCount > 0) && (hspi->Instance->SR & SPI_SR_TXP))
        {
            // 只写模式（SPIWrite）时 pTxData 可能为 NULL
            uint8_t tx = (pTxData != NULL) ? *pTxData++ : 0xFFu;
            // 直接操作TXDR寄存器，通过强制类型转换确保8位写入
            *(__IO uint8_t*)&hspi->Instance->TXDR = tx;
            txCount--;
        }

        // --- 接收部分 ---
        // 检查RXP标志 (Receive Packet Available)
        if((rxCount > 0) && (hspi->Instance->SR & SPI_SR_RXP))
        {
            // 直接读取RXDR寄存器；pRxData==NULL 时丢弃（SPIWrite 用法）
            uint8_t rx = *(__IO uint8_t*)&hspi->Instance->RXDR;
            if (pRxData != NULL)
                *pRxData++ = rx;
            rxCount--;
        }

        // --- 超时检查（不依赖 SysTick） ---
        if(--guard == 0)
        {
            spiTimeoutFlag = 1;
            spiTimeoutSR = hspi->Instance->SR;
            spiTimeoutCnt++;
            __HAL_SPI_DISABLE(hspi);
            __HAL_SPI_ENABLE(hspi);
            hspi->Instance->IFCR = 0xFFFFFFFFu;
            __set_PRIMASK(primask);
            return HAL_TIMEOUT;
        }
    }

    /* 5. 等待传输结束 (EOT) */
    guard = Timeout * 200u;
    while(!(hspi->Instance->SR & SPI_SR_EOT))
    {
        if(--guard == 0)
        {
            spiTimeoutFlag = 1;
            spiTimeoutSR = hspi->Instance->SR;
            spiTimeoutCnt++;
            __HAL_SPI_DISABLE(hspi);
            __HAL_SPI_ENABLE(hspi);
            hspi->Instance->IFCR = 0xFFFFFFFFu;
            __set_PRIMASK(primask);
            return HAL_TIMEOUT;
        }
    }

    // 清除标志位
    __HAL_SPI_CLEAR_EOTFLAG(hspi);
    __HAL_SPI_CLEAR_TXTFFLAG(hspi);

    __set_PRIMASK(primask);
    return HAL_OK;
}

#endif