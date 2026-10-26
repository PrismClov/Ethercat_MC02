/* 从 ecat_live.exe 的共享内存读 IMU，做 Mahony 姿态解算，输出欧拉角
 * 用法: mahony_ahrs.exe [kp] [ki] [cal_seconds]
 *   默认 kp=2.0 ki=0.02 cal=2   (cal=0 关闭静止零偏标定)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "imu_shm.h"

#define D2R  0.017453292519943295f
#define R2D  57.29577951308232f

static double now_us(void)
{
    static LONGLONG qpf = 0;
    LARGE_INTEGER c;
    if (!qpf) { QueryPerformanceFrequency(&c); qpf = c.QuadPart; }
    QueryPerformanceCounter(&c);
    return (double)c.QuadPart * 1000000.0 / (double)qpf;
}

/* 返回: 1=读到新数据  0=正在写(稍后再试)  -1=共享内存还没创建 */
static int shm_read(ImuShm *dst)
{
    static HANDLE hMap = NULL;
    static ImuShm *src = NULL;
    uint32_t s1, s2;

    if (!src)
    {
        hMap = OpenFileMappingA(FILE_MAP_READ, FALSE, IMU_SHM_NAME);
        if (!hMap) return -1;
        src = (ImuShm *)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, sizeof(ImuShm));
        if (!src) return -1;
    }
    s1 = src->seq;
    if (s1 & 1u) return 0;
    memcpy(dst, src, sizeof(ImuShm));
    s2 = src->seq;
    if (s1 != s2 || (s2 & 1u)) return 0;
    if (dst->magic != IMU_SHM_MAGIC) return 0;
    return 1;
}

