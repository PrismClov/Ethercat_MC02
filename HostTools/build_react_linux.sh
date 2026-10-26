#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT/HostTools/webui-react"

if ! command -v npm >/dev/null 2>&1; then
    echo "未找到 npm。请安装 Node.js 22+ 后重试。" >&2
    exit 1
fi

if [[ ! -d node_modules ]]; then
    npm install
fi
npm run build
echo "React UI: $ROOT/HostTools/webui-react/dist"
