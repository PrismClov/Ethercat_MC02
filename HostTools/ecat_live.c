/* 17 轴 MIT 实时监视 + 控制（整屏原地刷新）
 * 用法: ecat_live.exe <ifname> [cycle_ns]
 * 按键:
 *   p <轴> <度>        目标位置
 *   v <轴> <度/秒>     目标速度
 *   t <轴> <0.01A>     力矩前馈
 *   kp <轴> <0..500>   Kp
 *   kd <轴> <0..500>   Kd (0.01 定点, 250 = 2.50)
 *   e / d / x          使能 / 失能 / 急停
 *   c <hex>            直接写控制字
 *   q                  退出
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <conio.h>
#include <windows.h>
#include "soem/soem.h"
#include "ecat_ui_shm.h"

static ecx_contextt ctx;
static uint8 io_map[8192];
static LONGLONG qpf;

#define AXES 17
#define ROW_INPUT   9
#define ROW_MSG     10

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

/* ---- PDO 偏移（与固件一致） ---- */
#define OUT_CTRL     0
#define OUT_SEQ      1
#define OUT_AXIS(n)  (4 + 10 * ((n) - 1))
#define IN_IMU       0
#define IN_AXIS(n)   (12 + 10 * ((n) - 1))

/* 0x7050 段：U1..U20 */
#define OUT_RMUI     176
#define OUT_LED_R    (OUT_RMUI + 0)
#define OUT_LED_G    (OUT_RMUI + 1)
#define OUT_LED_B    (OUT_RMUI + 2)
#define OUT_LED_MODE (OUT_RMUI + 19)   /* U20 bit0: 1=用 U1..U3 控制 RGB */

/* ---- 共享内存：给另一个进程（Mahony）读 IMU ---- */
#pragma pack(push,1)
typedef struct
{
   volatile uint32_t seq;        /* 写前 +1(奇)，写后 +1(偶)，读方校验 */
   uint32_t magic;               /* 'IMU1' */
   uint64_t t_us;                /* QPC 微秒 */
   float    acc_mps2[3];         /* m/s^2（注意：不是 g） */
   float    gyro_rad[3];
   int16_t  raw_acc[3];
   int16_t  raw_gyro[3];
   uint16_t temp;
   uint16_t wkc;
   uint16_t alstat;
   uint16_t pad;
} ImuShm;
#pragma pack(pop)

#define SHM_NAME   L"ecat_imu"
#define SHM_MAGIC  0x314D5531u   /* "IMU1" 小端 */
#define ACC_LSB_MPS2  0.00179443359375f   /* BMI088_ACCEL_6G_SEN：m/s^2 每 LSB */
#define GYRO_LSB_RAD  0.00106526443603169529841533860381f

static ImuShm *shm = NULL;
static uint16 last_alstat = 0;
static EcatUiState *ui_state = NULL;
static EcatUiCmd   *ui_cmd   = NULL;
static uint32 last_cmd_seq = 0;
static int    cmd_applied = 0;
static uint32 fps_frames = 0;
static double fps_t0 = 0.0;
static float  fps_val = 0.0f;
static uint32 rtt_n = 0, rtt_sum = 0, rtt_max = 0, rtt_min = 0xFFFFFFFFu;
static uint32 mcu_n = 0, mcu_sum = 0, mcu_max = 0, mcu_min = 0xFFFFFFFFu;
static float  rtt_avg_f = 0, rtt_min_f = 0, rtt_max_f = 0;
static float  mcu_avg_f = 0, mcu_min_f = 0, mcu_max_f = 0;

static uint8 *out;
static uint8 *in;

