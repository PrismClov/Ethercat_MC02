/* DC Sync (SYNC0) 测试
 * 流程：
 *   PREOP 下 SDO 配置 0x1C32/0x1C33 为 DC SYNC0 + 周期
 *   config_map_group（内部请求 SAFE_OP，SSC 在此时读取 sync type）
 *   非阻塞等待 SAFE_OP（持续发帧喂狗）
 *   ecx_configdc + ecx_dcsync0 激活 SYNC0
 *   等待首个 SYNC0（约 100ms 后）再请求 OP
 *   OP 下连续发帧，监测 ALSTAT/ALCODE、0x092C 同步偏差、0x0980 激活状态、
 *   SDO 0x1C32:11 (SM event missed) / :13 (sync error)
 * 用法: ecat_dc_sync.exe <ifname> [seconds] [cycle_ns]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/* 精确等待到绝对时间点（先睡后自旋） */
static void pace_to(double target_us)
{
   for (;;)
   {
      double t = now_us();
      double rem;
      if (t >= target_us) return;
      rem = target_us - t;
      if (rem > 300.0) osal_usleep((int)(rem - 200.0));
   }
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

static int sdo_rd16(uint16 idx, uint8 sub, uint16 *val)
{
   int sz = 2, w;
   *val = 0;
   w = ecx_SDOread(&ctx, 1, idx, sub, FALSE, &sz, val, EC_TIMEOUTRXM);
   return w;
}
static int sdo_rd32(uint16 idx, uint8 sub, uint32 *val)
{
   int sz = 4, w;
   *val = 0;
   w = ecx_SDOread(&ctx, 1, idx, sub, FALSE, &sz, val, EC_TIMEOUTRXM);
   return w;
}
static int sdo_wr16(uint16 idx, uint8 sub, uint16 val)
{
   return ecx_SDOwrite(&ctx, 1, idx, sub, FALSE, 2, &val, EC_TIMEOUTRXM);
}
static int sdo_wr32(uint16 idx, uint8 sub, uint32 val)
{
   return ecx_SDOwrite(&ctx, 1, idx, sub, FALSE, 4, &val, EC_TIMEOUTRXM);
}

/* 非阻塞等待：每 1ms 发帧喂狗，再读 AL status */
static uint16 wait_state(uint16 adr, uint16 target, int timeout_ms)
{
   int i;
   uint16 st = 0;
   for (i = 0; i < timeout_ms; i++)
   {
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == target || (st & 0x10)) break;
      osal_usleep(1000);
   }
   return st;
}

static void dump_dc(uint16 adr, const char *tag)
{
   printf("%s: 0x0910=%08X 0x0918=%08X 0x092C=%08X 0x0980=%02X 0x0981=%02X 0x0990=%08X 0x09A0=%08X\n",
          tag, (unsigned)rd32(adr, 0x0910), (unsigned)rd32(adr, 0x0918),
          (unsigned)rd32(adr, 0x092C),
          (unsigned)(rd16(adr, 0x0980) & 0xFF), (unsigned)(rd16(adr, 0x0980) >> 8),
          (unsigned)rd32(adr, 0x0990), (unsigned)rd32(adr, 0x09A0));
}

