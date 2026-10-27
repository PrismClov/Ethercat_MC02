#!/usr/bin/env python3
"""Compose the historical and current EtherCAT test charts into one poster."""

from pathlib import Path

from PIL import Image, ImageDraw, ImageFont, ImageOps


ROOT = Path(__file__).resolve().parents[2]
CHART_DIR = ROOT / "build" / "soem_master"
OUTPUT = CHART_DIR / "ethercat_test_summary.png"

CANVAS_WIDTH = 4096
MARGIN = 110
GUTTER = 56
BACKGROUND = "#f2f5f7"
PANEL = "#ffffff"
INK = "#102333"
MUTED = "#607282"
BORDER = "#dce4e9"
NAVY = "#102638"
TEAL = "#00897b"
ORANGE = "#ef8b21"
RED = "#c73b3b"

FONT_REGULAR = "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc"
FONT_BOLD = "/usr/share/fonts/opentype/noto/NotoSansCJK-Bold.ttc"


def font(path, size):
    return ImageFont.truetype(path, size=size)


TITLE = font(FONT_BOLD, 76)
SUBTITLE = font(FONT_REGULAR, 31)
SECTION = font(FONT_BOLD, 40)
CAPTION = font(FONT_BOLD, 31)
SUBCAPTION = font(FONT_REGULAR, 23)
CARD_LABEL = font(FONT_REGULAR, 24)
CARD_VALUE = font(FONT_BOLD, 57)
CARD_NOTE = font(FONT_REGULAR, 21)
FOOTER = font(FONT_REGULAR, 24)
FOOTER_BOLD = font(FONT_BOLD, 25)


def wrapped_lines(draw, text, face, max_width):
    lines = []
    current = ""
    for part in text.split():
        candidate = f"{current} {part}".strip()
        if draw.textbbox((0, 0), candidate, font=face)[2] <= max_width:
            current = candidate
        else:
            if current:
                lines.append(current)
            current = part
    if current:
        lines.append(current)
    return lines


def draw_panel(canvas, draw, x, y, width, title, subtitle, image_path, max_image_height):
    image = Image.open(image_path).convert("RGB")
    image = ImageOps.contain(image, (width - 48, max_image_height), Image.LANCZOS)
    panel_height = 112 + image.height + 34
    draw.rounded_rectangle(
        (x, y, x + width, y + panel_height),
        radius=24,
        fill=PANEL,
        outline=BORDER,
        width=2,
    )
    draw.text((x + 30, y + 24), title, font=CAPTION, fill=INK)
    draw.text((x + 30, y + 68), subtitle, font=SUBCAPTION, fill=MUTED)
    image_x = x + (width - image.width) // 2
    image_y = y + 112
    canvas.paste(image, (image_x, image_y))
    return panel_height


def draw_header(draw, y):
    width = CANVAS_WIDTH - 2 * MARGIN
    draw.rounded_rectangle(
        (MARGIN, y, MARGIN + width, y + 470),
        radius=30,
        fill=NAVY,
    )
    draw.text((MARGIN + 48, y + 40), "Jetson Orin EtherCAT 实时抖动测试汇总", font=TITLE, fill="#ffffff")
    draw.text(
        (MARGIN + 50, y + 137),
        "普通 PREEMPT_RT · CPU5 隔离 · 2 kHz / 1 kHz · 2026-10-27",
        font=SUBTITLE,
        fill="#b8cad5",
    )

    cards = [
        ("历史 PREEMPT_RT 最大值", "361.92 µs", "旧会话 · FIFO99"),
        ("2 kHz 隔离 P99", "3.36 µs", "最大值 14.16 µs"),
        ("2 kHz 最大周期", "509.26 µs", "名义 500 µs · WKC 3/3"),
        ("1 kHz 最大周期", "1003.98 µs", "名义 1000 µs · WKC 3/3"),
    ]
    card_y = y + 220
    card_gap = 22
    card_width = (width - 96 - 3 * card_gap) // 4
    for index, (label, value, note) in enumerate(cards):
        card_x = MARGIN + 48 + index * (card_width + card_gap)
        draw.rounded_rectangle(
            (card_x, card_y, card_x + card_width, card_y + 188),
            radius=18,
            fill="#18364a",
        )
        draw.text((card_x + 22, card_y + 20), label, font=CARD_LABEL, fill="#b8cad5")
        draw.text((card_x + 22, card_y + 67), value, font=CARD_VALUE, fill="#ffffff")
        draw.text((card_x + 22, card_y + 145), note, font=CARD_NOTE, fill="#8fb0c2")
    return 470


