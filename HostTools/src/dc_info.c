/* 查询从站/主站的 DC 能力与当前寄存器状态（不改变状态） */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;

static uint16 rd16(uint16 adr, uint16 reg)
{
   uint16 v = 0;
   ecx_FPRD(&ctx.port, adr, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}
static uint32 rd32(uint16 adr, uint16 reg)
{
   uint32 v = 0;
   ecx_FPRD(&ctx.port, adr, reg, 4, &v, EC_TIMEOUTRET);
   return etohl(v);
}

int main(int argc, char *argv[])
{
   int i;
   uint16 adr;

   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   printf("slavecount=%d\n", ctx.slavecount);
   for (i = 1; i <= ctx.slavecount; i++)
   {
      printf("slave%d cfgadr=0x%04X hasdc=%d DCactive=%u DCcycle=%u DCshift=%d\n",
             i, ctx.slavelist[i].configadr, (int)ctx.slavelist[i].hasdc,
             (unsigned)ctx.slavelist[i].DCactive,
             (unsigned)ctx.slavelist[i].DCcycle, (int)ctx.slavelist[i].DCshift);
   }
   adr = ctx.slavelist[1].configadr;
   printf("REG 0x0900 DCTIME0=0x%08X 0x0904=0x%08X 0x0908=0x%08X 0x090C=0x%08X\n",
          (unsigned)rd32(adr, 0x0900), (unsigned)rd32(adr, 0x0904),
          (unsigned)rd32(adr, 0x0908), (unsigned)rd32(adr, 0x090C));
   printf("REG 0x0910 SYSTIME=0x%08X (lo)  0x0918 DCSOF=0x%08X  0x092C DIFF=0x%08X\n",
          (unsigned)rd32(adr, 0x0910), (unsigned)rd32(adr, 0x0918), (unsigned)rd32(adr, 0x092C));
   printf("REG 0x0980 CUC=0x%02X 0x0981 SYNCACT=0x%02X 0x0990 START0=0x%08X 0x09A0 CYCLE0=0x%08X\n",
          (unsigned)(rd16(adr, 0x0980) & 0xFF), (unsigned)(rd16(adr, 0x0980) >> 8),
          (unsigned)rd32(adr, 0x0990), (unsigned)rd32(adr, 0x09A0));

   /* SDO 读 0x1C32 / 0x1C33 的 Sync Type 与 Cycle Time */
   {
      uint16 v = 0; int sz = 2; int w;
      w = ecx_SDOread(&ctx, 1, 0x1C32, 0x01, FALSE, &sz, &v, EC_TIMEOUTRXM);
      printf("SDO 0x1C32:01 sync type  wkc=%d val=%u\n", w, v);
      sz = 4; { uint32 c = 0;
         w = ecx_SDOread(&ctx, 1, 0x1C32, 0x02, FALSE, &sz, &c, EC_TIMEOUTRXM);
         printf("SDO 0x1C32:02 cycle time wkc=%d val=%u\n", w, c); }
      sz = 2; v = 0;
      w = ecx_SDOread(&ctx, 1, 0x1C33, 0x01, FALSE, &sz, &v, EC_TIMEOUTRXM);
      printf("SDO 0x1C33:01 sync type  wkc=%d val=%u\n", w, v);
   }

   ecx_close(&ctx);
   return 0;
}
