@echo off
rem NOIR Web UI（零依赖版）—— 起桥 + 打开浏览器
setlocal
cd /d "%~dp0"
start "" http://127.0.0.1:8765/
"D:\clover\Environment\Python\python.exe" webui\serve.py --port 8765 --root webui
