@echo off
rem NOIR React UI (react + noir-ui). Starts the bridge and opens the browser.
setlocal
cd /d "%~dp0"
if not exist "webui-react\dist\index.html" (
  echo No build found. Run build_react.cmd first.
  exit /b 1
)
start "" http://127.0.0.1:8766/
"D:\clover\Environment\Python\python.exe" webui\serve.py --port 8766 --root webui-react\dist
