#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include "soem/soem.h"
#include "ecat_ui_shm.h"

#include <fcntl.h>
#include <errno.h>
#include <getopt.h>
#include <inttypes.h>
#include <net/if.h>
#include <sched.h>
#include <signal.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define IO_MAP_SIZE          (64U * 1024U)
#define DEFAULT_CYCLE_NS     2000000U
#define MAX_CYCLE_NS         100000000U
#define MC02_VENDOR_ID       0x000004D8U
#define MC02_PRODUCT_CODE    0x00009252U

#define STATE_SHM_NAME       "/ecat_ui_state"
#define CMD_SHM_NAME         "/ecat_ui_cmd"

#define OUT_CTRL             0U
#define OUT_SEQ              1U
#define OUT_AXIS(n)          (4U + 10U * ((n) - 1U))
#define IN_IMU               0U
#define IN_AXIS(n)           (12U + 10U * ((n) - 1U))
#define OUT_RMUI             176U
#define OUT_LED_R            (OUT_RMUI + 0U)
#define OUT_LED_G            (OUT_RMUI + 1U)
#define OUT_LED_B            (OUT_RMUI + 2U)
#define OUT_LED_MODE         (OUT_RMUI + 19U)
#define OUT_STAMP_OFF        180U
#define IN_ECHO_OFF          182U
#define IN_ISR_OFF           186U
#define IN_PHASE_OFF         188U
#define ACC_LSB_MPS2         0.00179443359375f
#define GYRO_LSB_RAD         0.0010652644360316953f

typedef struct
{
    const char *ifname;
    uint32_t cycle_ns;
    uint32_t duration_s;
    int state_timeout_ms;
    int rt_priority;
    int cpu;
    int32_t dc_lead_ns;
    bool list_adapters;
    bool enable_dc;
    bool profile_mc02;
    bool preop_only;
    bool verbose;
    bool lock_memory;
} MasterOptions;

typedef struct
{
    ecx_contextt ctx;
    uint8_t iomap[IO_MAP_SIZE];
    uint8_t group;
    uint32_t cycle_ns;
    bool socket_open;
    bool mapped;
    bool dc_active;
    uint16_t profile_slaves;
    EcatUiState *ui_state;
    EcatUiCmd *ui_cmd;
    void *state_mapping;
    void *cmd_mapping;
    size_t state_mapping_size;
    size_t cmd_mapping_size;
    uint32_t last_cmd_seq;
    uint32_t frame_count;
    uint64_t start_ns;
    uint64_t previous_cycle_ns;
    uint64_t fps_start_ns;
    uint32_t fps_frames;
    float fps;
    float max_gap_ms;
    uint16_t phase_us;
    uint16_t phase_max_us;
    uint64_t phase_count;
    uint64_t phase_sum_us;
    uint32_t phase_min_us;
    uint32_t phase_run_max_us;
    uint64_t phase_overflow;
    uint32_t phase_histogram[2001];
    uint64_t dc_phase_count;
    uint64_t dc_phase_sum_ns;
    uint32_t dc_phase_min_ns;
    uint32_t dc_phase_max_ns;
    uint32_t rtt_count;
    uint32_t rtt_sum_us;
    uint32_t rtt_min_us;
    uint32_t rtt_max_us;
    uint32_t mcu_count;
    uint32_t mcu_sum_us;
    uint32_t mcu_min_us;
    uint32_t mcu_max_us;
    uint16_t last_al_state;
    uint16_t last_al_code;
    uint64_t next_ui_publish_ns;
} Master;

static volatile sig_atomic_t g_running = 1;

static uint64_t now_ns(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
    {
        return 0;
    }
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}

static void sleep_until_ns(uint64_t deadline)
{
    struct timespec target;
    int result;

    target.tv_sec = (time_t)(deadline / 1000000000ULL);
    target.tv_nsec = (long)(deadline % 1000000000ULL);
    do
    {
        result = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &target, NULL);
    } while (result == EINTR);
}

static void on_signal(int signo)
{
    (void)signo;
    g_running = 0;
}

static void install_signal_handlers(void)
{
    struct sigaction action;

    memset(&action, 0, sizeof(action));
    action.sa_handler = on_signal;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
}

static void configure_cpu_and_memory(const MasterOptions *options)
{
    if (options->cpu >= 0)
    {
        cpu_set_t set;

        CPU_ZERO(&set);
        CPU_SET(options->cpu, &set);
        if (sched_setaffinity(0, sizeof(set), &set) != 0)
        {
            fprintf(stderr, "CPU 绑定失败: %s\n", strerror(errno));
        }
        else
        {
            printf("主站线程已绑定到 CPU%d。\n", options->cpu);
        }
    }

    if (options->lock_memory && (mlockall(MCL_CURRENT | MCL_FUTURE) != 0))
    {
        fprintf(stderr, "内存锁定失败: %s；继续运行。\n", strerror(errno));
    }
}

static void enable_realtime_scheduler(int priority)
{
    struct sched_param parameter;

    if (priority <= 0)
    {
        return;
    }
    memset(&parameter, 0, sizeof(parameter));
    parameter.sched_priority = priority;
    if (sched_setscheduler(0, SCHED_FIFO, &parameter) != 0)
    {
        fprintf(stderr,
                "SCHED_FIFO 设置失败: %s；需要 CAP_SYS_NICE，继续普通调度。\n",
                strerror(errno));
    }
    else
    {
        printf("主站线程已启用 SCHED_FIFO 优先级 %d。\n", priority);
    }
}

static bool print_adapters(void)
{
    struct if_nameindex *names;
    struct if_nameindex *adapter;

    /*
     * SOEM 2.0.0 的 oshw_find_adapters() 在 if_nameindex() 返回 NULL 时会解引用
     * 空指针。这里直接处理该 POSIX 边界情况，避免无网卡环境直接崩溃。
     */
    names = if_nameindex();
    if (names == NULL)
    {
        fprintf(stderr, "枚举网卡失败: %s\n", strerror(errno));
        return false;
    }

    puts("可用 EtherCAT 网卡：");
    for (adapter = names; adapter->if_index != 0; adapter++)
    {
        printf("  %d  %s\n", (int)adapter->if_index, adapter->if_name);
    }
    if_freenameindex(names);
    return true;
}

