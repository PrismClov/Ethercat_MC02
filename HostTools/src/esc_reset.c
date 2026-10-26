/* 广播写 ESC 复位寄存器 0x0100 = 1（ESC self reset） */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;

int main(int argc, char *argv[])
{
   uint32 v;
   int w;
   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   v = htoel(0x00000001);
   w = ecx_BWR(&ctx.port, 0, 0x0100, 4, &v, EC_TIMEOUTRET);
   printf("BWR 0x0100=1 wkc=%d\n", w);
   osal_usleep(200000);
   ecx_close(&ctx);
   return 0;
}
