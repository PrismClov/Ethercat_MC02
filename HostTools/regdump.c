/* Read ESC registers of the first slave via auto-increment (no config needed). */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;

static uint16 rd(uint16 reg)
{
   uint16 v = 0;
   ecx_APRD(&ctx.port, 0, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}

int main(int argc, char *argv[])
{
   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("init failed\n"); return 1; }

   printf("ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X ALEVENT=0x%04X\n",
          rd(0x0120), rd(0x0130), rd(0x0134), rd(0x0220));
   printf("ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X ALEVENT=0x%04X (again)\n",
          rd(0x0120), rd(0x0130), rd(0x0134), rd(0x0220));

   ecx_close(&ctx);
   return 0;
}
