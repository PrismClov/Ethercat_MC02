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
extern volatile uint8_t  spiTimeoutStage;
extern volatile uint32_t spiBusyCnt;

/* 超时阶段标识：用于区分 TXP / RXP / EOT / TX FIFO 填充 */
#define SPI_STAGE_NONE   0u
#define SPI_STAGE_TXP    1u
#define SPI_STAGE_RXP    2u
#define SPI_STAGE_EOT    3u
#define SPI_STAGE_TXDR   4u
#define SPI_STAGE_BUSY   5u

/* 超时参数单位：微秒（不是循环次数）。
   单条命令（≤8 字节）走 SPI_TMO_US_CMD；PRAM 批量按字节数放大。 */
#define SPI_TMO_US_CMD      200u
#define SPI_TMO_US_BULK(n)  (500u + (uint32_t)(n))

static inline HAL_StatusTypeDef SPI_PollExchange_Fast(SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t* pRxData,
                                               uint32_t Size, uint32_t Timeout)
{
    /* 一次 SPI 传输必须原子完成：否则 ESC 的 PDI 中断会在传输中间插入
       自己的 SPI 访问，破坏总线状态（表现为 CTSIZE 卡住/RX 收不到）。
       用 PRIMASK 保存/恢复，既能保护主循环，也能安全地在 ISR 中调用。

       超时用 DWT->CYCCNT 的绝对截止时间（48 位以上余量，且差值比较对
       32 位回绕安全），单位是微秒。此前用"循环次数"做 guard：RXP 等不到
       数据时虽然最终会退出，但 200000 次迭代在中断里是几十毫秒，表现为
       主循环停摆、SM 事件丢失，等同于卡死。

       数据阶段不再阻塞等待单个标志，而是每轮同时推进 TX/RX，用截止时间
       统一兜底；这样 RX FIFO 每轮都被清空，不会出现 RX 满导致 TXP
       永远不来的死等。 */
    HAL_StatusTypeDef status = HAL_OK;
    SPI_TypeDef *spi = hspi->Instance;
    uint32_t primask = __get_PRIMASK();
    uint32_t txCount = Size;
    uint32_t rxCount = Size;
    uint32_t start, limit;
    uint8_t  stage = SPI_STAGE_NONE;

    __disable_irq();

    if (Size == 0u)
        goto cleanup;

    /* 1. 检查并等待SPI准备就绪 */
    if(hspi->State != HAL_SPI_STATE_READY)
    {
        spiBusyCnt++;
        stage  = SPI_STAGE_BUSY;
        status = HAL_BUSY;
        goto cleanup;
    }

    /* DWT 周期计数器做时基（main 里已使能，这里做防呆） */
    if((DWT->CTRL & DWT_CTRL_CYCCNTENA_Msk) == 0u)
    {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CYCCNT = 0u;
        DWT->CTRL  |= DWT_CTRL_CYCCNTENA_Msk;
    }

    /* 微秒 -> 周期；SystemCoreClock 由 SystemClock_Config 更新 */
    limit = Timeout * (SystemCoreClock / 1000000u);
    if(limit < 2000u)
        limit = 2000u;

    /* 2. 禁止SPI并配置传输层 */
    __HAL_SPI_DISABLE(hspi);

    // 设置传输数据量 (TSIZE)
    MODIFY_REG(spi->CR2, SPI_CR2_TSIZE, Size);

    /* 3. 开启SPI */
    __HAL_SPI_ENABLE(hspi);

    // 启动传输 (CSTART)
    SET_BIT(spi->CR1, SPI_CR1_CSTART);

    /* 4. 数据阶段：非阻塞推进 TX/RX，统一用绝对截止时间兜底 */
    start = DWT->CYCCNT;
    while(txCount > 0 || rxCount > 0)
    {
        uint32_t sr = spi->SR;

        if((txCount > 0) && (sr & SPI_SR_TXP))
        {
            // 只写模式（SPIWrite）时 pTxData 可能为 NULL
            uint8_t tx = (pTxData != NULL) ? *pTxData++ : 0xFFu;
            // 直接操作TXDR寄存器，通过强制类型转换确保8位写入
            *(__IO uint8_t*)&spi->TXDR = tx;
            txCount--;
        }

        if((rxCount > 0) && (sr & SPI_SR_RXP))
        {
            // 直接读取RXDR寄存器；pRxData==NULL 时丢弃（SPIWrite 用法）
            uint8_t rx = *(__IO uint8_t*)&spi->RXDR;
            if (pRxData != NULL)
                *pRxData++ = rx;
            rxCount--;
        }

        /* 截止时间检查：报出真正卡住的方向 */
        if((uint32_t)(DWT->CYCCNT - start) >= limit)
        {
            stage  = (txCount > 0 && !(spi->SR & SPI_SR_TXP)) ? SPI_STAGE_TXP : SPI_STAGE_RXP;
            status = HAL_TIMEOUT;
            goto cleanup;
        }
    }

    /* 5. 等待传输结束 (EOT) */
    start = DWT->CYCCNT;
    while(!(spi->SR & SPI_SR_EOT))
    {
        if((uint32_t)(DWT->CYCCNT - start) >= limit)
        {
            stage  = SPI_STAGE_EOT;
            status = HAL_TIMEOUT;
            goto cleanup;
        }
    }

    // 清除标志位
    __HAL_SPI_CLEAR_EOTFLAG(hspi);
    __HAL_SPI_CLEAR_TXTFFLAG(hspi);

cleanup:
    if (status != HAL_OK)
    {
        /* 统一错误出口：只记录现场并做最小复位，退出后由命令层决定重试。
           不在 ISR 里反复 enable/disable 或重配置，避免拉长中断时间。 */
        spiTimeoutStage = stage;
        spiTimeoutSR    = spi->SR;
        spiTimeoutCnt++;
        spiTimeoutFlag  = 1;

        CLEAR_BIT(spi->CR1, SPI_CR1_CSTART);
        __HAL_SPI_DISABLE(hspi);
        spi->IFCR = 0xFFFFFFFFu;
        __HAL_SPI_ENABLE(hspi);
    }

    /* 所有退出路径（HAL_OK / HAL_BUSY / HAL_TIMEOUT）都在这里恢复 */
    __set_PRIMASK(primask);
    return status;
}

#endif
