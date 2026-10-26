/* 2 kHz PDO 数据完整性探针（无重绘、无交互）
 * 逐帧检查输入区是否全 0，并统计实际发帧间隔。
 * 用法: ecat_zero_probe.exe <ifname> [seconds] [cycle_ns]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "soem/soem.h"

static ecx_contextt ctx;
static uint8 io_map[8192];
static LONGLONG qpf;

static double now_us(void)
{
   LARGE_INTEGER c;
   QueryPerformanceCounter(&c);
   return (double)c.QuadPart * 1000000.0 / (double)qpf;
}

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

static uint16 rd16(uint16 adr, uint16 reg)
{
   uint16 v = 0;
   ecx_FPRD(&ctx.port, adr, reg, 2, &v, EC_TIMEOUTRET);
   return etohs(v);
}

static int sdo_wr16(uint16 idx, uint8 sub, uint16 val)
{
   return ecx_SDOwrite(&ctx, 1, idx, sub, FALSE, 2, &val, EC_TIMEOUTRXM);
}

static int sdo_wr32(uint16 idx, uint8 sub, uint32 val)
{
   return ecx_SDOwrite(&ctx, 1, idx, sub, FALSE, 4, &val, EC_TIMEOUTRXM);
}

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

static int all_zero(const uint8 *p, int n)
{
   int i;
   for (i = 0; i < n; i++) if (p[i]) return 0;
   return 1;
}

int main(int argc, char *argv[])
{
   uint16 adr, st;
   uint32 cycle_ns = 1000000;
   int secs = 10, i;
   uint8 *in;
   uint32 nframe = 0, nzero_all = 0, nzero_6000 = 0, nzero_axis = 0;
   uint32 nwkc_bad = 0, nal_bad = 0, run = 0, run_max = 0;
   uint32 gap_max_us = 0, gap_over_cycle = 0;
   uint32 al_last = 0xFFFF, alcode_last = 0xFFFF;
   double t_start, t_end, t_next, period_us;

   QueryPerformanceFrequency((LARGE_INTEGER *)&qpf);

   if (argc < 2) { printf("usage: %s <ifname> [seconds] [cycle_ns]\n", argv[0]); return 1; }
   if (argc >= 3) secs = atoi(argv[2]);
   if (argc >= 4) cycle_ns = (uint32)strtoul(argv[3], NULL, 0);
   if (secs <= 0) secs = 10;

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;

   ctx.slavelist[1].state = EC_STATE_INIT | 0x10;
   ecx_writestate(&ctx, 1);
   for (i = 0; i < 500; i++)
   {
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_INIT) break;
      osal_usleep(1000);
   }
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
   if ((st & 0x0F) != EC_STATE_PRE_OP) { printf("PREOP failed 0x%04X\n", st); ecx_close(&ctx); return 1; }

   { uint16 wd = htoes(0x03E8); ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET); }
   sdo_wr16(0x1C32, 1, 2);
   sdo_wr32(0x1C32, 2, cycle_ns);
   sdo_wr16(0x1C33, 1, 2);
   sdo_wr32(0x1C33, 2, cycle_ns);
   sdo_wr16(0x10F1, 2, 1000);
   ecx_configdc(&ctx);
   ecx_dcsync0(&ctx, 1, TRUE, cycle_ns, 0);
   osal_usleep(10000);

   if (!ecx_config_map_group(&ctx, io_map, 0)) { printf("map failed\n"); ecx_close(&ctx); return 1; }
   st = wait_state(adr, EC_STATE_SAFE_OP, 2000);
   if ((st & 0x0F) != EC_STATE_SAFE_OP) { printf("SAFEOP failed 0x%04X\n", st); ecx_close(&ctx); return 1; }

   period_us = (double)cycle_ns / 1000.0;
   t_next = now_us();
   for (i = 0; i < 200; i++)
   {
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      t_next += period_us;
      if (t_next < now_us()) t_next = now_us();
      pace_to(t_next);
   }

   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   t_next = now_us();
   for (i = 0; i < 30000; i++)
   {
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_OPERATIONAL) break;
      if (st & 0x10) break;
      t_next += period_us;
      if (t_next < now_us()) t_next = now_us();
      pace_to(t_next);
   }
   printf("cfgadr=0x%04X cycle=%uns OP=0x%04X ALCODE=0x%04X\n",
          adr, (unsigned)cycle_ns, st, rd16(adr, 0x0134));
   if ((st & 0x0F) != EC_STATE_OPERATIONAL) { ecx_close(&ctx); return 1; }

   in = (uint8 *)ctx.grouplist[0].inputs;

   t_start = now_us();
   t_end = t_start + (double)secs * 1000000.0;
   t_next = t_start;
   {
      double t_prev = t_start;
      int al_div = 0;
      while (now_us() < t_end)
      {
         double t_now = now_us();
         uint32 gap = (uint32)(t_now - t_prev);
         int wkc;

         if (gap > gap_max_us) gap_max_us = gap;
         if (gap > (uint32)(period_us * 1.5)) gap_over_cycle++;
         t_prev = t_now;

         ecx_send_processdata(&ctx);
         wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
         if (wkc <= 0) nwkc_bad++;
         nframe++;

         if (all_zero(in, ctx.grouplist[0].Ibytes))
         {
            nzero_all++;
            run++;
            if (run > run_max) run_max = run;
         }
         else
         {
            run = 0;
            if (all_zero(in, 204)) nzero_6000++;
            if (all_zero(in + 12, 192)) nzero_axis++;
         }

         if (++al_div >= 100)
         {
            al_div = 0;
            al_last = rd16(adr, 0x0130);
            alcode_last = rd16(adr, 0x0134);
            if ((al_last & 0x0F) != EC_STATE_OPERATIONAL) nal_bad++;
         }

         t_next += period_us;
         if (t_next < now_us()) t_next = now_us();
         pace_to(t_next);
      }
   }

   printf("frames=%u  avg_period=%.1fus  zero_all=%u  zero_0x6000_only=%u  zero_axis_only=%u\n",
          nframe, nframe ? (now_us() - t_start) / nframe : 0.0,
          nzero_all, nzero_6000, nzero_axis);
   printf("max_zero_run=%u  wkc_bad=%u  al_bad=%u  gap_max=%.2fms  gap>1.5T=%u\n",
          run_max, nwkc_bad, nal_bad, gap_max_us / 1000.0, gap_over_cycle);
   printf("final AL=0x%04X ALC=0x%04X\n", al_last, alcode_last);

   ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
   ecx_close(&ctx);
   return 0;
}
