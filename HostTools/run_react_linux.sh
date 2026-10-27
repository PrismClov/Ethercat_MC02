#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIST="$ROOT/HostTools/webui-react/dist"
PORT="${ECAT_UI_PORT:-8766}"
export ECAT_IFACE="${ECAT_IFACE:-enP8p1s0}"
export ECAT_DC_LEAD_US="${ECAT_DC_LEAD_US:-150}"

if [[ ! -f "$DIST/index.html" ]]; then
    echo "缺少 React 构建产物，请先运行 build_react_linux.sh" >&2
    exit 1
fi

cd "$ROOT"
if command -v xdg-open >/dev/null 2>&1; then
    xdg-open "http://127.0.0.1:${PORT}/" >/dev/null 2>&1 &
fi

exec python3 HostTools/webui/serve.py \
    --port "$PORT" \
    --root "$DIST"