static void print_usage(const char *program)
{
    printf(
        "用法:\n"
        "  %s --list\n"
        "  %s -i <网卡> [选项]\n\n"
        "选项:\n"
        "  -i, --ifname <网卡>        EtherCAT 专用网卡，例如 eth1\n"
        "  -c, --cycle-us <微秒>       主站发送周期，默认 2000\n"
        "      --cycle-ns <纳秒>       Web UI 使用的精确周期设置\n"
        "  -t, --duration <秒>         运行时间，0 表示直到 Ctrl+C，默认 0\n"
        "  -s, --state-timeout <毫秒>  状态切换超时，默认 10000\n"
        "      --cpu <编号>             固定主站线程到指定 CPU\n"
        "      --rt-priority <1..99>    使用 SCHED_FIFO 实时调度\n"
        "      --lock-memory            锁定主站内存，避免缺页抖动\n"
        "      --profile mc02          配置本项目 MC02 从站的 SYNC0/PDO 参数\n"
        "      --dc                    启用 SOEM 分布式时钟与 SYNC0\n"
        "      --dc-lead-us <微秒>     将发送相位锁到 SYNC0 前指定时间\n"
        "      --preop-only            只配置到 Pre-Op，不进入过程数据阶段\n"
        "  -v, --verbose               每秒打印过程数据前 32 字节\n"
        "  -l, --list                  列出网卡\n"
        "  -h, --help                  显示帮助\n\n"
        "安全说明：输出 PDO 在进入 OP 前全部清零；本程序不会使能电机。\n",
        program, program);
}

static bool parse_u32(const char *text, uint32_t *value)
{
    char *end = NULL;
    unsigned long parsed;

    errno = 0;
    parsed = strtoul(text, &end, 0);
    if ((errno != 0) || (end == text) || (*end != '\0') || (parsed > UINT32_MAX))
    {
        return false;
    }
    *value = (uint32_t)parsed;
    return true;
}

static bool parse_options(int argc, char **argv, MasterOptions *options)
{
    enum
    {
        OPT_PROFILE = 1000,
        OPT_DC,
        OPT_PREOP_ONLY,
        OPT_CYCLE_NS,
        OPT_CPU,
        OPT_RT_PRIORITY,
        OPT_LOCK_MEMORY,
        OPT_DC_LEAD_US
    };
    static const struct option long_options[] = {
        {"ifname", required_argument, NULL, 'i'},
        {"cycle-us", required_argument, NULL, 'c'},
        {"cycle-ns", required_argument, NULL, OPT_CYCLE_NS},
        {"duration", required_argument, NULL, 't'},
        {"state-timeout", required_argument, NULL, 's'},
        {"cpu", required_argument, NULL, OPT_CPU},
        {"rt-priority", required_argument, NULL, OPT_RT_PRIORITY},
        {"lock-memory", no_argument, NULL, OPT_LOCK_MEMORY},
        {"profile", required_argument, NULL, OPT_PROFILE},
        {"dc", no_argument, NULL, OPT_DC},
        {"dc-lead-us", required_argument, NULL, OPT_DC_LEAD_US},
        {"preop-only", no_argument, NULL, OPT_PREOP_ONLY},
        {"verbose", no_argument, NULL, 'v'},
        {"list", no_argument, NULL, 'l'},
        {"help", no_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}
    };
    int option;

    memset(options, 0, sizeof(*options));
    options->cycle_ns = DEFAULT_CYCLE_NS;
    options->state_timeout_ms = 10000;
    options->cpu = -1;

    while ((option = getopt_long(argc, argv, "i:c:t:s:vlh", long_options, NULL)) != -1)
    {
        uint32_t value;

        switch (option)
        {
        case 'i':
            options->ifname = optarg;
            break;
        case 'c':
            if (!parse_u32(optarg, &value) || (value == 0) ||
                ((uint64_t)value * 1000ULL > MAX_CYCLE_NS))
            {
                fprintf(stderr, "周期必须是 1..%u 微秒。\n", MAX_CYCLE_NS / 1000U);
                return false;
            }
            options->cycle_ns = value * 1000U;
            break;
        case OPT_CYCLE_NS:
            if (!parse_u32(optarg, &value) || (value < 1000U) ||
                (value > MAX_CYCLE_NS))
            {
                fprintf(stderr, "纳秒周期必须是 1000..%u。\n", MAX_CYCLE_NS);
                return false;
            }
            options->cycle_ns = value;
            break;
        case 't':
            if (!parse_u32(optarg, &options->duration_s))
            {
                fprintf(stderr, "运行时间参数无效。\n");
                return false;
            }
            break;
        case 's':
            if (!parse_u32(optarg, &value) || (value == 0) || (value > INT32_MAX))
            {
                fprintf(stderr, "状态超时参数无效。\n");
                return false;
            }
            options->state_timeout_ms = (int)value;
            break;
        case OPT_CPU:
            if (!parse_u32(optarg, &value) ||
                (value >= (uint32_t)sysconf(_SC_NPROCESSORS_ONLN)))
            {
                fprintf(stderr, "CPU 编号超出在线 CPU 范围。\n");
                return false;
            }
            options->cpu = (int)value;
            break;
        case OPT_RT_PRIORITY:
            if (!parse_u32(optarg, &value) || (value == 0) || (value > 99))
            {
                fprintf(stderr, "实时优先级必须是 1..99。\n");
                return false;
            }
            options->rt_priority = (int)value;
            break;
        case OPT_LOCK_MEMORY:
            options->lock_memory = true;
            break;
        case OPT_PROFILE:
            if (strcmp(optarg, "mc02") != 0)
            {
                fprintf(stderr, "未知 profile: %s（仅支持 mc02）。\n", optarg);
                return false;
            }
            options->profile_mc02 = true;
            break;
        case OPT_DC:
            options->enable_dc = true;
            break;
        case OPT_DC_LEAD_US:
            if (!parse_u32(optarg, &value) || (value == 0) ||
                (value > (uint32_t)(INT32_MAX / 1000)))
            {
                fprintf(stderr, "DC 提前量必须是正整数微秒。\n");
                return false;
            }
            options->dc_lead_ns = (int32_t)value * 1000;
            options->enable_dc = true;
            break;
        case OPT_PREOP_ONLY:
            options->preop_only = true;
            break;
        case 'v':
            options->verbose = true;
            break;
        case 'l':
            options->list_adapters = true;
            break;
        case 'h':
            print_usage(argv[0]);
            exit(EXIT_SUCCESS);
        default:
            print_usage(argv[0]);
            return false;
        }
    }

    if (options->list_adapters)
    {
        return true;
    }
    if (options->ifname == NULL)
    {
        fprintf(stderr, "缺少 --ifname。\n\n");
        print_usage(argv[0]);
        return false;
    }
    if (options->profile_mc02)
    {
        options->enable_dc = true;
    }
    if (options->dc_lead_ns >= (int32_t)options->cycle_ns)
    {
        fprintf(stderr, "DC 提前量必须小于发送周期。\n");
        return false;
    }
    return true;
}

