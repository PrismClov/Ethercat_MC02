/* EtherCAT 延迟测试（看门狗保持 100ms 使能，PREOP 写 0x03E8）
 * 测量：
 *   1) PREOP->SAFE_OP、SAFE_OP->OP 状态切换耗时
 *   2) 每周期 ecx_send+receive 的过程数据往返时延 (RTT)
 *   3) 实际周期长度与抖动（含 osal_usleep(1000)）
 *   4) AL status / WKC 异常计数
 * 用法: ecat_latency.exe <ifname> [seconds]
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 io_map[4096];
static LONGLONG qpf;

static double now_us(void)
{
   LARGE_INTEGER c;
   QueryPerformanceCounter(&c);
   return (double)c.QuadPart * 1000000.0 / (double)qpf;
}

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

static int cmp_u32(const void *a, const void *b)
{
   uint32 x = *(const uint32 *)a, y = *(const uint32 *)b;
   return (x > y) - (x < y);
}

static void stats(const char *name, uint32 *a, int n)
{
   uint32 sum = 0, p50, p95, p99;
   int i;
   if (n <= 0) { printf("%s: no samples\n", name); return; }
   qsort(a, n, sizeof(uint32), cmp_u32);
   for (i = 0; i < n; i++) sum += a[i];
   p50 = a[(int)(n * 0.50)];
   p95 = a[(int)(n * 0.95)];
   p99 = a[(int)(n * 0.99)];
   printf("%-10s n=%d min=%u avg=%.1f p50=%u p95=%u p99=%u max=%u (us)\n",
          name, n, a[0], (double)sum / n, p50, p95, p99, a[n - 1]);
}

/* 非阻塞等待：每 1ms 发帧喂狗，再读 AL status */
static uint16 wait_state(uint16 adr, uint16 target, int timeout_ms, double *elapsed_ms)
{
   int i;
   uint16 st = 0;
   double t0 = now_us();
   for (i = 0; i < timeout_ms; i++)
   {
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == target || (st & 0x10)) break;
      osal_usleep(1000);
   }
   if (elapsed_ms) *elapsed_ms = (now_us() - t0) / 1000.0;
   return st;
}

int main(int argc, char *argv[])
{
   uint16 adr, st;
   int i, n, wkc = 0, bad_wkc = 0, bad_stat = 0;
   int secs = 20;
   uint32 *rtt, *per;
   double t_map0, t_map1, t_safe_ms = 0, t_op_ms = 0;
   LARGE_INTEGER f;

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname> [seconds]\n", argv[0]); return 1; }
   if (argc >= 3) secs = atoi(argv[2]);
   QueryPerformanceFrequency(&f);
   qpf = f.QuadPart;

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X, test %ds, QPF=%lld Hz\n", adr, secs, (long long)qpf);

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   ecx_statecheck(&ctx, 1, EC_STATE_PRE_OP, EC_TIMEOUTSTATE);

   /* 看门狗合法使能：必须在 config_map_group（内部请求 SAFE_OP）之前写 */
   {
      uint16_t wd = htoes(0x03E8);
      ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET);
   }

   t_map0 = now_us();
   {
      int mr = ecx_config_map_group(&ctx, io_map, 0);
      t_map1 = now_us();
      printf("config_map_group ret=%d Obytes=%u Ibytes=%u\n", mr,
             (unsigned)ctx.grouplist[0].Obytes, (unsigned)ctx.grouplist[0].Ibytes);
   }
   st = wait_state(adr, EC_STATE_SAFE_OP, 2000, &t_safe_ms);
   printf("SAFE_OP: ALSTAT=0x%04X  transition=%.2fms  WD=0x%04X\n",
          st, t_safe_ms, rd16(adr, 0x0420));
   if ((st & 0x0F) != EC_STATE_SAFE_OP) { printf("SAFE_OP failed\n"); ecx_close(&ctx); return 1; }

   if (ctx.grouplist[0].Obytes >= 3)
   {
      ctx.grouplist[0].outputs[0] = 255;
      ctx.grouplist[0].outputs[1] = 0;
      ctx.grouplist[0].outputs[2] = 0;
   }
   /* 确认 WD 已被 SM2 写触发 */
   for (i = 0; i < 100; i++)
   {
      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      if ((rd32(adr, 0x0440) & 1) && wkc >= 3) break;
      osal_usleep(1000);
   }
   printf("pre-OP trigger i=%d wkc=%d WDst=0x%08X\n", i, wkc, (unsigned)rd32(adr, 0x0440));

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   {
      double t0 = now_us();
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
         st = rd16(adr, 0x0130);
         if ((st & 0x0F) == EC_STATE_OPERATIONAL || (st & 0x10)) break;
         if (i < 5 || (i % 200) == 0)
            printf("  opwait i=%d ALSTAT=0x%04X ALCODE=0x%04X WKC=%d WDst=0x%08X\n",
                   i, st, rd16(adr, 0x0134), wkc, (unsigned)rd32(adr, 0x0440));
         osal_usleep(1000);
      }
      t_op_ms = (now_us() - t0) / 1000.0;
   }
   printf("OP:      ALSTAT=0x%04X  transition=%.2fms  WD=0x%04X\n",
          st, t_op_ms, rd16(adr, 0x0420));
   if ((st & 0x0F) != EC_STATE_OPERATIONAL) { printf("OP failed\n"); ecx_close(&ctx); return 1; }
   printf("map_group=%0.2fms\n", (t_map1 - t_map0) / 1000.0);

   n = secs * 1000;
   rtt = (uint32 *)malloc(sizeof(uint32) * n);
   per = (uint32 *)malloc(sizeof(uint32) * n);
   if (!rtt || !per) { printf("malloc failed\n"); return 1; }

   {
      double t_prev = now_us();
      int ri = 0, pi = 0;
      printf("measuring %d cycles...\n", n);
      for (i = 0; i < n; i++)
      {
         double t0, t1;
         uint32 d;

         if (ctx.grouplist[0].Obytes >= 3)
         {
            ctx.grouplist[0].outputs[0] = 255;
            ctx.grouplist[0].outputs[1] = 0;
            ctx.grouplist[0].outputs[2] = 0;
         }
         t0 = now_us();
         ecx_send_processdata(&ctx);
         wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
         t1 = now_us();
         d = (uint32)((t1 - t0) + 0.5);
         rtt[ri++] = d;
         if (i > 0)
         {
            d = (uint32)((t0 - t_prev) + 0.5);
            per[pi++] = d;
         }
         t_prev = t0;
         if (wkc < 3) bad_wkc++;
         if ((i % 200) == 0)
         {
            st = rd16(adr, 0x0130);
            if ((st & 0x0F) != EC_STATE_OPERATIONAL || (st & 0x10)) bad_stat++;
         }
         osal_usleep(1000);
      }
      stats("frame RTT", rtt, ri);
      stats("cycle", per, pi);
   }

   printf("bad WKC=%d  bad ALSTAT=%d  final ALSTAT=0x%04X ALCODE=0x%04X WD=0x%04X WDst=0x%08X\n",
          bad_wkc, bad_stat, rd16(adr, 0x0130), rd16(adr, 0x0134),
          rd16(adr, 0x0420), (unsigned)rd32(adr, 0x0440));

   ctx.slavelist[0].state = EC_STATE_INIT;
   ecx_writestate(&ctx, 0);
   ecx_close(&ctx);
   printf("done\n");
   return 0;
}