static int16 rd_i16(const uint8 *p) { return (int16)((uint16)p[0] | ((uint16)p[1] << 8)); }
static uint16 rd_u16(const uint8 *p) { return (uint16)((uint16)p[0] | ((uint16)p[1] << 8)); }
static int32 rd_i32(const uint8 *p)
{
   return (int32)((uint32)p[0] | ((uint32)p[1] << 8) | ((uint32)p[2] << 16) | ((uint32)p[3] << 24));
}
static void wr_i16(uint8 *p, int16 v) { p[0] = (uint8)(v & 0xFF); p[1] = (uint8)((uint16)v >> 8); }
static void wr_u16(uint8 *p, uint16 v) { p[0] = (uint8)(v & 0xFF); p[1] = (uint8)(v >> 8); }
static void wr_u32(uint8 *p, uint32 v)
{
   p[0] = (uint8)(v & 0xFF); p[1] = (uint8)((v >> 8) & 0xFF);
   p[2] = (uint8)((v >> 16) & 0xFF); p[3] = (uint8)((v >> 24) & 0xFF);
}
static uint32 rd_u32(const uint8 *p)
{
   return (uint32)p[0] | ((uint32)p[1] << 8) | ((uint32)p[2] << 16) | ((uint32)p[3] << 24);
}

/* 与固件约定：0x7050 U4..U7 放主站时间戳；0x6000 VT1..VT8 回显与 MCU 计时 */
#define OUT_STAMP_OFF   180
#define IN_ECHO_OFF     182
#define IN_ISR_OFF      186
#define IN_PHASE_OFF    188

static uint8  ctrl_word = 0;
static uint32 seq = 0;
static int    last_wkc = 0;
static uint16 last_alcode = 0;
static double max_gap_us = 0.0;
static double max_draw_us = 0.0;
static char   msg[96] = "";
static char   input[64] = "";
static int    input_len = 0;

/* 把 UI 共享内存里的命令写进输出 PDO。只有 seq 变化（或首次）才执行。 */
static void ui_apply_cmd(void)
{
   int a;
   if (!ui_cmd) return;
   if (cmd_applied && ui_cmd->seq == last_cmd_seq) return;
   if (ui_cmd->magic != ECAT_UI_CMD_MAGIC) return;
   if (ui_cmd->size != (uint32)sizeof(EcatUiCmd)) return;

   last_cmd_seq = ui_cmd->seq;
   cmd_applied = 1;

   ctrl_word = ui_cmd->ctrl;
   out[OUT_RMUI + 0] = ui_cmd->led_r;
   out[OUT_RMUI + 1] = ui_cmd->led_g;
   out[OUT_RMUI + 2] = ui_cmd->led_b;
   out[OUT_LED_MODE] = ui_cmd->led_mode ? 1 : 0;

   for (a = 1; a <= AXES; a++)
   {
      const EcatAxisCmd *c = &ui_cmd->axis[a - 1];
      uint8 *p = out + OUT_AXIS(a);
      float kd = c->kd;
      if (kd < 0.0f) kd = 0.0f;
      if (kd > 500.0f) kd = 500.0f;
      wr_i16(p + 0, (int16)(c->pos_deg * 100.0f));
      wr_i16(p + 2, (int16)(c->vel_dps * 10.0f));
      wr_i16(p + 4, (int16)c->tor_a);
      wr_u16(p + 6, (uint16)c->kp);
      wr_u16(p + 8, (uint16)kd);
   }
}

/* 每周期发布给 UI */
static void ui_publish(void)
{
   int a;
   if (!ui_state) return;

   ui_state->seq++;
   ui_state->magic     = ECAT_UI_STATE_MAGIC;
   ui_state->size      = (uint32)sizeof(EcatUiState);
   ui_state->frame_cnt = seq;
   ui_state->t_us      = (uint64_t)now_us();
   ui_state->gap_max_ms = (float)(max_gap_us / 1000.0);
   ui_state->wkc       = (uint16)last_wkc;
   ui_state->alstat    = last_alstat;
   ui_state->alcode    = last_alcode;
   ui_state->temp      = shm ? shm->temp : 0;
   ui_state->ax_count  = ECAT_UI_AXES;

   for (a = 0; a < 3; a++)
   {
      ui_state->raw_acc[a]  = rd_i16(in + 2 * a);
      ui_state->raw_gyro[a] = rd_i16(in + 6 + 2 * a);
      ui_state->acc[a]      = (float)ui_state->raw_acc[a] * ACC_LSB_MPS2;
      ui_state->gyro[a]     = (float)ui_state->raw_gyro[a] * GYRO_LSB_RAD;
   }

   for (a = 0; a < ECAT_UI_AXES; a++)
   {
      const uint8 *s = in + IN_AXIS(a + 1);
      EcatAxisState *o = &ui_state->axis[a];
      o->pos_raw = rd_i32(s + 2);
      o->vel_raw = rd_i16(s + 6);
      o->status  = rd_u16(s + 8);
      o->id      = (uint16)s[0] | ((uint16)s[1] << 8);
      o->pos_deg = (float)o->pos_raw * 0.01f;
      o->vel_dps = (float)o->vel_raw * 0.1f;
   }

   ui_state->fps = fps_val;
   ui_state->rtt_avg_us = rtt_avg_f;
   ui_state->rtt_min_us = rtt_min_f;
   ui_state->rtt_max_us = rtt_max_f;
   ui_state->mcu_avg_us = mcu_avg_f;
   ui_state->mcu_min_us = mcu_min_f;
   ui_state->mcu_max_us = mcu_max_f;
   ui_state->seq++;
}

