/* 读取任意 ESC 寄存器（16/32 位），用法: reg_read <ifname> <reg> [size] ... */
#include <stdio.h>
#include <stdlib.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 io_map[16];

int main(int argc, char *argv[])
{
   int i;
   uint16 adr;
   if (argc < 3) { printf("usage: %s <ifname> <reg> [size=2] ...\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;
   printf("cfgadr=0x%04X ALSTAT=0x%04X ALCODE=0x%04X\n",
          adr, ecx_FPRDw(&ctx.port, adr, 0x0130, EC_TIMEOUTRET),
          ecx_FPRDw(&ctx.port, adr, 0x0134, EC_TIMEOUTRET));
   for (i = 2; i < argc; i++)
   {
      uint16 reg = (uint16)strtoul(argv[i], NULL, 0);
      uint32 v32 = 0; uint16 v16 = 0;
      if (ecx_FPRD(&ctx.port, adr, reg, 4, &v32, EC_TIMEOUTRET) > 0)
         printf("0x%04X = 0x%08X\n", reg, (unsigned)etohl(v32));
      else
         printf("0x%04X = read failed\n", reg);
      (void)v16;
   }
   ecx_close(&ctx);
   return 0;
}
