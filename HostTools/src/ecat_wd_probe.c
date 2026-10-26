/* 受控看门狗实验：
 * 1) 在 PREOP 写 0x0420=0x03E8（与 SM2 控制 bit6=1 一致，SSC 校验可通过）
 * 2) 进入 SAFE_OP / OP，1ms 周期发过程数据
 * 3) 每 5ms 采样 ALSTAT / ALCODE / 0x0440(WD state)，观察 WD trigger 位
 * 4) 若 WD trigger 位掉 0 并触发 0x1B，记录发生时刻
 * 结束前把 0x0420 还原为 0，避免影响下次运行。
 */
#include <stdio.h>
#include <stdlib.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 io_map[4096];

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

static void wr16(uint16 adr, uint16 reg, uint16 val)
{
   uint16 v = htoes(val);
   ecx_FPWR(&ctx.port, adr, reg, 2, &v, EC_TIMEOUTRET);
}

int main(int argc, char *argv[])
{
   uint16 adr;
   int i, wkc = 0, ms = 3000;
   int last_trig = -1, first_fail_ms = -1;
   uint16 last_stat = 0, last_code = 0;

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname> [ms]\n", argv[0]); return 1; }
   if (argc >= 3) ms = atoi(argv[2]);

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);

   printf("PREOP: ALSTAT=0x%04X ALCODE=0x%04X DIV=0x%04X WD=0x%04X WDst=0x%08X SM2ctrl=0x%02X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134), rd16(adr, 0x0400), rd16(adr, 0x0420),
          (unsigned)rd32(adr, 0x0440), (unsigned)(rd16(adr, 0x0814) & 0xFF));

   wr16(adr, 0x0420, 0x03E8);
   printf("set WD=1000: WD=0x%04X WDst=0x%08X\n",
          rd16(adr, 0x0420), (unsigned)rd32(adr, 0x0440));

   ecx_config_map_group(&ctx, io_map, 0);
   ecx_statecheck(&ctx, 0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
   printf("SAFEOP: ALSTAT=0x%04X ALCODE=0x%04X WD=0x%04X WDst=0x%08X SM2ctrl=0x%02X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134), rd16(adr, 0x0420),
          (unsigned)rd32(adr, 0x0440), (unsigned)(rd16(adr, 0x0814) & 0xFF));

   if (ctx.grouplist[0].Obytes >= 3)
   {
      ctx.grouplist[0].outputs[0] = 255;
      ctx.grouplist[0].outputs[1] = 0;
      ctx.grouplist[0].outputs[2] = 0;
   }
   ecx_send_processdata(&ctx);
   wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   printf("1 frame before OP: wkc=%d WDst=0x%08X\n", wkc, (unsigned)rd32(adr, 0x0440));

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   for (i = 0; i < 10; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      ecx_statecheck(&ctx, 0, EC_STATE_OPERATIONAL, EC_TIMEOUTSTATE / 10);
      if (ctx.slavelist[0].state == EC_STATE_OPERATIONAL) break;
   }
   printf("OP entry: state=0x%02X ALSTAT=0x%04X ALCODE=0x%04X WDst=0x%08X\n",
          ctx.slavelist[0].state, rd16(adr, 0x0130), rd16(adr, 0x0134),
          (unsigned)rd32(adr, 0x0440));

   for (i = 1; i <= ms; i++)
   {
      if (ctx.grouplist[0].Obytes >= 3)
      {
         ctx.grouplist[0].outputs[0] = 255;
         ctx.grouplist[0].outputs[1] = 0;
         ctx.grouplist[0].outputs[2] = 0;
      }
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);

      if ((i % 5) == 0 || i < 20)
      {
         uint32 wdst = rd32(adr, 0x0440);
         int trig = (int)(wdst & 1);
         uint16 stat = rd16(adr, 0x0130);
         uint16 code = rd16(adr, 0x0134);

         if (trig != last_trig || stat != last_stat || code != last_code || i < 20)
         {
            printf("t=%5dms ALSTAT=0x%04X ALCODE=0x%04X WKC=%d WDst=0x%08X trig=%d SM2ctl=0x%02X\n",
                   i, stat, code, wkc, (unsigned)wdst, trig,
                   (unsigned)(rd16(adr, 0x0814) & 0xFF));
         }
         last_trig = trig; last_stat = stat; last_code = code;
         if (stat != EC_STATE_OPERATIONAL && first_fail_ms < 0)
         {
            first_fail_ms = i;
            printf(">>> LEFT OP at t=%dms: ALSTAT=0x%04X ALCODE=0x%04X WDst=0x%08X\n",
                   i, stat, code, (unsigned)wdst);
         }
      }
      osal_usleep(1000);
   }

   printf("RESULT: first_fail=%dms (%s) final ALSTAT=0x%04X ALCODE=0x%04X WDst=0x%08X\n",
          first_fail_ms, first_fail_ms < 0 ? "WD held OK" : "WD EXPIRED/DROPPED",
          rd16(adr, 0x0130), rd16(adr, 0x0134), (unsigned)rd32(adr, 0x0440));

   /* 还原：关闭 WD，避免下次 SAFE_OP 校验失败 */
   wr16(adr, 0x0420, 0x0000);
   printf("restore WD=0: WD=0x%04X\n", rd16(adr, 0x0420));
   ctx.slavelist[0].state = EC_STATE_INIT;
   ecx_writestate(&ctx, 0);
   ecx_close(&ctx);
   return 0;
}