/* 一行：内容 + 清到行末（VT 序列），不依赖字节宽度算填充 */
static void line_at(int row, const char *fmt, ...)
{
   va_list ap;
   printf("\x1b[%d;1H", row);
   va_start(ap, fmt);
   vprintf(fmt, ap);
   va_end(ap);
   printf("\x1b[K");
}

static void draw(void)
{
   int a, col;
   const uint8 *s;

   line_at(1, "[ctrl=%02X seq=%u WKC=%d AL=0x%04X ALC=0x%04X]  IMU %d,%d,%d / %d,%d,%d%s",
           ctrl_word, (unsigned)seq, last_wkc,
           last_alstat, last_alcode,
           rd_i16(in + 0), rd_i16(in + 2), rd_i16(in + 4),
           rd_i16(in + 6), rd_i16(in + 8), rd_i16(in + 10),
           shm ? "  [shm]" : "");
   line_at(8, "gap_max=%.1fms  draw_max=%.1fms", max_gap_us / 1000.0, max_draw_us / 1000.0);

   for (a = 1; a <= AXES; a++)
   {
      s = in + IN_AXIS(a);
      col = (a - 1) % 3;
      if (col == 0) printf("\x1b[%d;1H", 1 + (a + 2) / 3);
      printf("%02d %9.2f %6.1f %c%c%c%s",
             a, rd_i32(s + 2) * 0.01, rd_i16(s + 6) * 0.1,
             (rd_u16(s + 8) & 0x01) ? 'E' : '-',
             (rd_u16(s + 8) & 0x02) ? 'F' : '-',
             (rd_u16(s + 8) & 0x20) ? 'V' : '-',
             (col == 2) ? "\x1b[K" : " | ");
   }
   if (AXES % 3) printf("\x1b[K");

   line_at(ROW_INPUT, "> %s", input);
   line_at(ROW_MSG, "%s", msg);
}

