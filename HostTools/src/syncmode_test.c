/* Verify SM-Sync (ESC interrupt) path: force 0x1C32.1=1 / 0x1C33.1=0x22
 * in PRE-OP, then try to reach OPERATIONAL.
 */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 iomap[4096];

static uint16 rd16(uint16 adr, uint16 reg)
{
   uint16 v = 0;
   ecx_FPRD(&ctx.port, adr, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}

int main(int argc, char *argv[])
{
   uint16 adr, v, st;
   int r, sz, i, wkc;

   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   adr = ctx.slavelist[1].configadr;
   printf("cfgadr=0x%04X\n", adr);

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);
   printf("PRE-OP: ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134));

   st = 0; sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C32, 1, FALSE, &sz, &st, EC_TIMEOUTRXM);
   printf("current 1C32.1: ret=%d val=0x%04X\n", r, st);
   st = 0; sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C33, 1, FALSE, &sz, &st, EC_TIMEOUTRXM);
   printf("current 1C33.1: ret=%d val=0x%04X\n", r, st);

   v = 0x0001; /* SYNCTYPE_SM_SYNCHRON */
   r = ecx_SDOwrite(&ctx, 1, 0x1C32, 1, FALSE, 2, &v, EC_TIMEOUTRXM);
   printf("write 1C32.1=0x0001 ret=%d\n", r);
   v = 0x0022; /* SYNCTYPE_SM2_SYNCHRON */
   r = ecx_SDOwrite(&ctx, 1, 0x1C33, 1, FALSE, 2, &v, EC_TIMEOUTRXM);
   printf("write 1C33.1=0x0022 ret=%d\n", r);

   ecx_config_map_group(&ctx, iomap, 0);
   ecx_statecheck(&ctx, 0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
   printf("SAFE_OP: ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134));

   ecx_send_processdata(&ctx);
   wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);

   for (i = 0; i < 300; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((i % 10) == 0)
      {
         printf("t=%4dms wkc=%d ALSTAT=0x%04X ALCODE=0x%04X ALEVENT=0x%04X\n",
                i * 20, wkc, rd16(adr, 0x0130), rd16(adr, 0x0134),
                rd16(adr, 0x0220));
      }
      if ((rd16(adr, 0x0130) & 0x000F) == EC_STATE_OPERATIONAL)
      {
         printf("*** OPERATIONAL (SM-Sync / IRQ path OK) ***\n");
         break;
      }
      osal_usleep(20000);
   }

   ecx_close(&ctx);
   return 0;
}
