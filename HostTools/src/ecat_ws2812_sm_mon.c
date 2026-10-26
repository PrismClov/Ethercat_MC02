/* SM-Sync 稳定性监控：保持 OP 若干秒，周期性记录
 *   AL Status(0x0130) / AL Code(0x0134) / AL Control(0x0120) / AL Event(0x0220)
 *   SM 看门狗 0x0420 / SM2 控制 0x0814
 *   输入 PDO(0x7000) 前 8 字节（同时从 ESC SM3 内存和主站 IOmap 各读一份）
 *   每个周期的 WKC
 * 用法: ecat_ws2812_sm_mon.exe <ifname> [hold_color 0..7] [seconds]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
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

static void rdbytes(uint16 adr, uint16 reg, uint8 *buf, int n)
{
   ecx_FPRD(&ctx.port, adr, reg, n, buf, EC_TIMEOUTRET);
}

static LONGLONG qpf;
static double now_us(void)
{
   LARGE_INTEGER c;
   QueryPerformanceCounter(&c);
   return (double)c.QuadPart * 1000000.0 / (double)qpf;
}

static int cmp_u32(const void *a, const void *b)
{
   uint32 x = *(const uint32 *)a, y = *(const uint32 *)b;
   return (x > y) - (x < y);
}

static void stats(const char *name, uint32 *a, int n)
{
   uint32 sum = 0;
   int i;
   if (n <= 0) { printf("%s: no samples\n", name); return; }
   qsort(a, n, sizeof(uint32), cmp_u32);
   for (i = 0; i < n; i++) sum += a[i];
   printf("%-10s n=%d min=%u avg=%.1f p50=%u p95=%u p99=%u max=%u (us)\n",
          name, n, a[0], (double)sum / n,
          a[(int)(n * 0.50)], a[(int)(n * 0.95)], a[(int)(n * 0.99)], a[n - 1]);
}

int main(int argc, char *argv[])
{
   ec_groupt *grp;
   uint16 adr, sm3 = 0;
   int i, wkc = 0, ci = 0;
   int hold = 0, secs = 20, pdiwd_flag = 0, freerun_flag = 0;
   int bad_stat = 0, bad_wkc = 0, sm2_ctrl_in = 0, op_ok = 0;
   uint16 first_stat = 0, last_stat = 0, last_code = 0;
   uint16 wd_now = 0;
   uint8 pdo[8], pdo_map[8];

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname> [hold 0..7] [seconds] [pdiwd_off]\n", argv[0]); return 1; }
   if (argc >= 3) hold = atoi(argv[2]);
   if (argc >= 4) secs = atoi(argv[3]);
   if (hold < 0 || hold > 7) hold = 0;
   { int mode = (argc >= 5) ? atoi(argv[4]) : 0;
     if (mode == 1) pdiwd_flag = 1;
     if (mode == 2) freerun_flag = 1;
     if (mode == 3) { pdiwd_flag = 1; freerun_flag = 1; } }

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }

   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X, duration=%ds, hold=%d\n", adr, secs, hold);

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);

   /* 必须在 ecx_config_map_group 之前写：该函数内部会向从站请求 SAFE_OP，
      SSC 的 StartInputHandler 在此时校验 0x0420 与 SM2 控制 bit6 的一致性。
      写 ESC 默认值 1000 (=100ms)，保持看门狗合法使能；同时修复上次运行
      残留 0 导致的 0x1F INVALIDWDCFG。绝不在 OP/SAFE_OP 之后改写为 0。 */
   printf("PREOP before WD write: ALSTAT=0x%04X ALCODE=0x%04X WD=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134), rd16(adr, 0x0420));
   {
      uint16_t wd = htoes(0x03E8);
      ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET);
   }
   if (pdiwd_flag)
   {
      uint16_t zero = 0;
      ecx_FPWR(&ctx.port, adr, 0x0410, 2, &zero, EC_TIMEOUTRET);
      printf("PDI WD disabled: 0x0410=0x%04X\n", rd16(adr, 0x0410));
   }
   if (freerun_flag)
   {
      uint16_t one = 1, r1 = 0, r2 = 0;
      int sz, w1, w2;
      w1 = ecx_SDOwrite(&ctx, 1, 0x1C32, 1, FALSE, 2, &one, EC_TIMEOUTRXM);
      osal_usleep(20000);
      w2 = ecx_SDOwrite(&ctx, 1, 0x1C33, 1, FALSE, 2, &one, EC_TIMEOUTRXM);
      if (w2 <= 0) { osal_usleep(50000); w2 = ecx_SDOwrite(&ctx, 1, 0x1C33, 1, FALSE, 2, &one, EC_TIMEOUTRXM); }
      sz = 2; ecx_SDOread(&ctx, 1, 0x1C32, 1, FALSE, &sz, &r1, EC_TIMEOUTRXM);
      sz = 2; ecx_SDOread(&ctx, 1, 0x1C33, 1, FALSE, &sz, &r2, EC_TIMEOUTRXM);
      printf("Force FreeRun: w1=%d w2=%d  read 0x1C32:1=%u 0x1C33:1=%u\n", w1, w2, r1, r2);
   }

   ecx_config_map_group(&ctx, io_map, 0);
   printf("group0: Obytes=%u Ibytes=%u\n",
          (unsigned)ctx.grouplist[0].Obytes, (unsigned)ctx.grouplist[0].Ibytes);

   /* 非阻塞等待 SAFE_OP：持续发帧，不用 ecx_statecheck 阻塞 */
   for (i = 0; i < 2000; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((rd16(adr, 0x0130) & 0x0F) == EC_STATE_SAFE_OP) break;
      osal_usleep(1000);
   }
   sm3 = rd16(adr, 0x0818);
   {
      uint16 sm2r = rd16(adr, 0x0814);
      printf("SAFE_OP: ALCTL=0x%04X ALSTAT=0x%04X ALCODE=0x%04X WD=0x%04X SM2ctl=0x%02X SM2st=0x%02X SM3addr=0x%04X\n",
             rd16(adr, 0x0120), rd16(adr, 0x0130), rd16(adr, 0x0134),
             rd16(adr, 0x0420), sm2r & 0xFF, sm2r >> 8, sm3);
      printf("        ALMASK=0x%04X IRQEN=0x%08X IRQST=0x%08X\n",
             rd16(adr, 0x0204), (unsigned)rd32(adr, 0x005C),
             (unsigned)rd32(adr, 0x0058));
   }

   wd_now = rd16(adr, 0x0420);
   {
      uint16 sm2r = rd16(adr, 0x0814);
      printf("after WD write: WD=0x%04X SM2ctl=0x%02X SM2st=0x%02X ALSTAT=0x%04X\n",
             wd_now, sm2r & 0xFF, sm2r >> 8, rd16(adr, 0x0130));
   }

   if (ctx.grouplist[0].Obytes >= 3)
   {
      grp = &ctx.grouplist[0];
      grp->outputs[0] = 255; grp->outputs[1] = 0; grp->outputs[2] = 0;
   }

   /* 进 OP 前必须确认 0x0440 bit0=1（WD 已由 SM2 写触发）。
      SSC 在 bEcatOutputUpdateRunning 置位的瞬间就会检查该位，
      为 0 时立刻回退 SAFE_OP 并置 0x1B —— 这就是 2ms 掉 OP 的竞态。 */
   for (i = 0; i < 100; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((rd32(adr, 0x0440) & 1) && wkc >= 3) break;
      osal_usleep(1000);
   }
   printf("pre-OP WD trigger: %s (i=%d wkc=%d WDst=0x%08X)\n",
          ((rd32(adr, 0x0440) & 1) ? "set" : "NOT SET"), i, wkc,
          (unsigned)rd32(adr, 0x0440));

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   /* 关键：OP 切换期间必须保持 1ms 连续发过程数据喂狗。
      不能用 ecx_statecheck(EC_TIMEOUTSTATE) 阻塞等待——它会 20ms 不发过程数据，
      几轮下来就超过 100ms 看门狗，CheckIfEcatError 立即回退 SAFE_OP + 0x1B。 */
   for (i = 0; i < 1000; i++)
   {
      if (ctx.grouplist[0].Obytes >= 3)
      {
         ctx.grouplist[0].outputs[0] = 255;
         ctx.grouplist[0].outputs[1] = 0;
         ctx.grouplist[0].outputs[2] = 0;
      }
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      last_stat = rd16(adr, 0x0130);
      if (i < 5)
         printf("  opw i=%d ALSTAT=0x%04X MASK=0x%04X IRQST=0x%08X SM2st=0x%02X\n",
                i, last_stat, rd16(adr, 0x0204),
                (unsigned)rd32(adr, 0x0058), (unsigned)(rd16(adr, 0x0814) >> 8));
      if (last_stat == EC_STATE_OPERATIONAL) { op_ok = 1; break; }
      if (last_stat & 0x10)
      {
         printf("  OP transition error at %dms ALSTAT=0x%04X ALCODE=0x%04X WDst=0x%08X\n",
                i, last_stat, rd16(adr, 0x0134), (unsigned)rd32(adr, 0x0440));
         break;
      }
      osal_usleep(1000);
   }
   if (!op_ok)
   {
      printf("OP failed, ALSTAT=0x%04X ALCODE=0x%04X\n",
             rd16(adr, 0x0130), rd16(adr, 0x0134));
      ctx.slavelist[0].state = EC_STATE_INIT;
      ecx_writestate(&ctx, 0);
      ecx_close(&ctx);
      return 1;
   }
   /* OP 真正建立后再确认一次 AL status */
   printf("OP entered: ALSTAT=0x%04X ALCODE=0x%04X\n",
          rd16(adr, 0x0130), rd16(adr, 0x0134));
   printf("OPERATIONAL at t=0ms\n");

   grp = &ctx.grouplist[0];
   first_stat = rd16(adr, 0x0130);

   {
      LARGE_INTEGER f;
      QueryPerformanceFrequency(&f);
      qpf = f.QuadPart;
   }
   {
   uint32 *lat_rtt = (uint32 *)malloc(sizeof(uint32) * (secs * 1000 + 1));
   uint32 *lat_per = (uint32 *)malloc(sizeof(uint32) * (secs * 1000 + 1));
   int ri = 0, pi = 0;
   double t_prev = now_us();

   for (i = 1; i <= secs * 1000; i++)
   {
      double t0, t1;
      if (grp->Obytes >= 3)
      {
         grp->outputs[0] = 255; grp->outputs[1] = 0; grp->outputs[2] = 0;  /* HOLD RED */
      }
      t0 = now_us();
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      t1 = now_us();
      if (lat_rtt) lat_rtt[ri++] = (uint32)((t1 - t0) + 0.5);
      if (lat_per && i > 1) lat_per[pi++] = (uint32)((t0 - t_prev) + 0.5);
      t_prev = t0;

      last_stat = rd16(adr, 0x0130);
      if (last_stat != EC_STATE_OPERATIONAL) bad_stat++;
      if (wkc < 3) bad_wkc++;

      if ((i % 250) == 0 || (i < 20))
      {
         uint16 alc = rd16(adr, 0x0120);
         uint16 alcode = rd16(adr, 0x0134);
         uint16 wd = rd16(adr, 0x0420);   /* 注意：主站禁止读 0x0220，会清从站事件 */
         uint32 wdst = rd32(adr, 0x0440);
         uint16 sm2r = rd16(adr, 0x0814);
         uint8 sm2ctl = (uint8)(sm2r & 0xFF);
         uint8 sm2st = (uint8)(sm2r >> 8);
         int k;

         last_code = alcode;
         if (sm2ctl & 0x40) sm2_ctrl_in++;    /* bit6: WD trigger enable */
         memset(pdo, 0, sizeof(pdo));
         memset(pdo_map, 0, sizeof(pdo_map));
         if (sm3) rdbytes(adr, sm3, pdo, 8);
         if (ctx.slavelist[1].inputs) memcpy(pdo_map, ctx.slavelist[1].inputs, 8);

         printf("t=%5dms ALSTAT=0x%04X ALCODE=0x%04X WKC=%d ALCTL=0x%04X WD=0x%04X WDst=0x%08X SM2ctl=0x%02X SM2st=0x%02X",
                i, last_stat, alcode, wkc, alc, wd,
                (unsigned)wdst, sm2ctl, sm2st);
         printf(" SM3=[");
         for (k = 0; k < 8; k++) printf("%s%02X", k ? " " : "", pdo[k]);
         printf("] MAP=[");
         for (k = 0; k < 8; k++) printf("%s%02X", k ? " " : "", pdo_map[k]);
         printf("]\n");

         if (last_stat != EC_STATE_OPERATIONAL)
            printf("  !! ALSTAT not OP (err) at t=%dms code=0x%04X\n", i, alcode);
      }
      osal_usleep(1000);
   }
   printf("\n==== LATENCY ====\n");
   stats("frame RTT", lat_rtt, ri);
   stats("cycle", lat_per, pi);
   free(lat_rtt);
   free(lat_per);
   }

   printf("\n==== SUMMARY ====\n");
   printf("first ALSTAT=0x%04X last ALSTAT=0x%04X last ALCODE=0x%04X\n",
          first_stat, last_stat, last_code);
   printf("bad ALSTAT samples=%d  bad WKC samples=%d  SM2 ctrl bit6 seen=%d  final WD=0x%04X\n",
          bad_stat, bad_wkc, sm2_ctrl_in, rd16(adr, 0x0420));

   ctx.slavelist[0].state = EC_STATE_INIT;
   ecx_writestate(&ctx, 0);
   ecx_close(&ctx);
   printf("done\n");
   return 0;
}
