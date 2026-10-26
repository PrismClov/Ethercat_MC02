/* Read ESC communication info registers via auto-increment. */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;

static uint32_t rd32(uint16 reg)
{
   uint32_t v = 0;
   ecx_APRD(&ctx.port, 0, reg, 4, &v, EC_TIMEOUTRET);
   return etohl(v);
}

static uint16 rd16(uint16 reg)
{
   uint16 v = 0;
   ecx_APRD(&ctx.port, 0, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}

static uint8_t rd8(uint16 reg)
{
   uint8_t v = 0;
   ecx_APRD(&ctx.port, 0, reg, 1, &v, EC_TIMEOUTRET);
   return v;
}

int main(int argc, char *argv[])
{
   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("init failed\n"); return 1; }
   printf("0x0004 (comm info) = 0x%08X\n", rd32(0x0004));
   printf("0x0000 (type)      = 0x%08X\n", rd32(0x0000));
   printf("0x0054 (IRQ cfg)   = 0x%08X\n", rd32(0x0054));
   printf("0x0058 (IRQ status)= 0x%08X\n", rd32(0x0058));
   printf("0x005C (IRQ enable)= 0x%08X\n", rd32(0x005C));
   printf("0x0130 (AL status) = 0x%04X\n", rd16(0x0130));
   printf("0x0134 (AL code)   = 0x%04X\n", rd16(0x0134));
   printf("0x0204 (evt mask)  = 0x%04X\n", rd16(0x0204));
   printf("0x0220 (AL event)  = 0x%04X\n", rd16(0x0220));
   printf("0x0120 (AL ctl)    = 0x%04X\n", rd16(0x0120));
   printf("0x1100 (SM2 out)   = 0x%08X\n", rd32(0x1100));
   printf("SM2 3-buffer       = %08X %08X %08X\n",
          rd32(0x1100), rd32(0x11C4), rd32(0x1288));
   printf("0x1400 (SM3 in)    = 0x%08X\n", rd32(0x1400));
   printf("SM0: addr=0x%04X len=%u ctrl=0x%02X act=0x%02X\n",
          rd16(0x0800), rd16(0x0802), rd8(0x0804), rd8(0x0806));
   printf("SM2: addr=0x%04X len=%u ctrl=0x%02X act=0x%02X\n",
          rd16(0x0810), rd16(0x0812), rd8(0x0814), rd8(0x0816));
   printf("SM3: addr=0x%04X len=%u ctrl=0x%02X act=0x%02X\n",
          rd16(0x0818), rd16(0x081A), rd8(0x081C), rd8(0x081E));
   {
      int i;
      printf("FMMU0 @0x0600:");
      for (i = 0; i < 16; i++) printf(" %02X", rd8(0x0600 + i));
      printf("\nFMMU1 @0x0610:");
      for (i = 0; i < 16; i++) printf(" %02X", rd8(0x0610 + i));
      printf("\n");
   }
   ecx_close(&ctx);
   return 0;
}