def main():
    images = {
        "history": CHART_DIR / "ethercat_dc_jitter_compare_rt.png",
        "isolation": CHART_DIR / "ethercat_2k_isolated_compare.png",
        "fifo80": CHART_DIR / "ethercat_dc_jitter.png",
        "fifo_compare": CHART_DIR / "ethercat_dc_jitter_fifo99.png",
        "two_k": CHART_DIR / "ethercat_2k_isolated_current.png",
        "one_k": CHART_DIR / "ethercat_1k_isolated_current.png",
    }
    for path in images.values():
        if not path.exists():
            raise SystemExit(f"缺少测试图: {path}")

    canvas = Image.new("RGB", (CANVAS_WIDTH, 5000), BACKGROUND)
    draw = ImageDraw.Draw(canvas)
    y = 80
    y += draw_header(draw, y) + 72

    left_width = (CANVAS_WIDTH - 2 * MARGIN - GUTTER) // 2
    right_x = MARGIN + left_width + GUTTER
    row_top = y
    left_height = draw_panel(
        canvas,
        draw,
        MARGIN,
        row_top,
        left_width,
        "历史对比：标准内核 vs PREEMPT_RT",
        "2 kHz · 四个诊断视图 · 用于保留旧基线",
        images["history"],
        1320,
    )
    right_height = draw_panel(
        canvas,
        draw,
        right_x,
        row_top,
        left_width,
        "当前改善：CPU5 隔离前后",
        "2 kHz · P99 绝对值与最大绝对值",
        images["isolation"],
        1320,
    )
    y = row_top + max(left_height, right_height) + 58

    row_top = y
    left_height = draw_panel(
        canvas,
        draw,
        MARGIN,
        row_top,
        left_width,
        "历史基线：标准内核 FIFO 80",
        "2 kHz · 30.15 秒抓包",
        images["fifo80"],
        790,
    )
    right_height = draw_panel(
        canvas,
        draw,
        right_x,
        row_top,
        left_width,
        "历史基线：标准内核 FIFO 80 / FIFO 99",
        "2 kHz · 60.39 秒对比",
        images["fifo_compare"],
        790,
    )
    y = row_top + max(left_height, right_height) + 58

    row_top = y
    left_height = draw_panel(
        canvas,
        draw,
        MARGIN,
        row_top,
        left_width,
        "当前结果：PREEMPT_RT + isolcpus=5",
        "2 kHz · 18.05 秒有效抓包 · 36,097 周期",
        images["two_k"],
        1160,
    )
    right_height = draw_panel(
        canvas,
        draw,
        right_x,
        row_top,
        left_width,
        "当前结果：PREEMPT_RT + isolcpus=5",
        "1 kHz · 20.21 秒有效抓包 · 20,215 周期",
        images["one_k"],
        1160,
    )
    y = row_top + max(left_height, right_height) + 70

    footer_height = 260
    draw.rounded_rectangle(
        (MARGIN, y, CANVAS_WIDTH - MARGIN, y + footer_height),
        radius=22,
        fill="#e8eef2",
    )
    draw.text(
        (MARGIN + 34, y + 28),
        "判读说明",
        font=FOOTER_BOLD,
        fill=INK,
    )
    notes = [
        "旧图与当前图不是同一次会话；当前数据在 MCU 手动复位后采集。",
        "DC 误差 = 相邻帧 DC SysTime 增量 − 名义周期；最大周期与 RTT 是不同指标。",
        "2 kHz 最终 60 秒运行无失败帧；1 kHz 一组 60 秒正常，另一组约第 53 秒出现一次 SM watchdog。",
    ]
    note_y = y + 76
    for note in notes:
        draw.ellipse((MARGIN + 37, note_y + 10, MARGIN + 47, note_y + 20), fill=TEAL)
        draw.text((MARGIN + 62, note_y), note, font=FOOTER, fill=INK)
        note_y += 54

    final_height = y + footer_height + 80
    canvas = canvas.crop((0, 0, CANVAS_WIDTH, final_height))
    canvas.save(OUTPUT, optimize=True)
    print(OUTPUT)
    print(f"size={canvas.size[0]}x{canvas.size[1]}")


if __name__ == "__main__":
    main()