static void apply_cmd(char *line)
{
   char cmd[8] = {0};
   int axis = 0;
   double val = 0;
   uint8 *c;

   if (sscanf(line, "%7s %d %lf", cmd, &axis, &val) < 1) return;

   if (cmd[0] == 'q') { printf("\x1b[?25h\x1b[%d;1H\n", ROW_MSG + 1); exit(0); }
   if (cmd[0] == 'e' && !cmd[1]) { ctrl_word |= 0x01; snprintf(msg, sizeof msg, ">> enable  ctrl=0x%02X", ctrl_word); return; }
   if (cmd[0] == 'd' && !cmd[1]) { ctrl_word &= (uint8)~0x01; snprintf(msg, sizeof msg, ">> disable ctrl=0x%02X", ctrl_word); return; }
   if (cmd[0] == 'x' && !cmd[1]) { ctrl_word |= 0x02; snprintf(msg, sizeof msg, ">> ESTOP   ctrl=0x%02X", ctrl_word); return; }
   if (cmd[0] == 'c') { ctrl_word = (uint8)strtoul(line + 1, NULL, 16); snprintf(msg, sizeof msg, ">> ctrl=0x%02X", ctrl_word); return; }
   if (!strcmp(cmd, "led"))
   {
      int r = 0, g = 0, b = 0;
      if (strstr(line, "off")) { out[OUT_LED_MODE] = 0; snprintf(msg, sizeof msg, ">> led: 状态色模式"); return; }
      if (sscanf(line, "%*s %d %d %d", &r, &g, &b) == 3)
      {
         out[OUT_LED_R] = (uint8)r; out[OUT_LED_G] = (uint8)g; out[OUT_LED_B] = (uint8)b;
         out[OUT_LED_MODE] = 1;
         snprintf(msg, sizeof msg, ">> led R=%d G=%d B=%d", r, g, b);
      }
      else snprintf(msg, sizeof msg, "!! led <r> <g> <b>  |  led off");
      return;
   }

   if (axis < 1 || axis > AXES) { snprintf(msg, sizeof msg, "!! axis 1..%d", AXES); return; }
   c = out + OUT_AXIS(axis);

   if (!strcmp(cmd, "p"))       { wr_i16(c + 0, (int16)(val * 100.0)); snprintf(msg, sizeof msg, ">> ax%d pos=%.2f deg", axis, val); }
   else if (!strcmp(cmd, "v"))  { wr_i16(c + 2, (int16)(val * 10.0));  snprintf(msg, sizeof msg, ">> ax%d vel=%.1f deg/s", axis, val); }
   else if (!strcmp(cmd, "t"))  { wr_i16(c + 4, (int16)val);           snprintf(msg, sizeof msg, ">> ax%d tor=%.2f A", axis, val * 0.01); }
   else if (!strcmp(cmd, "kp")) { wr_u16(c + 6, (uint16)val);          snprintf(msg, sizeof msg, ">> ax%d Kp=%.0f", axis, val); }
   else if (!strcmp(cmd, "kd")) { wr_u16(c + 8, (uint16)val);          snprintf(msg, sizeof msg, ">> ax%d Kd=%.2f", axis, val * 0.01); }
   else snprintf(msg, sizeof msg, "!! unknown cmd");
}

