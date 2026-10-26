/* ecat_live.exe <-> Python UI 共享内存
 *
 *  state: "ecat_ui_state"  主站 -> UI，每个周期发布
 *  cmd:   "ecat_ui_cmd"    UI -> 主站，seq 变化时生效
 *
 * 读方：先读 seq，读数据，再读 seq；两次相同才有效。
 * 写方：seq++ -> 写 -> seq++（两次写之间为奇数）。
 */
#ifndef ECAT_UI_SHM_H
#define ECAT_UI_SHM_H

#include <stdint.h>

#define ECAT_UI_STATE_NAME  L"ecat_ui_state"
#define ECAT_UI_CMD_NAME    L"ecat_ui_cmd"
#define ECAT_UI_STATE_MAGIC 0x32545345u   /* "EST2" */
#define ECAT_UI_CMD_MAGIC   0x32434D45u   /* "EMC2" */
#define ECAT_UI_AXES        17

#pragma pack(push,1)

typedef struct
{
    float    pos_deg;
    float    vel_dps;
    float    tor_a;
    float    kp;
    float    kd;
} EcatAxisCmd;

typedef struct
{
    volatile uint32_t seq;
    uint32_t magic;
    uint32_t size;
    uint8_t  ctrl;
    uint8_t  led_mode;
    uint8_t  led_r;
    uint8_t  led_g;
    uint8_t  led_b;
    uint8_t  stop;      /* UI 请求主站优雅退出：回 INIT、关 SYNC0、关网卡 */
    uint8_t  pad[2];
    EcatAxisCmd axis[ECAT_UI_AXES];
} EcatUiCmd;

typedef struct
{
    float    pos_deg;
    float    vel_dps;
    uint16_t status;
    uint16_t id;
    int32_t  pos_raw;
    int16_t  vel_raw;
    uint16_t pad;
} EcatAxisState;

typedef struct
{
    volatile uint32_t seq;
    uint32_t magic;
    uint32_t size;
    uint32_t frame_cnt;
    uint64_t t_us;
    float    fps;
    float    gap_max_ms;
    float    acc[3];
    float    gyro[3];
    int16_t  raw_acc[3];
    int16_t  raw_gyro[3];
    uint16_t wkc;
    uint16_t alstat;
    uint16_t alcode;
    uint16_t temp;
    uint16_t ax_count;
    uint16_t pad0;
    EcatAxisState axis[ECAT_UI_AXES];
    /* 延迟探针：rtt 含 Windows 调度；mcu 为从站 PDI 中断耗时 */
    float    rtt_avg_us;
    float    rtt_min_us;
    float    rtt_max_us;
    float    mcu_avg_us;
    float    mcu_min_us;
    float    mcu_max_us;
} EcatUiState;

#pragma pack(pop)

#endif
