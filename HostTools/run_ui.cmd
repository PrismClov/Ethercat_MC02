@echo off
rem EtherCAT 17-axis UI. usage: run_ui.cmd
setlocal
cd /d "%~dp0"
"D:\clover\Environment\Python\python.exe" ecat_ui.py %*
