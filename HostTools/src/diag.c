/* EtherCAT AL-state diagnostic: reads AL Control/Status registers while
 * requesting OPERATIONAL, to tell "master write not reaching slave" apart
 * from "slave PDI refuses OP".
 */
#include <stdio.h>
#include "soem/soem.h"

#define REG_ALCTL      0x0120
#define REG_ALSTAT     0x0130
#define REG_ALSTATCODE 0x0134
#define REG_ALEVENT    0x0220
#define REG_SM2CTRL    0x0804
#define REG_SM2STAT    0x0805
#define REG_SM2ACT     0x0806
#define REG_SM3CTRL    0x080C

static ecx_contextt ctx;
static uint8 iomap[4096];

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

static void dump(const char *tag, int t, int wkc, uint16 adr)
{
   printf("%-8s t=%4dms wkc=%d ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X\n",
          tag, t, wkc, rd16(adr, REG_ALCTL), rd16(adr, REG_ALSTAT),
          rd16(adr, REG_ALSTATCODE));
}

int main(int argc, char *argv[])
{
   uint16 adr;
   int i, wkc = 0;

   if (argc < 2)
   {
      printf("usage: %s <ifname>\n", argv[0]);
      return 1;
   }
   if (!ecx_init(&ctx, argv[1]))
   {
      printf("ecx_init failed\n");
      return 1;
   }
   if (ecx_config_init(&ctx) <= 0)
   {
      printf("no slaves\n");
      ecx_close(&ctx);
      return 1;
   }
   adr = ctx.slavelist[1].configadr;
   printf("slaves=%d slave1 cfgadr=0x%04X\n", ctx.slavecount, adr);

   ecx_config_map_group(&ctx, iomap, 0);
   ecx_configdc(&ctx);
   ecx_statecheck(&ctx, 0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
   ecx_send_processdata(&ctx);
   wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

   printf("SM2=0x%08X SM3=0x%08X ALEVENT=0x%04X\n",
          rd32(adr, REG_SM2CTRL), rd32(adr, REG_SM3CTRL), rd16(adr, REG_ALEVENT));
   dump("before", 0, wkc, adr);

   ctx.slavelist[1].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 1);
   printf("-- OP requested unicast to slave 1 --\n");
   for (i = 1; i <= 600; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((i % 10) == 0)
      {
         printf("unicast  t=%4dms wkc=%d ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X ALEVENT=0x%04X\n",
                i * 20, wkc, rd16(adr, REG_ALCTL), rd16(adr, REG_ALSTAT),
                rd16(adr, REG_ALSTATCODE), rd16(adr, REG_ALEVENT));
      }
      osal_usleep(20000);
   }

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   printf("-- OP requested broadcast --\n");
   for (i = 1; i <= 40; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((i % 5) == 0)
      {
         dump("broadcast", i * 20, wkc, adr);
      }
      osal_usleep(20000);
   }

   ecx_close(&ctx);
   return 0;
}
