@echo off
rem Build the React UI (first run installs deps, takes a few minutes).
setlocal
cd /d "%~dp0webui-react"
set PATH=D:\clover\Environment\node\node-v24.22.1-win-x64;%PATH%
if not exist node_modules (
  call npm install react react-dom github:HanRabbit/NOIR-UI || exit /b 1
  call npm install -D vite @vitejs/plugin-react || exit /b 1
)
call npm run build || exit /b 1
echo build OK -^> webui-react\dist