int main(int argc, char *argv[])
{
   uint32 cycle_ns = 2000000;
   uint16 adr, st = 0;
   int i;
   int headless = 0;
   double t_next, t_show = 0;
   DWORD cmode = 0;
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

   SetConsoleOutputCP(65001);          /* UTF-8，避免中文乱码 */
   SetConsoleCP(65001);
   if (GetConsoleMode(hCon, &cmode))
      SetConsoleMode(hCon, cmode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
   setvbuf(stdout, NULL, _IONBF, 0);

   { LARGE_INTEGER f; QueryPerformanceFrequency(&f); qpf = f.QuadPart; }
   if (argc < 2) { printf("usage: %s <ifname> [cycle_ns] [--headless]\n", argv[0]); return 1; }
   if (argc >= 3) cycle_ns = (uint32)strtoul(argv[2], NULL, 0);
   for (i = 3; i < argc; i++) if (!strcmp(argv[i], "--headless")) headless = 1;

   if (!headless) printf("\x1b[2J\x1b[?25l");
   printf("connecting ...\n");

   if (!ecx_init(&ctx, argv[1])) { printf("\x1b[?25h" "ecx_init failed\n"); return 1; }
   if (ecx_config_init(&ctx) <= 0) { printf("\x1b[?25h" "no slaves\n"); ecx_close(&ctx); return 1; }
   adr = ctx.slavelist[1].configadr;
   printf("slave1 cfgadr=0x%04X cycle=%uns\n", adr, (unsigned)cycle_ns);

   ctx.slavelist[1].state = EC_STATE_INIT | 0x10;
   ecx_writestate(&ctx, 1);
    for (i = 0; i < 1500; i++) { st = rd16(adr, 0x0130); if ((st & 0x0F) == EC_STATE_INIT) break; osal_usleep(1000); }
   ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
   osal_usleep(10000);

   ctx.slavelist[1].state = EC_STATE_PRE_OP;
   ecx_writestate(&ctx, 1);
    for (i = 0; i < 1500; i++) { st = rd16(adr, 0x0130); if ((st & 0x0F) == EC_STATE_PRE_OP) break; osal_usleep(1000); }
   if ((st & 0x0F) != EC_STATE_PRE_OP) { printf("\x1b[?25h" "PREOP failed\n"); ecx_close(&ctx); return 1; }
   osal_usleep(10000);

   { uint16_t wd = htoes(0x03E8); ecx_FPWR(&ctx.port, adr, 0x0420, 2, &wd, EC_TIMEOUTRET); }
   sdo_wr16(0x1C32, 1, 2);
   sdo_wr32(0x1C32, 2, cycle_ns);
   sdo_wr16(0x1C33, 1, 2);
   sdo_wr32(0x1C33, 2, cycle_ns);
   sdo_wr16(0x10F1, 2, 1000);
   ecx_configdc(&ctx);
   ecx_dcsync0(&ctx, 1, TRUE, cycle_ns, 0);
   osal_usleep(10000);

   if (!ecx_config_map_group(&ctx, io_map, 0))
   {
      printf("\x1b[?25h" "config_map_group failed\n");
      ecx_close(&ctx);
      return 1;
   }

   st = wait_state(adr, EC_STATE_SAFE_OP, 2000);
   if ((st & 0x0F) != EC_STATE_SAFE_OP) { printf("\x1b[?25h" "SAFEOP failed 0x%04X\n", st); ecx_close(&ctx); return 1; }
   ctx.slavelist[0].state = EC_STATE_OPERATIONAL;
   ecx_writestate(&ctx, 0);
   st = wait_state(adr, EC_STATE_OPERATIONAL, 5000);
   if ((st & 0x0F) != EC_STATE_OPERATIONAL) { printf("\x1b[?25h" "OP failed 0x%04X\n", st); ecx_close(&ctx); return 1; }

   out = (uint8 *)ctx.grouplist[0].outputs;
   in  = (uint8 *)ctx.grouplist[0].inputs;
   memset(out, 0, ctx.grouplist[0].Obytes);

   /* IMU 共享内存：另一个进程用 OpenFileMapping("ecat_imu") 读取 */
   {
      HANDLE hMap = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                                       0, sizeof(ImuShm), SHM_NAME);
      if (hMap)
      {
         shm = (ImuShm *)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(ImuShm));
         if (shm) { memset(shm, 0, sizeof(ImuShm)); shm->magic = SHM_MAGIC; }
      }
   }

   /* Python UI 的状态 / 命令共享内存 */
   {
      HANDLE hm = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                                     0, sizeof(EcatUiState), ECAT_UI_STATE_NAME);
      if (hm)
      {
         ui_state = (EcatUiState *)MapViewOfFile(hm, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(EcatUiState));
         if (ui_state) { memset(ui_state, 0, sizeof(EcatUiState)); ui_state->magic = ECAT_UI_STATE_MAGIC; ui_state->size = (uint32)sizeof(EcatUiState); }
      }
      hm = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                              0, sizeof(EcatUiCmd), ECAT_UI_CMD_NAME);
      if (hm)
      {
         ui_cmd = (EcatUiCmd *)MapViewOfFile(hm, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(EcatUiCmd));
         if (ui_cmd) ui_cmd->stop = 0;   /* 清掉上一次遗留的退出请求 */
      }
   }

   fps_t0 = now_us();

   snprintf(msg, sizeof msg, "out=%u in=%u shm=%s | p/v/t/kp/kd <ax> <v>  led <r> <g> <b>  e/d/x  q",
            (unsigned)ctx.grouplist[0].Obytes, (unsigned)ctx.grouplist[0].Ibytes,
            shm ? "on" : "off");
    if (!headless) printf("\x1b[2J");

   t_next = now_us();
   {
      double t_prev = t_next;
   for (;;)
   {
      double per = (double)cycle_ns / 1000.0;
      int wkc;
      double t_now = now_us();

      if (t_now - t_prev > max_gap_us) max_gap_us = t_now - t_prev;
      t_prev = t_now;

      ui_apply_cmd();

      if (ui_cmd && ui_cmd->stop) break;

      out[OUT_CTRL] = ctrl_word;
      out[OUT_SEQ + 0] = (uint8)(seq & 0xFF);
      out[OUT_SEQ + 1] = (uint8)((seq >> 8) & 0xFF);
      out[OUT_SEQ + 2] = (uint8)((seq >> 16) & 0xFF);
      wr_u32(out + OUT_STAMP_OFF, (uint32)t_now);
      seq++;

      ecx_send_processdata(&ctx);
      wkc = ecx_receive_processdata(&ctx, EC_TIMEOUTRET);
      last_wkc = wkc;

      {
         /* RTT（含 Windows 调度）：主站写戳 -> 从站回显 -> 主站收到 */
         uint32 t_rx  = (uint32)now_us();
         uint32 echo  = rd_u32(in + IN_ECHO_OFF);
         uint16 mcu   = rd_u16(in + IN_ISR_OFF);
         if (echo != 0)
         {
            uint32 rtt = t_rx - echo;      /* 无符号相减，自动处理回绕 */
            if (rtt < 100000u)
            {
               rtt_n++; rtt_sum += rtt;
               if (rtt < rtt_min) rtt_min = rtt;
               if (rtt > rtt_max) rtt_max = rtt;
            }
         }
         if (mcu != 0)
         {
            mcu_n++; mcu_sum += mcu;
            if (mcu < mcu_min) mcu_min = mcu;
            if (mcu > mcu_max) mcu_max = mcu;
         }
      }

      if (shm)
      {
         int k;
         shm->seq++;
         shm->t_us = (uint64_t)now_us();
         for (k = 0; k < 3; k++)
         {
            shm->raw_acc[k]  = rd_i16(in + 2 * k);
            shm->raw_gyro[k] = rd_i16(in + 6 + 2 * k);
            shm->acc_mps2[k] = (float)shm->raw_acc[k]  * ACC_LSB_MPS2;
            shm->gyro_rad[k] = (float)shm->raw_gyro[k] * GYRO_LSB_RAD;
         }
         shm->wkc    = (uint16_t)last_wkc;
         shm->alstat = last_alstat;
         shm->seq++;
      }

      ui_publish();

      fps_frames++;
      if (t_now - fps_t0 >= 250000.0)
      {
         float inst = (float)(fps_frames * 1000000.0 / (t_now - fps_t0));
         fps_val = (fps_val > 0.0f) ? (0.7f * fps_val + 0.3f * inst) : inst;
         fps_frames = 0;
         fps_t0 = t_now;

         if (rtt_n)
         {
            rtt_avg_f = (float)rtt_sum / (float)rtt_n;
            rtt_min_f = (float)rtt_min;
            rtt_max_f = (float)rtt_max;
            rtt_n = 0; rtt_sum = 0; rtt_max = 0; rtt_min = 0xFFFFFFFFu;
         }
         if (mcu_n)
         {
            mcu_avg_f = (float)mcu_sum / (float)mcu_n;
            mcu_min_f = (float)mcu_min;
            mcu_max_f = (float)mcu_max;
            mcu_n = 0; mcu_sum = 0; mcu_max = 0; mcu_min = 0xFFFFFFFFu;
         }
      }

      while (!headless && _kbhit())
      {
         int ch = _getch();
         if (ch == '\r' || ch == '\n')
         {
            input[input_len] = 0;
            if (input_len) apply_cmd(input);
            input_len = 0; input[0] = 0;
            draw();
         }
         else if (ch == 8)
         {
            if (input_len) { input_len--; input[input_len] = 0; draw(); }
         }
         else if (ch >= 32 && input_len < (int)sizeof(input) - 1)
         {
            input[input_len++] = (char)ch; input[input_len] = 0; draw();
         }
      }

      if (now_us() - t_show > 200000.0)
      {
         double d0 = now_us();
         t_show = now_us();
         last_alstat = rd16(adr, 0x0130);
         last_alcode = rd16(adr, 0x0134);
         if (!headless)
         {
            draw();
            if (now_us() - d0 > max_draw_us) max_draw_us = now_us() - d0;
         }
      }

      t_next += per;
      if (t_next < now_us()) t_next = now_us();
      pace_to(t_next);
   }
   }

   /* 优雅退出：关 SYNC0、从站回 INIT，下一次启动不用再复位 MCU */
   ecx_dcsync0(&ctx, 1, FALSE, cycle_ns, 0);
   osal_usleep(10000);
   ctx.slavelist[1].state = EC_STATE_INIT | 0x10;
   ecx_writestate(&ctx, 1);
   osal_usleep(50000);
   ecx_close(&ctx);
   return 0;
}