static int16_t rd_i16(const uint8_t *data)
{
    return (int16_t)((uint16_t)data[0] | ((uint16_t)data[1] << 8));
}

static uint16_t rd_u16(const uint8_t *data)
{
    return (uint16_t)((uint16_t)data[0] | ((uint16_t)data[1] << 8));
}

static int32_t rd_i32(const uint8_t *data)
{
    return (int32_t)((uint32_t)data[0] |
                     ((uint32_t)data[1] << 8) |
                     ((uint32_t)data[2] << 16) |
                     ((uint32_t)data[3] << 24));
}

static uint32_t rd_u32(const uint8_t *data)
{
    return (uint32_t)data[0] |
           ((uint32_t)data[1] << 8) |
           ((uint32_t)data[2] << 16) |
           ((uint32_t)data[3] << 24);
}

static void wr_i16(uint8_t *data, int16_t value)
{
    data[0] = (uint8_t)((uint16_t)value & 0xFFU);
    data[1] = (uint8_t)((uint16_t)value >> 8);
}

static void wr_u16(uint8_t *data, uint16_t value)
{
    data[0] = (uint8_t)(value & 0xFFU);
    data[1] = (uint8_t)(value >> 8);
}

static void wr_u32(uint8_t *data, uint32_t value)
{
    data[0] = (uint8_t)(value & 0xFFU);
    data[1] = (uint8_t)((value >> 8) & 0xFFU);
    data[2] = (uint8_t)((value >> 16) & 0xFFU);
    data[3] = (uint8_t)((value >> 24) & 0xFFU);
}

static int16_t clamp_i16(double value)
{
    if (value > INT16_MAX)
    {
        return INT16_MAX;
    }
    if (value < INT16_MIN)
    {
        return INT16_MIN;
    }
    return (int16_t)value;
}

static uint16_t clamp_u16(double value)
{
    if (value > UINT16_MAX)
    {
        return UINT16_MAX;
    }
    if (value < 0.0)
    {
        return 0;
    }
    return (uint16_t)value;
}

static bool map_shared_memory(const char *name, size_t size,
                              void **mapping, size_t *mapping_size)
{
    int fd;
    void *address;

    fd = shm_open(name, O_CREAT | O_RDWR, 0600);
    if (fd < 0)
    {
        return false;
    }
    if (ftruncate(fd, (off_t)size) != 0)
    {
        close(fd);
        return false;
    }
    address = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (address == MAP_FAILED)
    {
        return false;
    }
    *mapping = address;
    *mapping_size = size;
    return true;
}

static void open_ui_shared_memory(Master *master)
{
    _Static_assert(sizeof(EcatUiState) == 444,
                   "EcatUiState layout does not match Python bridge");
    _Static_assert(sizeof(EcatUiCmd) == 360,
                   "EcatUiCmd layout does not match Python bridge");

    if (!map_shared_memory(STATE_SHM_NAME, sizeof(EcatUiState),
                           &master->state_mapping,
                           &master->state_mapping_size))
    {
        fprintf(stderr, "无法创建 UI 状态共享内存: %s\n", strerror(errno));
        return;
    }
    if (!map_shared_memory(CMD_SHM_NAME, sizeof(EcatUiCmd),
                           &master->cmd_mapping,
                           &master->cmd_mapping_size))
    {
        fprintf(stderr, "无法创建 UI 命令共享内存: %s\n", strerror(errno));
        munmap(master->state_mapping, master->state_mapping_size);
        master->state_mapping = NULL;
        master->state_mapping_size = 0;
        return;
    }

    master->ui_state = (EcatUiState *)master->state_mapping;
    master->ui_cmd = (EcatUiCmd *)master->cmd_mapping;
    memset(master->ui_state, 0, sizeof(*master->ui_state));
    master->ui_state->magic = ECAT_UI_STATE_MAGIC;
    master->ui_state->size = (uint32_t)sizeof(*master->ui_state);
    master->ui_cmd->stop = 0;
}

static void close_ui_shared_memory(Master *master)
{
    if (master->cmd_mapping != NULL)
    {
        munmap(master->cmd_mapping, master->cmd_mapping_size);
        master->cmd_mapping = NULL;
        master->ui_cmd = NULL;
    }
    if (master->state_mapping != NULL)
    {
        munmap(master->state_mapping, master->state_mapping_size);
        master->state_mapping = NULL;
        master->ui_state = NULL;
    }
}

