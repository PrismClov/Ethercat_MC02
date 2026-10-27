#!/usr/bin/env python3
"""Build one statistical summary chart and one DC waveform chart."""

from pathlib import Path

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from matplotlib import font_manager


ROOT = Path(__file__).resolve().parents[2]
DATA = ROOT / "build" / "soem_master"
STATS_OUTPUT = DATA / "ethercat_dc_statistics_cjk.png"
WAVE_OUTPUT = DATA / "ethercat_dc_waveforms_cjk.png"

FONT_PATH = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"
font_manager.fontManager.addfont(FONT_PATH)
FONT_NAME = font_manager.FontProperties(fname=FONT_PATH).get_name()

plt.rcParams.update(
    {
        "font.family": FONT_NAME,
        "axes.unicode_minus": False,
        "figure.facecolor": "white",
        "axes.facecolor": "white",
        "axes.edgecolor": "#8c9aa5",
        "axes.labelcolor": "#172735",
        "xtick.color": "#354654",
        "ytick.color": "#354654",
        "text.color": "#172735",
        "grid.color": "#dce4e9",
        "grid.alpha": 0.65,
    }
)

BLUE = "#2474b5"
ORANGE = "#e67e22"
TEAL = "#00897b"
GRAY = "#5f6f7c"
RED = "#c73b3b"


def load_historical(path, cycle_us, trim_s=1.0):
    frame = pd.read_csv(path)
    frame = frame[frame["ecat.reg.dc.systime"] != "0x0000000000000000"].copy()
    dc = frame["ecat.reg.dc.systime"].str[2:].apply(lambda value: int(value, 16))
    timestamp = frame["frame.time_epoch"].astype(float).to_numpy()
    dc = dc.to_numpy(dtype=np.uint64)

    elapsed = timestamp - timestamp[0]
    period_us = np.diff(timestamp) * 1_000_000.0
    error_us = np.diff(dc).astype(np.float64) / 1000.0 - cycle_us
    sample_time = elapsed[1:]
    valid = (
        (sample_time >= trim_s)
        & (sample_time <= elapsed[-1] - trim_s)
        & (period_us > cycle_us * 0.5)
        & (period_us < cycle_us * 1.8)
        & (np.abs(error_us) < 1000.0)
    )
    return sample_time[valid], error_us[valid]


def load_current(path):
    frame = pd.read_csv(path)
    return (
        frame["elapsed_s"].to_numpy(dtype=float),
        frame["dc_error_us"].to_numpy(dtype=float),
    )


def statistics_chart():
    labels = [
        "标准内核 · FIFO 80\n2 kHz · 30.15 s",
        "标准内核 · FIFO 99\n2 kHz · 60.39 s",
        "PREEMPT_RT · FIFO 99\n2 kHz · 56.56 s · 历史",
        "PREEMPT_RT + isolcpus=5\n2 kHz · 18.05 s",
        "PREEMPT_RT + isolcpus=5\n1 kHz · 20.21 s",
    ]
    p99 = np.array([28.640, 26.880, 31.600, 3.3616, 3.7600])
    maximum = np.array([269.920, 662.880, 361.920, 14.160, 14.400])
    stddev = np.array([8.398, 8.382, 9.760, 1.0760, 1.2701])

    positions = np.arange(len(labels))
    fig, axis = plt.subplots(figsize=(13.2, 7.6), constrained_layout=True)
    bar_height = 0.30
    bars_p99 = axis.barh(
        positions - bar_height / 2,
        p99,
        height=bar_height,
        color=BLUE,
        label="|P99| DC 增量误差",
    )
    bars_max = axis.barh(
        positions + bar_height / 2,
        maximum,
        height=bar_height,
        color=ORANGE,
        label="最大 |DC 增量误差|",
    )
    axis.scatter(
        stddev,
        positions,
        marker="D",
        s=64,
        color=TEAL,
        edgecolor="white",
        linewidth=1.2,
        zorder=5,
        label="标准差",
    )

    for bars, values in ((bars_p99, p99), (bars_max, maximum)):
        for bar, value in zip(bars, values):
            axis.annotate(
                f"{value:.2f} µs",
                (bar.get_width(), bar.get_y() + bar.get_height() / 2),
                xytext=(5, 0),
                textcoords="offset points",
                va="center",
                fontsize=10,
            )
    for y_pos, value in zip(positions, stddev):
        axis.annotate(
            f"σ {value:.2f}",
            (value, y_pos + 0.19),
            ha="center",
            va="bottom",
            fontsize=9,
            color=TEAL,
        )

    axis.axvline(100, color=RED, linestyle="--", linewidth=1.0, alpha=0.8)
    axis.text(104, -0.47, "100 µs", color=RED, fontsize=9, va="bottom")
    axis.set_xscale("symlog", linthresh=10)
    axis.set_xlim(0, 1100)
    axis.set_yticks(positions, labels)
    axis.invert_yaxis()
    axis.set_xlabel("DC 增量误差（µs，对数刻度）")
    axis.set_title("EtherCAT 2 kHz / 1 kHz DC 抖动统计对比", fontsize=18, pad=14)
    axis.grid(axis="x")
    axis.legend(loc="lower right", frameon=False)
    fig.savefig(STATS_OUTPUT, dpi=170)
    plt.close(fig)


