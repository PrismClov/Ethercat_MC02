#include "ws2812.h"

/* 与官方例程 CtrBoard-H7_WS2812 一致：
   0xC0 >>1 = 0x60（2 个高电平 = T0H 0.33us @6MHz）
   0xF0 >>1 = 0x78（4 个高电平 = T1H 0.67us @6MHz）
   注意 0xA0/0xC8 右移后会变成两段不连续脉冲，波形是错的。 */
#define WS2812_LowLevel    0xC0
#define WS2812_HighLevel   0xF0

/* 复位脉冲：100 个 0 字节（约 133us @6MHz），一次发完即可 */
#define WS2812_RESET_BYTES        100u
/* 等待 SPI 空闲的上限：原来是无超时自旋，SPI 异常会永久卡住调用者 */
#define WS2812_READY_TIMEOUT_US   5000u

void WS2812_Ctrl(uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t txbuf[24];
    static const uint8_t resetbuf[WS2812_RESET_BYTES] = {0};
    uint8_t res = 0;
    for (int i = 0; i < 8; i++)
    {
        txbuf[7-i]  = (((g>>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
        txbuf[15-i] = (((r>>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
        txbuf[23-i] = (((b>>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
    }
	WS2812B_Write_Byte(&res, 0);

    {
        uint32_t limit = WS2812_READY_TIMEOUT_US * (SystemCoreClock / 1000000u);
        uint32_t start = DWT->CYCCNT;
        while (WS2812_SPI_UNIT.State != HAL_SPI_STATE_READY)
        {
            if ((uint32_t)(DWT->CYCCNT - start) >= limit)
                return;
        }
    }

	WS2812B_Write_Byte(txbuf, 24);
    /* 原来逐个发 100 次单字节事务，这里合并成一笔 */
    WS2812B_Write_Byte((uint8_t *)resetbuf, WS2812_RESET_BYTES);
}

void V0_V1(int8_t *tmp)
{
    if(*tmp != 0)   *tmp = 1;
    if(*tmp == 0)   *tmp = 0;
}

void RGB_Ctrl(uint8_t COLOR, float TIME, uint8_t Power)
{
    float TIME_NOW = DWT_GetTimeline_ms();
    static float TIME_LAST = 0;

    static int8_t BIT = 0;

    static uint8_t LED_CONFIG[7][3] ={
        {1, 0, 0},    // RED
        {0, 1, 0},    // GREEN
        {0, 0, 1},    // BLUE
        {1, 1, 0},    // YELLOW
        {1, 0, 1},    // PURPLE
        {0, 1, 1},    // CYAN
        {1, 1, 1},    // write
    };
	
    if ((TIME_NOW - TIME_LAST) > TIME)
    {
        TIME_LAST = TIME_NOW;
		BIT = !BIT;
        V0_V1(&BIT);
    }

    WS2812_Ctrl(LED_CONFIG[COLOR][0]*Power*BIT,
                LED_CONFIG[COLOR][1]*Power*BIT,
                LED_CONFIG[COLOR][2]*Power*BIT);
}