/* Mahony：q 为 w,x,y,z；g 为 rad/s；a 为 m/s^2（内部归一化） */
static void mahony(float *q, const float *g, const float *a, float dt,
                   float kp, float ki, float *ei)
{
    float ax = a[0], ay = a[1], az = a[2];
    float n = sqrtf(ax * ax + ay * ay + az * az);
    float qw = q[0], qx = q[1], qy = q[2], qz = q[3];
    float vx, vy, vz, ex, ey, ez, gx, gy, gz, h;

    if (n < 1e-3f) return;
    ax /= n; ay /= n; az /= n;

    /* 由四元数估计重力方向 */
    vx = 2.0f * (qx * qz - qw * qy);
    vy = 2.0f * (qw * qx + qy * qz);
    vz = qw * qw - qx * qx - qy * qy + qz * qz;

    ex = ay * vz - az * vy;
    ey = az * vx - ax * vz;
    ez = ax * vy - ay * vx;

    if (ki > 0.0f)
    {
        ei[0] += ex * dt;
        ei[1] += ey * dt;
        ei[2] += ez * dt;
    }

    gx = g[0] + kp * ex + ki * ei[0];
    gy = g[1] + kp * ey + ki * ei[1];
    gz = g[2] + kp * ez + ki * ei[2];

    h = 0.5f * dt;
    q[0] += (-qx * gx - qy * gy - qz * gz) * h;
    q[1] += ( qw * gx + qy * gz - qz * gy) * h;
    q[2] += ( qw * gy - qx * gz + qz * gx) * h;
    q[3] += ( qw * gz + qx * gy - qy * gx) * h;

    n = sqrtf(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
    q[0] /= n; q[1] /= n; q[2] /= n; q[3] /= n;
}

static void to_euler(const float *q, float *rpy_deg)
{
    float w = q[0], x = q[1], y = q[2], z = q[3];
    float s = 2.0f * (w * y - z * x);

    if (s > 1.0f) s = 1.0f;
    if (s < -1.0f) s = -1.0f;

    rpy_deg[0] = atan2f(2.0f * (w * x + y * z), 1.0f - 2.0f * (x * x + y * y)) * R2D;
    rpy_deg[1] = asinf(s) * R2D;
    rpy_deg[2] = atan2f(2.0f * (w * z + x * y), 1.0f - 2.0f * (y * y + z * z)) * R2D;
}

static void line(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}

int main(int argc, char *argv[])
{
    float kp = 2.0f, ki = 0.02f;
    int cal_ms = 2000;
    float q[4] = {1, 0, 0, 0};
    float ei[3] = {0, 0, 0};
    float gb[3] = {0, 0, 0};
    ImuShm s;
    uint64_t last_seq = 0, last_t = 0;
    DWORD cmode = 0;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    int samples = 0, rate = 0;
    double t_print = 0, t_cal = 0;
    float rpy[3] = {0, 0, 0}, amag = 0;
    float cal_acc = 0.0f;

    if (argc > 1) kp = (float)atof(argv[1]);
    if (argc > 2) ki = (float)atof(argv[2]);
    if (argc > 3) cal_ms = atoi(argv[3]);

    SetConsoleOutputCP(65001);
    if (GetConsoleMode(hCon, &cmode))
        SetConsoleMode(hCon, cmode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("\x1b[2J\x1b[?25l");

    for (;;)
    {
        {
            int r = shm_read(&s);
            if (r < 0)
            {
                line("\x1b[1;1H\x1b[K等待共享内存 ecat_imu ... 先启动 ecat_live.exe\x1b[K");
                Sleep(200);
                continue;
            }
            if (r == 0) continue;          /* 生产者正在写，下一轮再读 */
        }
        if (s.seq == last_seq) { Sleep(0); continue; }
        last_seq = s.seq;

        if (last_t == 0) { last_t = s.t_us; t_cal = now_us(); continue; }

        {
            float dt = (float)((s.t_us - last_t) * 1e-6);
            last_t = s.t_us;
            if (dt <= 0.0f || dt > 0.05f) continue;

            amag = sqrtf(s.acc_mps2[0] * s.acc_mps2[0] +
                         s.acc_mps2[1] * s.acc_mps2[1] +
                         s.acc_mps2[2] * s.acc_mps2[2]);

            /* 静止零偏标定：开机前 cal_ms 内对角速度求时间平均 */
            if (samples >= 0)
            {
                if (cal_ms > 0 && cal_acc < cal_ms * 1e-3f)
                {
                    gb[0] += s.gyro_rad[0] * dt;
                    gb[1] += s.gyro_rad[1] * dt;
                    gb[2] += s.gyro_rad[2] * dt;
                    cal_acc += dt;
                    samples++;
                    if ((samples & 63) == 0)
                        line("\x1b[1;1H\x1b[K标定中 ... %.1f / %.1f s （保持静止）\x1b[K",
                             cal_acc, cal_ms * 1e-3f);
                    continue;
                }
                if (cal_acc > 0.1f)
                {
                    gb[0] /= cal_acc; gb[1] /= cal_acc; gb[2] /= cal_acc;
                }
                else gb[0] = gb[1] = gb[2] = 0.0f;
                samples = -1;                 /* 只标定一次 */
                q[0] = 1; q[1] = q[2] = q[3] = 0;
                ei[0] = ei[1] = ei[2] = 0;
                printf("\x1b[2J");
            }

            {
                float g[3];
                g[0] = s.gyro_rad[0] - gb[0];
                g[1] = s.gyro_rad[1] - gb[1];
                g[2] = s.gyro_rad[2] - gb[2];
                mahony(q, g, s.acc_mps2, dt, kp, ki, ei);
            }
            to_euler(q, rpy);
            rate++;
        }

        if (now_us() - t_print > 100000.0)
        {
            double el = now_us() - t_print;
            t_print = now_us();
            line("\x1b[1;1H\x1b[KRoll %7.2f  Pitch %7.2f  Yaw %7.2f  deg   \x1b[K",
                 rpy[0], rpy[1], rpy[2]);
            line("\x1b[2;1H\x1b[K|a| %6.2f m/s2   gyro %6.2f %6.2f %6.2f dps   %.0f Hz   \x1b[K",
                 amag,
                 (s.gyro_rad[0] - gb[0]) * R2D,
                 (s.gyro_rad[1] - gb[1]) * R2D,
                 (s.gyro_rad[2] - gb[2]) * R2D,
                 rate * 1e6 / el);
            line("\x1b[3;1H\x1b[Kq = %6.4f %6.4f %6.4f %6.4f   kp=%.2f ki=%.3f\x1b[K",
                 q[0], q[1], q[2], q[3], kp, ki);
            rate = 0;
        }
    }
}
