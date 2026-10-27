#!/usr/bin/env python3
"""Sample the SOEM master shared-memory state and summarize RT excursions."""

import argparse
import mmap
import struct
import time


AXES = 17
STATE_SIZE = 444
STATE_FMT = "<IIIIQff3f3f3h3hHHHHHH" + "ffHHihH" * AXES + "ffffff"
LATENCY_OFFSET = 25 + AXES * 7


def parse_state(fd):
    state = mmap.mmap(fd, STATE_SIZE, access=mmap.ACCESS_READ)
    try:
        return struct.unpack(STATE_FMT, state[:STATE_SIZE])
    finally:
        state.close()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--seconds", type=float, default=30.0)
    parser.add_argument(
        "--state",
        default="/dev/shm/ecat_ui_state",
        help="SOEM master shared-memory state file",
    )
    args = parser.parse_args()

    deadline = time.monotonic() + args.seconds
    last_frame = None
    max_gap_ms = 0.0
    max_rtt_us = 0.0
    max_mcu_us = 0.0
    max_phase_us = 0
    samples = 0
    invalid_samples = 0
    min_wkc = None
    first_frame = None
    last_frame = None

    with open(args.state, "rb", buffering=0) as fd:
        try:
            last_frame = parse_state(fd.fileno())[3]
        except (OSError, ValueError, struct.error):
            pass

        while time.monotonic() < deadline:
            try:
                values = parse_state(fd.fileno())
            except (OSError, ValueError, struct.error):
                time.sleep(0.05)
                continue

            frame = values[3]
            if last_frame is None or frame == last_frame:
                last_frame = frame
                time.sleep(0.02)
                continue
            last_frame = frame
            if first_frame is None:
                first_frame = frame
            samples += 1

            max_gap_ms = max(max_gap_ms, float(values[6]))
            wkc = int(values[19])
            phase_max = int(values[24])
            min_wkc = wkc if min_wkc is None else min(min_wkc, wkc)

            # The firmware uses 0xffff as the phase sentinel while leaving OP.
            if wkc < 3 or phase_max == 0xFFFF:
                invalid_samples += 1
            else:
                max_phase_us = max(max_phase_us, phase_max)
                max_rtt_us = max(max_rtt_us, float(values[LATENCY_OFFSET + 2]))
                max_mcu_us = max(max_mcu_us, float(values[LATENCY_OFFSET + 5]))
            time.sleep(0.02)

    print(f"samples={samples}")
    print(f"invalid_samples={invalid_samples}")
    print(f"frames_observed={(last_frame - first_frame + 1) if first_frame is not None else 0}")
    print(f"min_wkc={min_wkc}")
    print(f"max_gap_ms={max_gap_ms:.3f}")
    print(f"max_rtt_us={max_rtt_us:.1f}")
    print(f"max_mcu_us={max_mcu_us:.1f}")
    print(f"max_phase_us={max_phase_us}")


if __name__ == "__main__":
    main()
