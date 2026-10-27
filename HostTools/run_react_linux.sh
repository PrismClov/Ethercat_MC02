#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIST="$ROOT/HostTools/webui-react/dist"
export ECAT_IFACE="${ECAT_IFACE:-enP8p1s0}"
export ECAT_DC_LEAD_US="${ECAT_DC_LEAD_US:-150}"

if [[ ! -f "$DIST/index.html" ]]; then
    echo "缺少 React 构建产物，请先运行 build_react_linux.sh" >&2
    exit 1
fi

cd "$ROOT"
exec bash HostTools/run_client_linux.sh "$@"
