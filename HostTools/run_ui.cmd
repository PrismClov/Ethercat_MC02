@echo off
rem EtherCAT 17-axis UI. usage: run_ui.cmd
setlocal
cd /d "%~dp0"
if exist "bin\EcatUI\EcatUI.exe" (
  start "" "bin\EcatUI\EcatUI.exe"
) else (
  "D:\clover\Environment\Python\python.exe" ui\ecat_ui.py %*
)
