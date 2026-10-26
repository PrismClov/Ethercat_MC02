@echo off
rem 重新编译主站工具（需要 SOEM 2.0.0 + MinGW gcc）
setlocal
cd /d "%~dp0"

set SOEM=C:\Users\Administrator\Projects\soem-2.0.0\SOEM-v2.0.0
set INC=-I"%SOEM%\include" -I"%SOEM%\build\include" -I"%SOEM%\osal" -I"%SOEM%\osal\win32" -I"%SOEM%\oshw\win32" -I"%SOEM%\oshw\win32\wpcap\Include"
set LIB=-L"%SOEM%\build" -lsoem -L"%SOEM%\oshw\win32\wpcap\Lib\x64" -lwpcap -lPacket -lws2_32 -lwinmm

echo [1/3] ecat_live.exe
gcc -O2 -std=c11 -Wall -o ecat_live.exe ecat_live.c %INC% %LIB% || exit /b 1

echo [2/3] ecat_zero_probe.exe
gcc -O2 -std=c11 -Wall -o ecat_zero_probe.exe ecat_zero_probe.c %INC% %LIB% || exit /b 1

echo [3/3] ecat_dc_sync_1ms.exe
gcc -O2 -std=c11 -Wall -o ecat_dc_sync_1ms.exe ecat_dc_sync.c %INC% %LIB% || exit /b 1

echo build OK