static bool apply_ui_command(Master *master)
{
    ec_groupt *group = &master->ctx.grouplist[master->group];
    EcatUiCmd *cmd = master->ui_cmd;
    uint32_t seq;
    int axis;

    if ((cmd == NULL) || (group->outputs == NULL) || (group->Obytes < 196U))
    {
        return true;
    }

    seq = cmd->seq;
    if (seq & 1U)
    {
        return true;
    }
    if ((seq == master->last_cmd_seq) && (seq != 0U))
    {
        return !cmd->stop;
    }
    if ((cmd->magic != ECAT_UI_CMD_MAGIC) ||
        (cmd->size != (uint32_t)sizeof(*cmd)))
    {
        return true;
    }
    atomic_thread_fence(memory_order_acquire);
    if (cmd->seq != seq)
    {
        return true;
    }

    master->last_cmd_seq = seq;
    group->outputs[OUT_CTRL] = cmd->ctrl;
    group->outputs[OUT_LED_R] = cmd->led_r;
    group->outputs[OUT_LED_G] = cmd->led_g;
    group->outputs[OUT_LED_B] = cmd->led_b;
    group->outputs[OUT_LED_MODE] = cmd->led_mode ? 1U : 0U;

    for (axis = 0; axis < ECAT_UI_AXES; axis++)
    {
        const EcatAxisCmd *input = &cmd->axis[axis];
        uint8_t *output = group->outputs + OUT_AXIS((uint32_t)axis + 1U);
        double kd = input->kd;

        if (kd < 0.0)
        {
            kd = 0.0;
        }
        if (kd > 500.0)
        {
            kd = 500.0;
        }
        wr_i16(output + 0, clamp_i16((double)input->pos_deg * 100.0));
        wr_i16(output + 2, clamp_i16((double)input->vel_dps * 10.0));
        wr_i16(output + 4, clamp_i16((double)input->tor_a));
        wr_u16(output + 6, clamp_u16((double)input->kp));
        wr_u16(output + 8, clamp_u16(kd));
    }
    return !cmd->stop;
}

static void update_latency_stats(Master *master, uint64_t received_ns)
{
    const ec_groupt *group = &master->ctx.grouplist[master->group];
    uint32_t echo;
    uint16_t mcu;

    if (group->inputs == NULL)
    {
        return;
    }
    if (group->Ibytes >= IN_ECHO_OFF + 4U)
    {
        echo = rd_u32(group->inputs + IN_ECHO_OFF);
        if (echo != 0U)
        {
            uint32_t received_us = (uint32_t)(received_ns / 1000ULL);
            uint32_t rtt = received_us - echo;

            if (rtt < 100000U)
            {
                master->rtt_count++;
                master->rtt_sum_us += rtt;
                if ((master->rtt_min_us == 0U) || (rtt < master->rtt_min_us))
                {
                    master->rtt_min_us = rtt;
                }
                if (rtt > master->rtt_max_us)
                {
                    master->rtt_max_us = rtt;
                }
            }
        }
    }
    if (group->Ibytes >= IN_ISR_OFF + 2U)
    {
        mcu = rd_u16(group->inputs + IN_ISR_OFF);
        if (mcu != 0U)
        {
            master->mcu_count++;
            master->mcu_sum_us += mcu;
            if ((master->mcu_min_us == 0U) || (mcu < master->mcu_min_us))
            {
                master->mcu_min_us = mcu;
            }
            if (mcu > master->mcu_max_us)
            {
                master->mcu_max_us = mcu;
            }
        }
    }
    if (group->Ibytes >= IN_PHASE_OFF + 2U)
    {
        master->phase_us = rd_u16(group->inputs + IN_PHASE_OFF);
        if (master->phase_us > master->phase_max_us)
        {
            master->phase_max_us = master->phase_us;
        }
        if (master->phase_us != 0xFFFFU)
        {
            uint32_t bucket = master->phase_us <= 2000U
                                  ? master->phase_us
                                  : 2000U;

            master->phase_count++;
            master->phase_sum_us += master->phase_us;
            if ((master->phase_min_us == 0U) ||
                (master->phase_us < master->phase_min_us))
            {
                master->phase_min_us = master->phase_us;
            }
            if (master->phase_us > master->phase_run_max_us)
            {
                master->phase_run_max_us = master->phase_us;
            }
            if (master->phase_us > 2000U)
            {
                master->phase_overflow++;
            }
            master->phase_histogram[bucket]++;
        }
    }
}

static uint32_t phase_percentile(const Master *master, uint32_t percentile)
{
    uint64_t target;
    uint64_t cumulative = 0;
    uint32_t index;

    if (master->phase_count == 0U)
    {
        return 0U;
    }
    target = (master->phase_count * percentile + 99U) / 100U;
    for (index = 0; index < 2001U; index++)
    {
        cumulative += master->phase_histogram[index];
        if (cumulative >= target)
        {
            return index;
        }
    }
    return 2000U;
}

static void align_dc_send_phase(Master *master, const MasterOptions *options,
                                uint64_t *next_cycle, int wkc,
                                int expected_wkc)
{
    int64_t phase_ns;
    int64_t target_ns;
    int64_t error_ns;
    int64_t adjustment_ns;
    uint64_t now;

    if (!master->dc_active || (options->dc_lead_ns <= 0) ||
        (master->ctx.DCtime <= 0) || (wkc < expected_wkc))
    {
        return;
    }

    phase_ns = master->ctx.DCtime % (int64_t)master->cycle_ns;
    if (phase_ns < 0)
    {
        phase_ns += master->cycle_ns;
    }
    target_ns = (int64_t)master->cycle_ns - options->dc_lead_ns;
    error_ns = target_ns - phase_ns;
    if (error_ns > (int64_t)master->cycle_ns / 2)
    {
        error_ns -= master->cycle_ns;
    }
    else if (error_ns < -(int64_t)master->cycle_ns / 2)
    {
        error_ns += master->cycle_ns;
    }

    /* Slow phase-only trim; keep the local monotonic interval close to cycle. */
    adjustment_ns = error_ns / 4;
    if (adjustment_ns > 25000)
    {
        adjustment_ns = 25000;
    }
    else if (adjustment_ns < -25000)
    {
        adjustment_ns = -25000;
    }
    now = now_ns();
    if ((int64_t)(*next_cycle + adjustment_ns) < (int64_t)now + 10000)
    {
        *next_cycle = now + 10000U;
    }
    else
    {
        *next_cycle = (uint64_t)((int64_t)*next_cycle + adjustment_ns);
    }

    master->dc_phase_count++;
    master->dc_phase_sum_ns += (uint64_t)phase_ns;
    if ((master->dc_phase_min_ns == 0U) ||
        ((uint32_t)phase_ns < master->dc_phase_min_ns))
    {
        master->dc_phase_min_ns = (uint32_t)phase_ns;
    }
    if ((uint32_t)phase_ns > master->dc_phase_max_ns)
    {
        master->dc_phase_max_ns = (uint32_t)phase_ns;
    }
}

