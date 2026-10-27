#!/usr/bin/env python3
"""Plot PREEMPT_RT DC jitter before and after CPU isolation."""

import argparse
import csv

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np


def read_row(path, selector):
    with open(path, newline="", encoding="utf-8") as source:
        rows = list(csv.DictReader(source))
    for row in rows:
        if selector in row["dataset"]:
            return row
    raise SystemExit(f"{path} 中找不到 {selector}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("baseline_summary")
    parser.add_argument("isolated_summary")
    parser.add_argument("--output", required=True)
    args = parser.parse_args()

    baseline = read_row(args.baseline_summary, "PREEMPT_RT")
    with open(args.isolated_summary, newline="", encoding="utf-8") as source:
        isolated = next(csv.DictReader(source))

    metrics = ["P99 absolute", "Maximum absolute"]
    baseline_values = [
        float(baseline["abs_p99_us"]),
        float(baseline["max_abs_us"]),
    ]
    isolated_values = [
        float(isolated["p99_abs_us"]),
        float(isolated["max_abs_us"]),
    ]

    x = np.arange(len(metrics))
    width = 0.34
    fig, axis = plt.subplots(figsize=(10, 6), constrained_layout=True)
    first = axis.bar(x - width / 2, baseline_values, width, label="PREEMPT_RT")
    second = axis.bar(
        x + width / 2, isolated_values, width, label="PREEMPT_RT + isolcpus=5"
    )
    axis.bar_label(first, fmt="%.2f us", padding=4)
    axis.bar_label(second, fmt="%.2f us", padding=4)
    axis.set_xticks(x, metrics)
    axis.set_ylabel("DC increment error (us, lower is better)")
    axis.set_title("EtherCAT 2 kHz DC jitter: CPU isolation comparison")
    axis.grid(axis="y", alpha=0.25)
    axis.legend()
    fig.savefig(args.output, dpi=160)

    for label, value in zip(metrics, baseline_values):
        print(f"baseline_{label}={value:.3f}")
    for label, value in zip(metrics, isolated_values):
        print(f"isolated_{label}={value:.3f}")
    print(f"png={args.output}")


if __name__ == "__main__":
    main()
