@echo off
rem EtherCAT 17 轴界面。用法: run_ui.cmd
setlocal
cd /d "%~dp0"
"D:\clover\Environment\Python\python.exe" ecat_ui.py %*
