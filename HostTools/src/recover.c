/* Try to recover the slave from INIT+ERROR by sending ACKed state requests. */
#include <stdio.h>
#include "soem/soem.h"

static ecx_contextt ctx;

static uint16 rd(uint16 reg)
{
   uint16 v = 0;
   ecx_APRD(&ctx.port, 0, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}

static void req(const char *tag, uint16 state)
{
   ecx_APWRw(&ctx.port, 0, ECT_REG_ALCTL, htoes(state), EC_TIMEOUTRET3);
   osal_usleep(150000);
   printf("%-16s -> ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X\n",
          tag, rd(0x0120), rd(0x0130), rd(0x0134));
}

int main(int argc, char *argv[])
{
   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }
   if (!ecx_init(&ctx, argv[1])) { printf("init failed\n"); return 1; }

   printf("initial          ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd(0x0120), rd(0x0130), rd(0x0134));

   req("INIT|ACK",  0x0011);
   req("PREOP|ACK", 0x0012);
   req("SAFEOP|ACK",0x0014);
   req("OP",        0x0008);

   ecx_close(&ctx);
   return 0;
}