def waveform_chart():
    historical = [
        (
            "标准内核 · FIFO 80",
            load_historical(DATA / "ethercat_dc_timestamps.csv", 500.0),
            "#76a9d3",
        ),
        (
            "标准内核 · FIFO 99",
            load_historical(DATA / "ethercat_dc_timestamps_fifo99.csv", 500.0),
            "#e6a15c",
        ),
        (
            "PREEMPT_RT · 历史",
            load_historical(DATA / "ethercat_dc_timestamps_rt.csv", 500.0, trim_s=2.0),
            "#16a39a",
        ),
    ]
    current_2k = load_current(DATA / "ethercat_2k_isolated_current.csv")
    current_1k = load_current(DATA / "ethercat_1k_isolated_current.csv")

    fig, axes = plt.subplots(
        2,
        1,
        figsize=(14, 9.6),
        constrained_layout=True,
        gridspec_kw={"height_ratios": [1.05, 1.0]},
    )
    top, bottom = axes
    for label, (time, error), color in historical:
        top.plot(time, error, linewidth=0.32, alpha=0.78, color=color, label=label)
    top.axhline(0, color="#536674", linewidth=0.8)
    for threshold in (-100, 100):
        top.axhline(threshold, color=RED, linewidth=0.8, linestyle="--", alpha=0.65)
    top.set_xlim(0, 60)
    top.set_ylim(-720, 720)
    top.set_ylabel("DC 增量误差（µs）")
    top.set_xlabel("测试时间（s）")
    top.set_title("历史 2 kHz 基线：标准内核与 PREEMPT_RT", fontsize=16)
    top.grid()
    top.legend(loc="upper right", ncol=3, frameon=False)

    for label, (time, error), color in (
        ("PREEMPT_RT + isolcpus=5 · 2 kHz", current_2k, BLUE),
        ("PREEMPT_RT + isolcpus=5 · 1 kHz", current_1k, ORANGE),
    ):
        bottom.plot(time, error, linewidth=0.45, color=color, label=label)
        peak_index = int(np.argmax(np.abs(error)))
        bottom.scatter(
            time[peak_index],
            error[peak_index],
            s=34,
            color=color,
            edgecolor="white",
            linewidth=0.8,
            zorder=4,
        )
        bottom.annotate(
            f"max {abs(error[peak_index]):.2f} µs",
            (time[peak_index], error[peak_index]),
            xytext=(8, 8),
            textcoords="offset points",
            fontsize=9,
            color=color,
        )
    for threshold in (-10, 10):
        bottom.axhline(threshold, color=RED, linewidth=0.8, linestyle="--", alpha=0.65)
    bottom.axhline(0, color="#536674", linewidth=0.8)
    bottom.set_xlim(0, 22)
    bottom.set_ylim(-18, 18)
    bottom.set_ylabel("DC 增量误差（µs）")
    bottom.set_xlabel("测试时间（s）")
    bottom.set_title("当前 CPU5 隔离结果：1 kHz / 2 kHz", fontsize=16, loc="left")
    bottom.grid()
    bottom.legend(
        loc="lower right",
        bbox_to_anchor=(1.0, 1.01),
        ncol=2,
        frameon=False,
    )

    fig.suptitle("EtherCAT DC 增量误差波形对比", fontsize=20)
    fig.text(
        0.01,
        0.005,
        "说明：历史与当前数据不是同一轮会话；当前数据在 MCU 手动复位后采集。",
        fontsize=9,
        color=GRAY,
    )
    fig.savefig(WAVE_OUTPUT, dpi=170)
    plt.close(fig)


if __name__ == "__main__":
    statistics_chart()
    waveform_chart()
    print(STATS_OUTPUT)
    print(WAVE_OUTPUT)