static void print_run_summary(const Master *master, uint64_t cycle_count,
                              uint64_t bad_wkc_count)
{
    const uint32_t p50 = phase_percentile(master, 50U);
    const uint32_t p99 = phase_percentile(master, 99U);
    const double phase_avg = master->phase_count > 0U
                                 ? (double)master->phase_sum_us /
                                       (double)master->phase_count
                                 : 0.0;

    printf("运行统计：周期=%" PRIu64 " 失败帧=%" PRIu64
           " 最大间隔=%.3fms\n",
           cycle_count, bad_wkc_count, (double)master->max_gap_ms);
    printf("PDI 相位：样本=%" PRIu64 " 最小=%uus 平均=%.2fus "
           "P50=%uus P99=%uus 最大=%uus 超过2000us=%" PRIu64 "\n",
           master->phase_count, master->phase_min_us, phase_avg,
           p50, p99, master->phase_run_max_us, master->phase_overflow);
    if (master->dc_phase_count > 0U)
    {
        const double dc_avg_ns =
            (double)master->dc_phase_sum_ns / (double)master->dc_phase_count;

        printf("DC 发送相位：样本=%" PRIu64 " 最小=%.2fus 平均=%.2fus "
               "最大=%.2fus\n",
               master->dc_phase_count, master->dc_phase_min_ns / 1000.0,
               dc_avg_ns / 1000.0, master->dc_phase_max_ns / 1000.0);
    }
}

static void publish_ui_state(Master *master, uint64_t now, int wkc,
                             uint16_t al_state, uint16_t al_code)
{
    const ec_groupt *group = &master->ctx.grouplist[master->group];
    EcatUiState *state = master->ui_state;
    int axis;

    if ((state == NULL) || (group->inputs == NULL))
    {
        return;
    }

    state->seq++;
    atomic_thread_fence(memory_order_release);
    state->magic = ECAT_UI_STATE_MAGIC;
    state->size = (uint32_t)sizeof(*state);
    state->frame_cnt = ++master->frame_count;
    state->t_us = now / 1000ULL;
    state->fps = master->fps;
    state->gap_max_ms = master->max_gap_ms;
    state->wkc = (uint16_t)wkc;
    state->alstat = al_state;
    state->alcode = al_code;
    state->temp = master->phase_us;
    state->ax_count = ECAT_UI_AXES;
    state->pad0 = master->phase_max_us;
    master->phase_max_us = 0;

    if (group->Ibytes >= 12U)
    {
        for (axis = 0; axis < 3; axis++)
        {
            state->raw_acc[axis] = rd_i16(group->inputs + IN_IMU + 2U * axis);
            state->raw_gyro[axis] =
                rd_i16(group->inputs + IN_IMU + 6U + 2U * axis);
            state->acc[axis] = (float)state->raw_acc[axis] * ACC_LSB_MPS2;
            state->gyro[axis] = (float)state->raw_gyro[axis] * GYRO_LSB_RAD;
        }
    }

    for (axis = 0; axis < ECAT_UI_AXES; axis++)
    {
        uint32_t offset = IN_AXIS((uint32_t)axis + 1U);
        EcatAxisState *output = &state->axis[axis];

        if (group->Ibytes < offset + 10U)
        {
            continue;
        }
        output->id = rd_u16(group->inputs + offset);
        output->pos_raw = rd_i32(group->inputs + offset + 2U);
        output->vel_raw = rd_i16(group->inputs + offset + 6U);
        output->status = rd_u16(group->inputs + offset + 8U);
        output->pos_deg = (float)output->pos_raw * 0.01f;
        output->vel_dps = (float)output->vel_raw * 0.1f;
    }

    if (master->rtt_count > 0U)
    {
        state->rtt_avg_us = (float)master->rtt_sum_us / master->rtt_count;
        state->rtt_min_us = (float)master->rtt_min_us;
        state->rtt_max_us = (float)master->rtt_max_us;
        master->rtt_count = 0;
        master->rtt_sum_us = 0;
        master->rtt_min_us = 0;
        master->rtt_max_us = 0;
    }
    if (master->mcu_count > 0U)
    {
        state->mcu_avg_us = (float)master->mcu_sum_us / master->mcu_count;
        state->mcu_min_us = (float)master->mcu_min_us;
        state->mcu_max_us = (float)master->mcu_max_us;
        master->mcu_count = 0;
        master->mcu_sum_us = 0;
        master->mcu_min_us = 0;
        master->mcu_max_us = 0;
    }

    atomic_thread_fence(memory_order_release);
    state->seq++;
}

static int sdo_write_u16(ecx_contextt *ctx, uint16_t slave, uint16_t index,
                         uint8_t subindex, uint16_t value)
{
    uint16_t wire_value = htoes(value);

    return ecx_SDOwrite(ctx, slave, index, subindex, FALSE, sizeof(wire_value),
                        &wire_value, EC_TIMEOUTRXM);
}

static int sdo_write_u32(ecx_contextt *ctx, uint16_t slave, uint16_t index,
                         uint8_t subindex, uint32_t value)
{
    uint32_t wire_value = htoel(value);

    return ecx_SDOwrite(ctx, slave, index, subindex, FALSE, sizeof(wire_value),
                        &wire_value, EC_TIMEOUTRXM);
}

static bool is_mc02(const ec_slavet *slave)
{
    return (slave->eep_man == MC02_VENDOR_ID) &&
           (slave->eep_id == MC02_PRODUCT_CODE);
}

