/* 涓荤珯閫氳繃 PDO 杈撳嚭鎺у埗浠庣珯 WS2812锛歰utput[0]=R, [1]=G, [2]=B */
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

/* 非阻塞状态等待：每 1ms 发一帧过程数据再读 AL status。
   不能用 ecx_statecheck——它阻塞期间不发过程数据，SM 看门狗(100ms)
   会在 SAFEOP→OP 切换时超时，从站回退 SAFE_OP 并报 0x1B。 */
static uint16 wait_state(uint16 adr, uint16 target, int timeout_ms)
{
   int i;
   uint16 st = 0;
   for (i = 0; i < timeout_ms; i++)
   {
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == target) return st;
      if (st & 0x10) return st;   /* error bit */
      osal_usleep(1000);
   }
   return st;
}

static const uint8 colors[8][3] = {
   {255,   0,   0},  /* 绾?*/
   {  0, 255,   0},  /* 缁?*/
   {  0,   0, 255},  /* 钃?*/
   {255, 255, 255},  /* 鐧?*/
   {255, 255,   0},  /* 榛?*/
   {  0, 255, 255},  /* 闈?*/
   {255,   0, 255},  /* 绱?*/
   {  0,   0,   0},  /* 鐏?*/
};
static const char *names[8] = { "RED", "GREEN", "BLUE", "WHITE", "YELLOW", "CYAN", "MAGENTA", "OFF" };

int main(int argc, char *argv[])
{
   ec_groupt *grp;
   uint16 adr, z = 0;
   int i, wkc, r = 0, g = 0, b = 0, ci = -1;
   int hold = -1;   /* >=0: 閿佸畾璇ラ鑹蹭笉鍒囨崲 */

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname> [hold_color 0..7]\n", argv[0]); return 1; }
   if (argc >= 3) hold = atoi(argv[2]);
   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X\n", adr);
   grp = &ctx.grouplist[0];

   /* PRE-OP + 寮哄埗 FreeRun锛堜笌宸查獙璇佺殑娴佺▼涓€鑷达級 */
   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);
   /* SM-Sync: 不写 0x1C32，让 SSC 自动选择 SM-Sync */
   /* SM-Sync: 不写 0x1C33 */

   /* 必须在 ecx_config_map_group 之前写：该函数内部会请求 SAFE_OP，
      SSC 的 StartInputHandler 在 PREOP→SAFEOP 时校验 0x0420 与 SM2 控制
      bit6 的一致性。写 ESC 默认的 1000 (=100ms) 使看门狗保持合法使能，
      同时修复上次运行残留 0 导致的 0x1F INVALIDWDCFG。 */
   {
      uint16_t wd = htoes(0x03E8);
      ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET);
      printf("WD set: 0x%04X\n", rd16(adr, 0x0420));
   }

   ecx_config_map_group(&ctx, io_map, 0);
   printf("group0: logstart=0x%08X Obytes=%u Ibytes=%u\n",
          (unsigned)ctx.grouplist[0].logstartaddr,
          (unsigned)ctx.grouplist[0].Obytes,
          (unsigned)ctx.grouplist[0].Ibytes);

   /* 非阻塞等待 SAFE_OP（持续发帧喂狗） */
   {
      uint16 st = wait_state(adr, EC_STATE_SAFE_OP, 2000);
      printf("SAFE_OP: ALSTAT=0x%04X\n", (unsigned)st);
      if ((st & 0x0F) != EC_STATE_SAFE_OP)
      {
         printf("SAFE_OP failed, ALSTAT=0x%04X ALCODE=0x%04X\n",
                (unsigned)st, rd16(adr, 0x0134));
         ecx_close(&ctx);
         return 1;
      }
   }

   if (grp->Obytes >= 3)
   {
      grp->outputs[0] = 255; grp->outputs[1] = 0; grp->outputs[2] = 0;
   }
   /* 请求 OP 前先确认 WD 已被 SM2 写触发(0x0440 bit0=1)：
      SSC 在进入 OP 的瞬间检查该位，为 0 会立即回退 SAFE_OP + 0x1B。 */
   for (i = 0; i < 100; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((rd32(adr, 0x0440) & 1) && wkc >= 3) break;
      osal_usleep(1000);
   }
   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   {
      uint16 st = wait_state(adr, EC_STATE_OPERATIONAL, 1000);
      if ((st & 0x0F) != EC_STATE_OPERATIONAL)
      {
         printf("OP failed, ALSTAT=0x%04X ALCODE=0x%04X\n",
                (unsigned)st, rd16(adr, 0x0134));
         ecx_close(&ctx);
         return 1;
      }
   }
   printf("OPERATIONAL, Obytes=%d Ibytes=%d, 寮€濮嬫帶鍒?WS2812 (姣?绉掓崲鑹?\n",
          ctx.grouplist[0].Obytes, ctx.grouplist[0].Ibytes);

   grp = &ctx.grouplist[0];

   for (i = 0; i < 16000; i++)   /* 绾?16~20 绉?*/
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

   /* 閫€鍑哄墠鐏伅骞跺洖鍒?INIT锛堥攣瀹氶鑹叉椂淇濇寔鐏晥锛屾柟渚胯瀵燂級 */
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