int main(int argc, char *argv[])
{
   uint16 adr, st, v16;
   uint32 v32;
   int i, wkc = 0, secs = 30, w;
   uint32 cycle_ns = 2000000;
   int bad_stat = 0, bad_wkc = 0, op_ok = 0;
   uint16 sync_missed0 = 0, sync_err0 = 0, sync_missed = 0, sync_err = 0;
   int sync_err_samples = 0;

   setvbuf(stdout, NULL, _IONBF, 0);
   { LARGE_INTEGER f; QueryPerformanceFrequency(&f); qpf = f.QuadPart; }
   if (argc < 2) { printf("usage: %s <ifname> [seconds] [cycle_ns]\n", argv[0]); return 1; }
   if (argc >= 3) secs = atoi(argv[2]);
   if (argc >= 4) cycle_ns = (uint32)strtoul(argv[3], NULL, 0);

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X hasdc=%d seconds=%d cycle=%uns\n",
          adr, (int)ctx.slavelist[1].hasdc, secs, (unsigned)cycle_ns);

   /* 强制回 INIT（带 ACK）清残留状态 */
   ctx.slavelist[1].state = EC_STATE_INIT | 0x10;
   ecx_writestate(&ctx, 1);
   for (i = 0; i < 500; i++)
   {
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_INIT) break;
      osal_usleep(1000);
   }
   printf("INIT:  ALSTAT=0x%04X ALCODE=0x%04X\n", st, rd16(adr, 0x0134));
   /* 关闭可能残留的 SYNC0 */
   ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
   osal_usleep(10000);

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
   for (i = 0; i < 500; i++)
   {
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_PRE_OP) break;
      osal_usleep(1000);
   }
   printf("PREOP: ALSTAT=0x%04X ALCODE=0x%04X\n", st, rd16(adr, 0x0134));
   if ((st & 0x0F) != EC_STATE_PRE_OP)
   {
      printf("slave not in PREOP, abort (mailbox/SDO would be unsafe)\n");
      ecx_close(&ctx);
      return 1;
   }

   /* 看门狗合法使能，必须在 config_map_group（内部请求 SAFE_OP）之前 */
   { uint16_t wd = htoes(0x03E8); ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET); }

   /* --- PREOP 下配置 DC sync type / cycle（SSC 在 PREOP->SAFEOP 读取） --- */
   w = sdo_rd16(0x1C32, 4, &v16); printf("SDO 0x1C32:04 supported   wkc=%d val=0x%04X\n", w, v16);
   w = sdo_rd16(0x1C32, 1, &v16); printf("SDO 0x1C32:01 sync type   wkc=%d val=%u\n", w, v16);
   w = sdo_rd32(0x1C32, 2, &v32); printf("SDO 0x1C32:02 cycle       wkc=%d val=%u\n", w, (unsigned)v32);
   w = sdo_rd16(0x1C33, 4, &v16); printf("SDO 0x1C33:04 supported   wkc=%d val=0x%04X\n", w, v16);
   w = sdo_rd16(0x1C33, 1, &v16); printf("SDO 0x1C33:01 sync type   wkc=%d val=%u\n", w, v16);

   w = sdo_wr16(0x1C32, 1, 2); printf("WR 0x1C32:01=2 (DC SYNC0) wkc=%d\n", w);
   w = sdo_wr32(0x1C32, 2, cycle_ns); printf("WR 0x1C32:02=%u wkc=%d\n", (unsigned)cycle_ns, w);
   w = sdo_wr16(0x1C33, 1, 2); printf("WR 0x1C33:01=2 (DC SYNC0) wkc=%d\n", w);
   w = sdo_wr32(0x1C33, 2, cycle_ns); printf("WR 0x1C33:02=%u wkc=%d\n", (unsigned)cycle_ns, w);

   w = sdo_rd16(0x1C32, 1, &v16); printf("RD 0x1C32:01=%u (wkc=%d)\n", v16, w);
   w = sdo_rd32(0x1C32, 2, &v32); printf("RD 0x1C32:02=%u (wkc=%d)\n", (unsigned)v32, w);
   w = sdo_rd16(0x1C33, 1, &v16); printf("RD 0x1C33:01=%u (wkc=%d)\n", v16, w);
   /* 放宽 sync error counter limit（默认 4 太严格，SM 事件偶发丢失会导致 DC 序列无效） */
   {
      uint16_t lim = 1000;
      w = sdo_wr16(0x10F1, 2, lim);
      printf("WR 0x10F1:02 sync-error-limit=%u wkc=%d\n", lim, w);
      w = sdo_rd16(0x10F1, 2, &v16);
      printf("RD 0x10F1:02=%u (wkc=%d)\n", v16, w);
   }

   /* --- DC 配置必须在 PREOP->SAFE_OP 之前完成 ---
      SSC 在 StartInputHandler 中校验 DC 配置，若 SYNC0 尚未激活会返回 0x30 */
   {
      boolean dcok = ecx_configdc(&ctx);
      printf("ecx_configdc=%d\n", (int)dcok);
   }
   dump_dc(adr, "after configdc");
   ecx_dcsync0(&ctx, 1, TRUE, cycle_ns, 0);
   printf("dcsync0 activated (cycle=%uns)\n", (unsigned)cycle_ns);
   dump_dc(adr, "after dcsync0");
   osal_usleep(10000);   /* 短等待；首个 SYNC0 在 map/SAFE_OP 期间到来 */
   dump_dc(adr, "after short wait");

   /* --- mapping + SAFE_OP --- */
   ecx_config_map_group(&ctx, io_map, 0);
   printf("group0: Obytes=%u Ibytes=%u\n",
          (unsigned)ctx.grouplist[0].Obytes, (unsigned)ctx.grouplist[0].Ibytes);
   st = wait_state(adr, EC_STATE_SAFE_OP, 2000);
   printf("SAFE_OP: ALSTAT=0x%04X ALCODE=0x%04X\n", st, rd16(adr, 0x0134));
   if ((st & 0x0F) != EC_STATE_SAFE_OP) { printf("SAFE_OP failed\n"); ecx_close(&ctx); return 1; }
   dump_dc(adr, "SAFE_OP");

   /* --- OP --- */
   if (ctx.grouplist[0].Obytes >= 3)
   {
      ctx.grouplist[0].outputs[0] = 255;
      ctx.grouplist[0].outputs[1] = 0;
      ctx.grouplist[0].outputs[2] = 0;
   }
   /* 确认 SAFE_OP 下 SM2 写是否触发过程数据事件 */
   {
      int k;
      for (k = 0; k < 100; k++)
      {
         ecx_send_processdata(&ctx);
         ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
         if (rd32(adr, 0x0440) & 1) break;
         osal_usleep(1000);
      }
      printf("pre-OP: trigger=%d WDst=0x%08X MASK=0x%04X (k=%d)\n",
             (int)(rd32(adr, 0x0440) & 1), (unsigned)rd32(adr, 0x0440),
             rd16(adr, 0x0204), k);
   }

   /* 持续发帧 200ms：让 SYNC0 稳定，同时保持 SM 事件丢失计数为 0 */
   {
      double t_next = now_us();
      double per = (double)cycle_ns / 1000.0;   /* 1 帧/SYNC0 */
      int k;
      for (k = 0; k < 200; k++)
      {
         ecx_send_processdata(&ctx);
         ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
         t_next += per;
         if (t_next < now_us()) t_next = now_us();
         pace_to(t_next);
      }
   }

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   {
      double t_next = now_us();
      /* 每个 SYNC0 周期发送一帧：验证 1 ms PDO + 1 ms SYNC0
         （原为 cycle/2，Windows 上 500 µs 节拍不稳，会累积 SM 事件丢失） */
      double period_us = (double)cycle_ns / 1000.0;
      for (i = 0; i < 30000; i++)   /* 548MHz 下 DC 迁移可能需数秒到十几秒 */
      {
         ecx_send_processdata(&ctx);
         wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
         st = rd16(adr, 0x0130);
         if (i < 5)
            printf("  opw i=%d ALSTAT=0x%04X MASK=0x%04X\n",
                   i, st, rd16(adr, 0x0204));
         if ((st & 0x0F) == EC_STATE_OPERATIONAL) { op_ok = 1; break; }
         if (st & 0x10) break;
         t_next += period_us;
         if (t_next < now_us()) t_next = now_us();
         pace_to(t_next);
      }
   }
   printf("OP: %s ALSTAT=0x%04X ALCODE=0x%04X\n",
          op_ok ? "entered" : "FAILED", st, rd16(adr, 0x0134));
   if (!op_ok)
   {
      dump_dc(adr, "OP failed DC");
      ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
      ctx.slavelist[0].state = EC_STATE_INIT | 0x10;
      ecx_writestate(&ctx, 0);
      ecx_close(&ctx);
      return 1;
   }

   /* 读取同步错误计数器基线 */
   sdo_rd16(0x1C32, 11, &sync_missed0);
   sdo_rd16(0x1C32, 13, &sync_err0);
   printf("sync counters base: missed=%u err=%u\n", sync_missed0, sync_err0);

   /* --- 运行监测（按 DC 周期精确节拍）--- */
   {
      double t_start = now_us();
      double t_end = t_start + (double)secs * 1000000.0;
      double t_next = t_start;
      double period_us = (double)cycle_ns / 1000.0;   /* 1 帧/SYNC0（1ms PDO @ 1ms DC） */
      double last_print = 0.0, last_sdo = 0.0, t_prev = t_start;
      int n = 0, ri = 0, pi = 0;
      int maxn = secs * 1000 + 10;
      uint32_t *rtt = (uint32_t *)malloc(sizeof(uint32_t) * maxn);
      uint32_t *per = (uint32_t *)malloc(sizeof(uint32_t) * maxn);
      while (now_us() < t_end)
      {
         double el, t0, t1;
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
         if (rtt && ri < maxn) rtt[ri++] = (uint32_t)((t1 - t0) + 0.5);
         if (per && pi < maxn && n > 0) per[pi++] = (uint32_t)((t0 - t_prev) + 0.5);
         t_prev = t0;
         st = rd16(adr, 0x0130);
         if ((st & 0x0F) != EC_STATE_OPERATIONAL || (st & 0x10)) bad_stat++;
         if (wkc < 3) bad_wkc++;
         n++;

         el = now_us() - t_start;
         if (el - last_print >= 100000.0)
         {
            uint32 diff = rd32(adr, 0x092C);
            uint16 act = rd16(adr, 0x0980);
            uint32 wdst = rd32(adr, 0x0440);
            printf("t=%5dms ALSTAT=0x%04X ALCODE=0x%04X WKC=%d WDst=0x%08X DCdiff=0x%08X act=0x%02X/0x%02X\n",
                   (int)(el / 1000.0), st, rd16(adr, 0x0134), wkc, (unsigned)wdst, (unsigned)diff,
                   (unsigned)(act & 0xFF), (unsigned)(act >> 8));
            last_print = el;
         }
         if (el - last_sdo >= 1000000.0)
         {
            if (sdo_rd16(0x1C32, 11, &sync_missed) > 0 &&
                sdo_rd16(0x1C32, 13, &sync_err) > 0)
               sync_err_samples++;
            last_sdo = el;
         }
         t_next += period_us;
         if (t_next < now_us()) t_next = now_us();
         pace_to(t_next);
      }
      printf("cycles=%d (%.2f us/cycle)\n", n,
             n ? (now_us() - t_start) / n : 0.0);
      stats("frame RTT", rtt, ri);
      stats("cycle", per, pi);
      free(rtt);
      free(per);
   }

   printf("\n==== DC SUMMARY ====\n");
   printf("OP entered, bad ALSTAT=%d bad WKC=%d\n", bad_stat, bad_wkc);
   printf("sync counters: missed=%u (base %u) err=%u (base %u)\n",
          sync_missed, sync_missed0, sync_err, sync_err0);
   printf("final ALSTAT=0x%04X ALCODE=0x%04X\n", rd16(adr, 0x0130), rd16(adr, 0x0134));
   dump_dc(adr, "final");

   ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
   ctx.slavelist[0].state = EC_STATE_INIT;
   ecx_writestate(&ctx, 0);
   ecx_close(&ctx);
   printf("done\n");
   return 0;
}
