@echo off
rem 17-axis live monitor. usage: run_live.cmd [cycle_ns], default 2000000 (2 ms)
setlocal
cd /d "%~dp0"
set CYCLE=%~1
if "%CYCLE%"=="" set CYCLE=2000000
mode con: cols=120 lines=40
ecat_live.exe "\Device\NPF_{9269FBF0-8A17-4A3B-A238-90DF8FACBB09}" %CYCLE%
