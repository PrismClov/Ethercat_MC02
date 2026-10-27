#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIST="$ROOT/HostTools/webui-react/dist"

if [[ ! -f "$DIST/index.html" ]]; then
    echo "缺少 React 构建产物，请先运行 HostTools/build_react_linux.sh" >&2
    exit 1
fi

cd "$ROOT"
exec python3 HostTools/ui/web_client.py "$@"
