/* ecat_live.exe 发布的 IMU 共享内存
 * 名字:  "ecat_imu"  (CreateFileMapping / OpenFileMapping)
 * 大小:  60 字节
 * 读法:  读 seq -> 读数据 -> 再读 seq，两次相同且为偶数则数据有效
 */
#ifndef IMU_SHM_H
#define IMU_SHM_H

#include <stdint.h>

#pragma pack(push,1)
typedef struct
{
    volatile uint32_t seq;        /* 奇数=正在写，偶数=稳定 */
    uint32_t magic;               /* 0x314D5531 ("IMU1") */
    uint64_t t_us;                /* 主机 QPC 时间戳，微秒 */
    float    acc_mps2[3];         /* 加速度，单位 m/s^2  (±6g 量程，静止约 9.81) */
    float    gyro_rad[3];         /* 角速度，单位 rad/s  (±2000dps 量程) */
    int16_t  raw_acc[3];          /* 原始 LSB，0.0017944 m/s^2 每 LSB */
    int16_t  raw_gyro[3];         /* 原始 LSB，0.00106526 rad/s/LSB */
    uint16_t temp;                /* 预留，当前为 0 */
    uint16_t wkc;                 /* 工作计数器，正常 3 */
    uint16_t alstat;              /* AL 状态，0x0008 = OP */
    uint16_t pad;
} ImuShm;
#pragma pack(pop)

#define IMU_SHM_NAME   "ecat_imu"
#define IMU_SHM_SIZE   ((int)sizeof(ImuShm))
#define IMU_SHM_MAGIC  0x314D5531u

#endif
