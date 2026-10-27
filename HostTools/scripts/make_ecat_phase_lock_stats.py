#!/usr/bin/env python3
"""Summarize how DC phase locking changed PDI timing and WKC reliability."""

from pathlib import Path

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from matplotlib import font_manager


ROOT = Path(__file__).resolve().parents[2]
DATA = ROOT / "build" / "soem_master"
INPUT = ROOT / "HostTools" / "docs" / "ethercat_phase_lock_validation.csv"
OUTPUT = DATA / "ethercat_phase_lock_statistics.png"

FONT_PATH = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"
font_manager.fontManager.addfont(FONT_PATH)
plt.rcParams.update(
    {
        "font.family": font_manager.FontProperties(fname=FONT_PATH).get_name(),
        "axes.unicode_minus": False,
        "figure.facecolor": "white",
        "axes.facecolor": "white",
        "axes.edgecolor": "#8797a3",
        "grid.color": "#dde5ea",
        "grid.alpha": 0.7,
        "text.color": "#152735",
        "axes.labelcolor": "#263947",
        "xtick.color": "#334552",
        "ytick.color": "#334552",
    }
)

BLUE = "#2474b5"
ORANGE = "#e67e22"
TEAL = "#00897b"
RED = "#c73b3b"
GRAY = "#748692"


def main():
    frame = pd.read_csv(INPUT)
    free = frame[frame["phase_lock"] == "no"]
    locked = frame[frame["phase_lock"] == "yes"]

    fig, axes = plt.subplots(
        1,
        3,
        figsize=(16, 6.2),
        constrained_layout=True,
        gridspec_kw={"width_ratios": [1.05, 1.35, 0.9]},
    )

    # P50 demonstrates the free-running phase ambiguity.
    axis = axes[0]
    groups = [
        free[free["duration_s"] <= 10]["pdi_p50_us"].to_numpy(),
        locked["pdi_p50_us"].to_numpy(),
    ]
    for index, values in enumerate(groups):
        jitter = np.linspace(-0.08, 0.08, len(values))
        axis.scatter(
            np.full(len(values), index) + jitter,
            values,
            s=72,
            color=BLUE if index == 0 else TEAL,
            edgecolor="white",
            linewidth=1.0,
            zorder=3,
        )
        axis.plot(
            [index - 0.2, index + 0.2],
            [np.mean(values), np.mean(values)],
            color=BLUE if index == 0 else TEAL,
            linewidth=2,
        )
    axis.set_xticks([0, 1], ["自由发送相位", "DC 相位锁定"])
    axis.set_ylabel("PDI P50（µs）")
    axis.set_title("P50 跨启动稳定性", fontsize=15)
    axis.set_ylim(0, 220)
    axis.grid(axis="y")

    # Locked P99 and maximum, including stressed runs.
    axis = axes[1]
    labels = ["空闲", "CPU1–4\n满载", "CPU0–4\n满载", "绝对唤醒\n10 秒"]
    positions = np.arange(len(locked))
    width = 0.34
    bars_p99 = axis.bar(
        positions - width / 2,
        locked["pdi_p99_us"],
        width,
        color=BLUE,
        label="P99",
    )
    bars_max = axis.bar(
        positions + width / 2,
        locked["pdi_max_us"],
        width,
        color=ORANGE,
        label="最大值",
    )
    for bars in (bars_p99, bars_max):
        axis.bar_label(bars, fmt="%.0f", padding=3, fontsize=9)
    axis.axhline(500, color=RED, linewidth=1.0, linestyle="--")
    axis.text(3.42, 505, "500 µs 截止线", ha="right", color=RED, fontsize=9)
    axis.set_xticks(positions, labels, fontsize=9)
    axis.set_ylabel("PDI 相位（µs）")
    axis.set_ylim(0, 540)
    axis.set_title("锁定后 PDI 延迟", fontsize=15)
    axis.grid(axis="y")
    axis.legend(frameon=False, loc="upper left")

    # Most important reliability outcome: full-core stress before/after lock.
    axis = axes[2]
    values = [86, 0]
    bars = axis.bar(
        ["自由相位\nCPU0–4 满载", "DC 锁定\nCPU0–4 满载"],
        values,
        color=[RED, TEAL],
        width=0.58,
    )
    axis.bar_label(bars, fmt="%d 帧", padding=5, fontsize=11)
    axis.set_ylabel("60 秒内 WKC 失败帧")
    axis.set_ylim(0, 105)
    axis.set_title("Watchdog 可靠性", fontsize=15)
    axis.grid(axis="y")
    axis.text(
        1,
        8,
        "60 s · 120,004 周期\n0 次 SM watchdog",
        ha="center",
        va="bottom",
        fontsize=10,
        color=TEAL,
    )

    fig.suptitle(
        "Jetson Orin 2 kHz EtherCAT：主站–从站 DC 相位锁定效果",
        fontsize=20,
    )
    fig.savefig(OUTPUT, dpi=170)

    print(f"unlocked_p50_range={free[free['duration_s'] <= 10]['pdi_p50_us'].min()}"
          f"..{free[free['duration_s'] <= 10]['pdi_p50_us'].max()} us")
    print(f"locked_p50={sorted(set(locked['pdi_p50_us']))}")
    print(f"locked_p99={sorted(set(locked['pdi_p99_us']))}")
    print(f"full_stress_failures={values}")
    print(OUTPUT)


if __name__ == "__main__":
    main()
