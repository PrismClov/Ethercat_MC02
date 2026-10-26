/* Test: force slave SyncType (0x1C32.1 / 0x1C33.1) to FreeRun and see if
 * the slave can reach OPERATIONAL. SDO return values are checked.
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
   uint16 adr, v, st32, st33;
   int r, sz, i, wkc;

   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   adr = ctx.slavelist[1].configadr;
   printf("cfgadr=0x%04X ALSTAT=0x%04X ALCODE=0x%04X\n",
          adr, rd16(adr, 0x0130), rd16(adr, 0x0134));

   /* force PRE-OP so the object values are re-read on the next SAFE-OP transition */
   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);
   printf("after PRE-OP req: ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134));

   st32 = st33 = 0;
   sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C32, 1, FALSE, &sz, &st32, EC_TIMEOUTRXM);
   printf("read 1C32.1: ret=%d size=%d val=0x%04X\n", r, sz, st32);
   sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C33, 1, FALSE, &sz, &st33, EC_TIMEOUTRXM);
   printf("read 1C33.1: ret=%d size=%d val=0x%04X\n", r, sz, st33);

   v = 0; /* FreeRun */
   r = ecx_SDOwrite(&ctx, 1, 0x1C32, 1, FALSE, 2, &v, EC_TIMEOUTRXM);
   printf("write 1C32.1=0: ret=%d\n", r);
   r = ecx_SDOwrite(&ctx, 1, 0x1C33, 1, FALSE, 2, &v, EC_TIMEOUTRXM);
   printf("write 1C33.1=0: ret=%d\n", r);

   st32 = st33 = 0;
   sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C32, 1, FALSE, &sz, &st32, EC_TIMEOUTRXM);
   printf("re-read 1C32.1: ret=%d val=0x%04X\n", r, st32);
   sz = 2;
   r = ecx_SDOread(&ctx, 1, 0x1C33, 1, FALSE, &sz, &st33, EC_TIMEOUTRXM);
   printf("re-read 1C33.1: ret=%d val=0x%04X\n", r, st33);

   ecx_config_map_group(&ctx, iomap, 0);
   ecx_statecheck(&ctx, 0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
   printf("SAFE_OP: ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134));

   ecx_send_processdata(&ctx);
   wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);

   for (i = 0; i < 250; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((i % 10) == 0)
      {
         printf("t=%4dms wkc=%d ALSTAT=0x%04X ALCODE=0x%04X\n",
                i * 20, wkc, rd16(adr, 0x0130), rd16(adr, 0x0134));
      }
      if ((rd16(adr, 0x0130) & 0x000F) == EC_STATE_OPERATIONAL)
      {
         printf("*** OPERATIONAL ***\n");
         break;
      }
      osal_usleep(20000);
   }

   ecx_close(&ctx);
   return 0;
}
