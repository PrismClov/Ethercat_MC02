@echo off
rem NOIR React UI（真 NOIR-UI 组件库）—— 起桥 + 打开浏览器
setlocal
cd /d "%~dp0"
if not exist "webui-react\dist\index.html" (
  echo 还没有构建产物，先跑 build_react.cmd
  exit /b 1
)
start "" http://127.0.0.1:8766/
"D:\clover\Environment\Python\python.exe" webui\serve.py --port 8766 --root webui-react\dist
