/* 读 PDO 分配/映射与 SM 长度，确认当前布局（只读，不改变从站状态） */
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

static int sdo_rd16(uint16 idx, uint8 sub, uint16 *val)
{
   int sz = 2, w;
   *val = 0;
   w = ecx_SDOread(&ctx, 1, idx, sub, FALSE, &sz, val, EC_TIMEOUTRXM);
   return w;
}

static void show16(uint16 idx, uint8 sub, const char *label)
{
   uint16 v = 0;
   int w = sdo_rd16(idx, sub, &v);
   printf("%-22s 0x%04X:%02X = %u   (wkc=%d)\n", label, idx, sub, (unsigned)v, w);
}

int main(int argc, char *argv[])
{
   int i;
   uint16 st = 0, adr;

   setvbuf(stdout, NULL, _IONBF, 0);
   if (argc < 2) { printf("usage: %s <ifname>\n", argv[0]); return 1; }

   if (!ecx_init(&ctx, argv[1])) { printf("ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X\n\n", adr);

   ctx.slavelist[1].state = EC_STATE_INIT | 0x10;
   ecx_writestate(&ctx, 1);
   for (i = 0; i < 500; i++)
   {
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_INIT) break;
      osal_usleep(1000);
   }
   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   /* 关掉可能残留的 SYNC0，否则上一轮 DC 测试的同步仍在跑，邮箱会变慢 */
   ecx_dcsync0(&ctx, 1, FALSE, 2000000, 0);
   osal_usleep(10000);
   ecx_writestate(&ctx, 1);
   for (i = 0; i < 500; i++)
   {
      st = rd16(adr, 0x0130);
      if ((st & 0x0F) == EC_STATE_PRE_OP) break;
      osal_usleep(1000);
      ecx_send_processdata(&ctx);
      ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
   }
   printf("state ALSTAT=0x%04X\n\n", st);
   if ((st & 0x0F) != EC_STATE_PRE_OP) { printf("not PREOP, abort\n"); ecx_close(&ctx); return 1; }
   osal_usleep(10000);   /* 等邮箱稳定，否则前几次 SDO 会 wkc=0 */

   printf("--- SM 长度 (ESC 寄存器) ---\n");
   printf("SM2 (out) len = %u\n", (unsigned)rd16(adr, 0x0812));
   printf("SM3 (in)  len = %u\n\n", (unsigned)rd16(adr, 0x081A));

   printf("--- PDO 分配 ---\n");
   show16(0x1C12, 0, "RxPDO assign count");
   show16(0x1C12, 1, "RxPDO assign[1]");
   show16(0x1C13, 0, "TxPDO assign count");
   show16(0x1C13, 1, "TxPDO assign[1]");
   printf("\n");

   printf("--- RxPDO 映射 0x1600 ---\n");
   show16(0x1600, 0, "entries");
   show16(0x1600, 1, "first");
   show16(0x1600, 68, "idx68");
   show16(0x1600, 69, "idx69");
   show16(0x1600, 128, "idx128");
   show16(0x1600, 196, "idx196");
   printf("\n");

   printf("--- TxPDO 映射 0x1A00 ---\n");
   show16(0x1A00, 0, "entries");
   show16(0x1A00, 1, "first");
   show16(0x1A00, 204, "idx204");
   show16(0x1A00, 205, "idx205");
   show16(0x1A00, 216, "idx216");
   show16(0x1A00, 217, "idx217");
   show16(0x1A00, 416, "idx416");
   printf("\n");

   printf("--- 记录子索引数 ---\n");
   show16(0x6000, 0, "0x6000 sub0");
   show16(0x60F0, 0, "0x60F0 sub0");
   show16(0x7000, 0, "0x7000 sub0");
   show16(0x7050, 0, "0x7050 sub0");

   ecx_close(&ctx);
   return 0;
}