static int mc02_po2so(ecx_contextt *ctx, uint16_t slave_index)
{
    Master *master = (Master *)ctx->userdata;
    ec_slavet *slave = &ctx->slavelist[slave_index];
    uint16_t watchdog = htoes(1000);
    int rc;
    bool ok = true;

    if (!is_mc02(slave))
    {
        return 0;
    }

    /* 与固件现有 Windows 主站使用相同的同步模式、周期和 SM 看门狗。 */
    rc = sdo_write_u32(ctx, slave_index, 0x1C32, 10, master->cycle_ns);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: SDO 0x1C32:10 写入失败 (%d)\n",
                slave_index, rc);
        ok = false;
    }
    rc = sdo_write_u16(ctx, slave_index, 0x1C32, 1, 2);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: SDO 0x1C32:1 写入失败 (%d)\n",
                slave_index, rc);
        ok = false;
    }
    rc = sdo_write_u32(ctx, slave_index, 0x1C33, 10, master->cycle_ns);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: SDO 0x1C33:10 写入失败 (%d)\n",
                slave_index, rc);
        ok = false;
    }
    rc = sdo_write_u16(ctx, slave_index, 0x1C33, 1, 2);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: SDO 0x1C33:1 写入失败 (%d)\n",
                slave_index, rc);
        ok = false;
    }
    rc = sdo_write_u16(ctx, slave_index, 0x10F1, 2, 1000);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: 可选 SDO 0x10F1:2 写入失败 (%d)，继续启动。\n",
                slave_index, rc);
    }
    rc = ecx_FPWR(&ctx->port, slave->configadr, 0x0420, sizeof(watchdog),
                  &watchdog, EC_TIMEOUTRET);
    if (rc <= 0)
    {
        fprintf(stderr, "从站 %u: SM 看门狗寄存器写入失败 (%d)，继续启动。\n",
                slave_index, rc);
    }

    if (!ok)
    {
        fprintf(stderr,
                "从站 %u 的同步参数未全部写入；映射阶段会再次尝试，"
                "最终以 Safe-Op/Op 状态为准。\n",
                slave_index);
    }
    return ok;
}

static void print_slaves(Master *master)
{
    uint16_t slave_index;

    puts("检测到的 EtherCAT 从站：");
    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        const ec_slavet *slave = &master->ctx.slavelist[slave_index];

        printf("  #%u  %-24s  vendor=0x%08X  product=0x%08X  rev=0x%08X\n",
               slave_index,
               slave->name[0] != '\0' ? slave->name : "(未命名)",
               slave->eep_man,
               slave->eep_id,
               slave->eep_rev);
    }
}

static bool wait_state_pumped(Master *master, uint16_t state, int timeout_ms)
{
    uint64_t deadline = now_ns() + (uint64_t)timeout_ms * 1000000ULL;

    while (now_ns() < deadline)
    {
        uint16_t slave_index;
        bool all_reached = true;

        (void)ecx_send_processdata(&master->ctx);
        (void)ecx_receive_processdata(&master->ctx, EC_TIMEOUTRET);
        for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
        {
            const uint16_t config_address =
                master->ctx.slavelist[slave_index].configadr;
            uint16_t reached =
                etohs(ecx_FPRDw(&master->ctx.port, config_address, 0x0130,
                                EC_TIMEOUTRET));

            if ((reached & 0x0F) != (state & 0x0F))
            {
                all_reached = false;
                break;
            }
        }
        if (all_reached)
        {
            return true;
        }
        osal_usleep(1000);
    }
    return false;
}

static bool request_state_all(Master *master, uint16_t state, int timeout_ms)
{
    uint16_t slave_index;
    uint16_t writable_state = state;
    bool already_reached = true;

    (void)ecx_readstate(&master->ctx);
    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        uint16_t actual = master->ctx.slavelist[slave_index].state;

        if (((actual & 0x0F) != (state & 0x0F)) || ((actual & EC_STATE_ERROR) != 0U))
        {
            already_reached = false;
            break;
        }
    }
    if (already_reached)
    {
        return true;
    }

    /*
     * 广播 BWR 在部分 ESC/固件组合上可能在 PDI 尚未完成上一次切换时被丢弃。
     * 逐站写入并在每个从站上确认目标状态。
     */
    if (state == EC_STATE_INIT)
    {
        writable_state |= EC_STATE_ACK;
    }

    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        master->ctx.slavelist[slave_index].state = writable_state;
        if (ecx_writestate(&master->ctx, slave_index) <= 0)
        {
            return false;
        }
    }

    if (master->mapped &&
        ((state == EC_STATE_SAFE_OP) || (state == EC_STATE_OPERATIONAL)))
    {
        return wait_state_pumped(master, state, timeout_ms);
    }

    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        uint16_t reached = ecx_statecheck(&master->ctx, slave_index,
                                          state & 0x0F, timeout_ms * 1000);

        if ((reached & 0x0F) != (state & 0x0F))
        {
            return false;
        }
    }
    return true;
}

static void print_state_errors(Master *master)
{
    uint16_t slave_index;

    ecx_readstate(&master->ctx);
    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        const ec_slavet *slave = &master->ctx.slavelist[slave_index];

        if ((slave->state & 0x0F) != EC_STATE_OPERATIONAL)
        {
            fprintf(stderr,
                    "从站 %u 状态=0x%04X，AL 状态码=0x%04X (%s)\n",
                    slave_index, slave->state, slave->ALstatuscode,
                    ec_ALstatuscode2string(slave->ALstatuscode));
        }
    }
}

static bool configure_profile(Master *master)
{
    uint16_t slave_index;

    master->profile_slaves = 0;
    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        ec_slavet *slave = &master->ctx.slavelist[slave_index];

        slave->PO2SOconfig = mc02_po2so;
        if (is_mc02(slave))
        {
            (void)mc02_po2so(&master->ctx, slave_index);
            master->profile_slaves++;
        }
    }
    if (master->profile_slaves == 0)
    {
        fprintf(stderr, "未找到 MC02 从站（vendor=0x%08X product=0x%08X）。\n",
                MC02_VENDOR_ID, MC02_PRODUCT_CODE);
        return false;
    }
    return true;
}

static bool configure_dc(Master *master)
{
    uint16_t slave_index;
    int dc_slaves = 0;

    if (!ecx_configdc(&master->ctx))
    {
        fprintf(stderr, "没有从站支持分布式时钟。\n");
        return false;
    }

    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        if (master->ctx.slavelist[slave_index].hasdc)
        {
            ecx_dcsync0(&master->ctx, slave_index, TRUE,
                        master->cycle_ns, 0);
            dc_slaves++;
        }
    }
    if (dc_slaves == 0)
    {
        fprintf(stderr, "分布式时钟配置完成，但没有可用的 DC 从站。\n");
        return false;
    }
    master->dc_active = true;
    return true;
}

