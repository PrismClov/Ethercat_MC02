/* 主站通过 PDO 输出控制从站 WS2812：output[0]=R, [1]=G, [2]=B */
#include <stdio.h>
#include <stdlib.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 io_map[4096];

static const uint8 colors[8][3] = {
   {255,   0,   0},  /* 红 */
   {  0, 255,   0},  /* 绿 */
   {  0,   0, 255},  /* 蓝 */
   {255, 255, 255},  /* 白 */
   {255, 255,   0},  /* 黄 */
   {  0, 255, 255},  /* 青 */
   {255,   0, 255},  /* 紫 */
   {  0,   0,   0},  /* 灭 */
};
static const char *names[8] = { "RED", "GREEN", "BLUE", "WHITE", "YELLOW", "CYAN", "MAGENTA", "OFF" };

int main(int argc, char *argv[])
{
   ec_groupt *grp;
   uint16 adr, z = 0;
   int i, wkc, r = 0, g = 0, b = 0, ci = -1;
   int hold = -1;   /* >=0: 锁定该颜色不切换 */

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname> [hold_color 0..7]\n", argv[0]); return 1; }
   if (argc >= 3) hold = atoi(argv[2]);
   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X\n", adr);

   /* PRE-OP + 强制 FreeRun（与已验证的流程一致） */
   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);
   ecx_SDOwrite(&ctx, 1, 0x1C32, 1, FALSE, 2, &z, EC_TIMEOUTRXM);
   ecx_SDOwrite(&ctx, 1, 0x1C33, 1, FALSE, 2, &z, EC_TIMEOUTRXM);

   ecx_config_map_group(&ctx, io_map, 0);
   printf("group0: logstart=0x%08X Obytes=%u Ibytes=%u\n",
          (unsigned)ctx.grouplist[0].logstartaddr,
          (unsigned)ctx.grouplist[0].Obytes,
          (unsigned)ctx.grouplist[0].Ibytes);
   ecx_configdc(&ctx);
   ecx_statecheck(&ctx, 0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
   printf("SAFE_OP: ALSTAT=0x%04X\n", (unsigned)((ecx_FPRDw(&ctx.port, adr, 0x0130, EC_TIMEOUTRET)) ));

   ecx_send_processdata(&ctx);
   wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   for (i = 0; i < 10; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      ecx_statecheck(&ctx, 0, EC_STATE_OPERATIONAL, EC_TIMEOUTSTATE / 10);
      if (ctx.slavelist[0].state == EC_STATE_OPERATIONAL)
         break;
   }
   if (ctx.slavelist[0].state != EC_STATE_OPERATIONAL)
   {
      printf("OP failed, ALSTAT=0x%04X\n", (unsigned)ecx_FPRDw(&ctx.port, adr, 0x0130, EC_TIMEOUTRET));
      ecx_close(&ctx);
      return 1;
   }
   printf("OPERATIONAL, Obytes=%d Ibytes=%d, 开始控制 WS2812 (每2秒换色)\n",
          ctx.grouplist[0].Obytes, ctx.grouplist[0].Ibytes);

   grp = &ctx.grouplist[0];

   for (i = 0; i < 16000; i++)   /* 约 16~20 秒 */
   {
      if (hold >= 0 || (i % 2000) == 0)
      {
         if (hold >= 0)
         {
            if (ci != hold)
            {
               ci = hold;
               printf("HOLD %-8s R=%3d G=%3d B=%3d\n", names[ci], colors[ci][0], colors[ci][1], colors[ci][2]);
            }
         }
         else
         {
            ci = (ci + 1) % 8;
         }
         r = colors[ci][0];
         g = colors[ci][1];
         b = colors[ci][2];
      }

      if (grp->Obytes >= 3)
      {
         grp->outputs[0] = (uint8)r;
         grp->outputs[1] = (uint8)g;
         grp->outputs[2] = (uint8)b;
      }

      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((i % 4000) == 0)
         printf("     WKC=%d\n", wkc);

      osal_usleep(1000);
   }

   /* 退出前灭灯并回到 INIT（锁定颜色时保持灯效，方便观察） */
   if (hold < 0 && grp->Obytes >= 3)
   {
      grp->outputs[0] = 0; grp->outputs[1] = 0; grp->outputs[2] = 0;
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   }
   ctx.slavelist[0].state = EC_STATE_INIT;
   ecx_writestate(&ctx, 0);
   ecx_close(&ctx);
   printf("done\n");
   return 0;
}
