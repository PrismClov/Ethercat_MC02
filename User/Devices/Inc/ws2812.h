#ifndef __WS2812_H__
#define __WS2812_H__

#include "main.h" 
#include "bsp_spi.h"
#include "bsp_dwt.h"
 
void RGB_Ctrl(uint8_t COLOR, float TIME, uint8_t Power);
void WS2812_Ctrl(uint8_t r, uint8_t g, uint8_t b);

#endif