static bool prepare_master(Master *master, const MasterOptions *options)
{
    uint16_t slave_index;

    printf("打开网卡 %s ...\n", options->ifname);
    if (!ecx_init(&master->ctx, options->ifname))
    {
        fprintf(stderr, "网卡打开失败。请确认网卡名和 CAP_NET_RAW 权限。\n");
        return false;
    }
    master->socket_open = true;

    if (ecx_config_init(&master->ctx) <= 0)
    {
        fprintf(stderr, "未扫描到 EtherCAT 从站。\n");
        return false;
    }
    print_slaves(master);

    if (options->profile_mc02)
    {
        for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
        {
            master->ctx.slavelist[slave_index].PO2SOconfig = mc02_po2so;
        }
    }

    printf("切换到 INIT ...\n");
    if (!request_state_all(master, EC_STATE_INIT, options->state_timeout_ms))
    {
        print_state_errors(master);
        return false;
    }

    /* 等待 LAN9252/PDI 完成 INIT 后的内部复位，再请求 Pre-Op。 */
    osal_usleep(20000);

    printf("切换到 Pre-Op ...\n");
    if (!request_state_all(master, EC_STATE_PRE_OP, options->state_timeout_ms))
    {
        print_state_errors(master);
        return false;
    }

    if (options->profile_mc02 && !configure_profile(master))
    {
        return false;
    }

    if (options->preop_only)
    {
        return true;
    }

    if (options->enable_dc)
    {
        printf("配置分布式时钟 ...\n");
        if (!configure_dc(master))
        {
            return false;
        }
        osal_usleep(10000);
    }

    printf("映射过程数据 ...\n");
    if (ecx_config_map_group(&master->ctx, master->iomap, master->group) <= 0)
    {
        fprintf(stderr, "过程数据映射失败。\n");
        return false;
    }
    master->mapped = true;
    osal_usleep(10000);
    {
        ec_groupt *group = &master->ctx.grouplist[master->group];

        printf("映射结果：输出 %u 字节，输入 %u 字节，段数 %u。\n",
               (unsigned)group->Obytes, (unsigned)group->Ibytes,
               (unsigned)group->nsegments);
        if ((group->outputs == NULL) || (group->inputs == NULL))
        {
            fprintf(stderr, "SOEM 返回了无效的 PDO 指针。\n");
            return false;
        }
        memset(group->outputs, 0, group->Obytes);
    }

    printf("切换到 Safe-Op ...\n");
    if (!request_state_all(master, EC_STATE_SAFE_OP, options->state_timeout_ms))
    {
        print_state_errors(master);
        return false;
    }

    /* SAFE_OP 下先发一帧，确保输出段已经建立。 */
    (void)ecx_send_processdata(&master->ctx);
    (void)ecx_receive_processdata(&master->ctx, EC_TIMEOUTRET);

    printf("切换到 Op ...\n");
    if (!request_state_all(master, EC_STATE_OPERATIONAL, options->state_timeout_ms))
    {
        print_state_errors(master);
        return false;
    }
    return true;
}

static int expected_wkc(Master *master)
{
    const ec_groupt *group = &master->ctx.grouplist[master->group];

    return (int)(group->outputsWKC * 2U + group->inputsWKC);
}

static void print_pdo_prefix(const char *label, const uint8_t *data, uint32_t size)
{
    uint32_t count = size < 32U ? size : 32U;
    uint32_t index;

    printf("  %s %3u:", label, (unsigned)size);
    for (index = 0; index < count; index++)
    {
        printf(" %02X", data[index]);
    }
    if (size > count)
    {
        printf(" ...");
    }
    putchar('\n');
}

static void service_slave_states(Master *master, int timeout_ms)
{
    uint16_t slave_index;

    (void)timeout_ms;
    master->ctx.grouplist[master->group].docheckstate = FALSE;
    ecx_readstate(&master->ctx);

    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        ec_slavet *slave = &master->ctx.slavelist[slave_index];

        if (slave->group != master->group)
        {
            continue;
        }
        if ((slave->state & 0x0F) == EC_STATE_OPERATIONAL)
        {
            slave->islost = FALSE;
            continue;
        }

        master->ctx.grouplist[master->group].docheckstate = TRUE;
        fprintf(stderr, "从站 %u 离开 OP，状态=0x%04X，AL=0x%04X (%s)。\n",
                slave_index, slave->state, slave->ALstatuscode,
                ec_ALstatuscode2string(slave->ALstatuscode));

        if (slave->state == (EC_STATE_SAFE_OP + EC_STATE_ERROR))
        {
            slave->state = EC_STATE_SAFE_OP + EC_STATE_ACK;
            (void)ecx_writestate(&master->ctx, slave_index);
        }
        else if ((slave->state & 0x0F) == EC_STATE_SAFE_OP)
        {
            slave->state = EC_STATE_OPERATIONAL;
            (void)ecx_writestate(&master->ctx, slave_index);
        }
        else if (!slave->islost)
        {
            if ((slave->state & 0x0F) == EC_STATE_NONE)
            {
                slave->islost = TRUE;
            }
        }
    }
}

