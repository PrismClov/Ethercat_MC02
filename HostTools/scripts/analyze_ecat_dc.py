#!/usr/bin/env python3
"""Extract EtherCAT DC timestamps from a capture and summarize cycle jitter."""

import argparse
import csv
import io
import subprocess

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np


def extract_rows(pcap, source_mac):
    display_filter = f'eth.src == {source_mac} && ecat.reg.dc.systime'
    command = [
        "tshark",
        "-n",
        "-r",
        pcap,
        "-Y",
        display_filter,
        "-T",
        "fields",
        "-E",
        "separator=,",
        "-e",
        "frame.number",
        "-e",
        "frame.time_epoch",
        "-e",
        "ecat.reg.dc.systime",
    ]
    result = subprocess.run(command, check=True, capture_output=True, text=True)
    rows = []
    for row in csv.reader(io.StringIO(result.stdout)):
        if len(row) < 3 or not row[1] or not row[2]:
            continue
        dc_systime = int(row[2], 16)
        if dc_systime == 0:
            continue
        rows.append((int(row[0]), float(row[1]), dc_systime))
    return rows


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("pcap")
    parser.add_argument("--source-mac", default="01:01:01:01:01:01")
    parser.add_argument("--cycle-us", type=float, default=500.0)
    parser.add_argument("--trim-s", type=float, default=1.0)
    parser.add_argument("--output-prefix", required=True)
    args = parser.parse_args()

    rows = extract_rows(args.pcap, args.source_mac)
    if len(rows) < 3:
        raise SystemExit("没有提取到足够的 EtherCAT DC 时间戳")

    times = np.asarray([row[1] for row in rows], dtype=np.float64)
    dc = np.asarray([row[2] for row in rows], dtype=np.uint64)
    elapsed = times - times[0]
    dc_delta_us = np.diff(dc).astype(np.float64) / 1000.0
    frame_period_us = np.diff(times) * 1_000_000.0
    dc_error_us = dc_delta_us - args.cycle_us
    sample_time = elapsed[1:]

    mask = (sample_time >= args.trim_s) & (
        sample_time <= elapsed[-1] - args.trim_s
    )
    # Missing/reordered cycles are not scheduler samples. Keep ordinary cycles.
    mask &= (frame_period_us > args.cycle_us * 0.5) & (
        frame_period_us < args.cycle_us * 1.8
    )
    errors = dc_error_us[mask]
    periods = frame_period_us[mask]
    plot_time = sample_time[mask]
    if errors.size == 0:
        raise SystemExit("过滤后没有有效的 DC 周期样本")

    absolute = np.abs(errors)
    rate_khz = 1000.0 / args.cycle_us
    rate_label = f"{rate_khz:g} kHz"
    summary = {
        "frames": int(errors.size),
        "duration_s": float(plot_time[-1] - plot_time[0]),
        "mean_us": float(np.mean(errors)),
        "std_us": float(np.std(errors)),
        "p5_us": float(np.percentile(errors, 5)),
        "p50_us": float(np.percentile(errors, 50)),
        "p95_us": float(np.percentile(errors, 95)),
        "p95_abs_us": float(np.percentile(absolute, 95)),
        "p99_abs_us": float(np.percentile(absolute, 99)),
        "max_abs_us": float(np.max(absolute)),
        "period_p99_us": float(np.percentile(periods, 99)),
        "period_max_us": float(np.max(periods)),
        "over_100us_pct": float(np.mean(absolute > 100.0) * 100.0),
        "over_200us_pct": float(np.mean(absolute > 200.0) * 100.0),
    }

    csv_path = f"{args.output_prefix}.csv"
    with open(csv_path, "w", encoding="utf-8") as output:
        writer = csv.writer(output)
        writer.writerow(["elapsed_s", "dc_error_us", "frame_period_us"])
        writer.writerows(zip(plot_time, errors, periods))

    summary_path = f"{args.output_prefix}_summary.csv"
    with open(summary_path, "w", encoding="utf-8") as output:
        writer = csv.writer(output)
        writer.writerow(summary.keys())
        writer.writerow(summary.values())

    fig, axes = plt.subplots(2, 1, figsize=(14, 8), constrained_layout=True)
    axes[0].plot(plot_time, errors, linewidth=0.35, color="#00897b")
    axes[0].axhline(0, color="0.4", linewidth=0.7)
    axes[0].axhline(100, color="#d32f2f", linewidth=0.8, linestyle="--")
    axes[0].axhline(-100, color="#d32f2f", linewidth=0.8, linestyle="--")
    axes[0].set(
        title=f"EtherCAT {rate_label} isolated PREEMPT_RT DC jitter",
        xlabel="Test time (s)",
        ylabel="DC increment error (us)",
    )
    axes[0].grid(alpha=0.25)
    axes[1].hist(errors, bins=240, range=(-250, 250), color="#00897b")
    axes[1].set(
        title=(
            f"Distribution: p99(abs)={summary['p99_abs_us']:.1f} us, "
            f"max(abs)={summary['max_abs_us']:.1f} us"
        ),
        xlabel="DC increment error (us)",
        ylabel="Samples",
    )
    axes[1].grid(alpha=0.25)
    fig.suptitle(
        f"Jetson Orin {rate_label} EtherCAT - PREEMPT_RT with isolcpus=5"
    )
    png_path = f"{args.output_prefix}.png"
    fig.savefig(png_path, dpi=160)

    for key, value in summary.items():
        if isinstance(value, float):
            print(f"{key}={value:.3f}")
        else:
            print(f"{key}={value}")
    print(f"csv={csv_path}")
    print(f"summary_csv={summary_path}")
    print(f"png={png_path}")


if __name__ == "__main__":
    main()