static int run_cycle_loop(Master *master, const MasterOptions *options)
{
    ec_groupt *group = &master->ctx.grouplist[master->group];
    uint64_t next_cycle = now_ns();
    uint64_t start_time = next_cycle;
    uint64_t previous_cycle = start_time;
    uint64_t next_al_poll = start_time;
    uint64_t next_fps_update = start_time + 250000000ULL;
    uint64_t next_report = start_time + 1000000000ULL;
    uint64_t cycle_count = 0;
    uint64_t bad_wkc_count = 0;
    int wkc = 0;
    const int wkc_expected = expected_wkc(master);

    master->start_ns = start_time;
    master->previous_cycle_ns = previous_cycle;
    master->fps_start_ns = start_time;
    master->fps_frames = 0;
    master->next_ui_publish_ns = start_time;

    printf("主站进入 OP：周期 %.3f ms，循环次数/秒约 %.1f，期望 WKC=%d。\n",
           (double)options->cycle_ns / 1000000.0,
           1000000000.0 / (double)options->cycle_ns,
           wkc_expected);
    puts("按 Ctrl+C 安全停止。");

    while (g_running)
    {
        uint64_t current = now_ns();
        uint64_t gap_ns = current - previous_cycle;

        if ((options->duration_s > 0) &&
            ((current - start_time) >= (uint64_t)options->duration_s * 1000000000ULL))
        {
            break;
        }

        previous_cycle = current;
        master->previous_cycle_ns = current;
        if ((double)gap_ns / 1000000.0 > (double)master->max_gap_ms)
        {
            master->max_gap_ms = (float)((double)gap_ns / 1000000.0);
        }

        if (!apply_ui_command(master))
        {
            puts("收到 Web UI 停止命令。");
            break;
        }
        if (group->Obytes >= OUT_STAMP_OFF + 4U)
        {
            wr_u32(group->outputs + OUT_STAMP_OFF,
                   (uint32_t)(current / 1000ULL));
        }

        (void)ecx_send_processdata(&master->ctx);
        wkc = ecx_receive_processdata(&master->ctx, EC_TIMEOUTRET);
        {
            uint64_t received = now_ns();

            update_latency_stats(master, received);
        }
        cycle_count++;

        if (wkc < wkc_expected)
        {
            bad_wkc_count++;
            if ((cycle_count % 100U) == 0U)
            {
                fprintf(stderr, "WKC=%d，期望 %d；检查从站状态与网线。\n",
                        wkc, wkc_expected);
            }
            if ((cycle_count % 100U) == 0U)
            {
                service_slave_states(master, options->state_timeout_ms);
            }
        }

        if (current >= next_fps_update)
        {
            double seconds = (double)(current - master->fps_start_ns) / 1000000000.0;

            if (seconds > 0.0)
            {
                float current_fps = (float)((double)master->fps_frames / seconds);

                master->fps = (master->fps > 0.0f)
                                  ? (0.7f * master->fps + 0.3f * current_fps)
                                  : current_fps;
            }
            master->fps_frames = 0;
            master->fps_start_ns = current;
            next_fps_update = current + 250000000ULL;
        }
        master->fps_frames++;

        if (current >= next_al_poll)
        {
            const uint16_t config_address = master->ctx.slavelist[1].configadr;
            uint16_t state = ecx_FPRDw(&master->ctx.port, config_address,
                                       0x0130, EC_TIMEOUTRET);
            uint16_t code = ecx_FPRDw(&master->ctx.port, config_address,
                                      0x0134, EC_TIMEOUTRET);

            master->last_al_state = etohs(state);
            master->last_al_code = etohs(code);
            if ((master->last_al_state & 0x0F) != EC_STATE_OPERATIONAL)
            {
                service_slave_states(master, options->state_timeout_ms);
            }
            next_al_poll = current + 200000000ULL;
        }

        if (current >= master->next_ui_publish_ns)
        {
            publish_ui_state(master, current, wkc, master->last_al_state,
                             master->last_al_code);
            master->next_ui_publish_ns = current + 50000000ULL;
        }

        if (current >= next_report)
        {
            printf("[%6.1f s] WKC=%d/%d  输出=%uB 输入=%uB  失败帧=%" PRIu64 "\n",
                   (double)(current - start_time) / 1000000000.0,
                   wkc, wkc_expected, (unsigned)group->Obytes,
                   (unsigned)group->Ibytes, bad_wkc_count);
            if (options->verbose)
            {
                print_pdo_prefix("OUT", group->outputs, group->Obytes);
                print_pdo_prefix("IN ", group->inputs, group->Ibytes);
            }
            next_report = current + 1000000000ULL;
        }

        next_cycle += options->cycle_ns;
        if (next_cycle < now_ns())
        {
            next_cycle = now_ns();
        }
        align_dc_send_phase(master, options, &next_cycle, wkc, wkc_expected);
        sleep_until_ns(next_cycle);
    }

    print_run_summary(master, cycle_count, bad_wkc_count);
    return 0;
}

static void deactivate_dc(Master *master)
{
    uint16_t slave_index;

    if (!master->dc_active)
    {
        return;
    }
    for (slave_index = 1; slave_index <= master->ctx.slavecount; slave_index++)
    {
        if (master->ctx.slavelist[slave_index].hasdc)
        {
            ecx_dcsync0(&master->ctx, slave_index, FALSE,
                        master->cycle_ns, 0);
        }
    }
    master->dc_active = false;
}

static void close_master(Master *master)
{
    if (!master->socket_open)
    {
        return;
    }

    puts("安全停止：关闭 SYNC0，并请求所有从站回到 INIT。");
    deactivate_dc(master);
    osal_usleep(10000);
    (void)request_state_all(master, EC_STATE_INIT, 1000);
    osal_usleep(50000);
    ecx_close(&master->ctx);
    master->socket_open = false;
}

int main(int argc, char **argv)
{
    static Master master;
    MasterOptions options;
    int result = EXIT_FAILURE;

    if (!parse_options(argc, argv, &options))
    {
        return EXIT_FAILURE;
    }
    if (options.list_adapters)
    {
        return print_adapters() ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    install_signal_handlers();
    memset(&master, 0, sizeof(master));
    master.group = 0;
    master.cycle_ns = options.cycle_ns;
    master.ctx.userdata = &master;
    configure_cpu_and_memory(&options);
    open_ui_shared_memory(&master);

    if (!prepare_master(&master, &options))
    {
        goto cleanup;
    }

    if (options.preop_only)
    {
        puts("已到达 Pre-Op，保持运行。按 Ctrl+C 返回 INIT。");
        while (g_running)
        {
            osal_usleep(100000);
        }
        result = EXIT_SUCCESS;
        goto cleanup;
    }

    enable_realtime_scheduler(options.rt_priority);
    result = run_cycle_loop(&master, &options);

cleanup:
    close_master(&master);
    close_ui_shared_memory(&master);
    return result;
}
