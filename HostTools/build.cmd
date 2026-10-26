@echo off
rem Rebuild host tools (requires SOEM 2.0.0 + MinGW gcc)
setlocal
cd /d "%~dp0"
if not exist bin mkdir bin

set SOEM=C:\Users\Administrator\Projects\soem-2.0.0\SOEM-v2.0.0
set INC=-I"%SOEM%\include" -I"%SOEM%\build\include" -I"%SOEM%\osal" -I"%SOEM%\osal\win32" -I"%SOEM%\oshw\win32" -I"%SOEM%\oshw\win32\wpcap\Include"
set LIB=-L"%SOEM%\build" -lsoem -L"%SOEM%\oshw\win32\wpcap\Lib\x64" -lwpcap -lPacket -lws2_32 -lwinmm

echo [1/6] bin\ecat_live.exe
gcc -O2 -std=c11 -Wall -o bin\ecat_live.exe src\ecat_live.c %INC% %LIB% || exit /b 1

echo [2/6] bin\ecat_zero_probe.exe
gcc -O2 -std=c11 -Wall -o bin\ecat_zero_probe.exe src\ecat_zero_probe.c %INC% %LIB% || exit /b 1

echo [3/6] bin\ecat_dc_sync_1ms.exe
gcc -O2 -std=c11 -Wall -o bin\ecat_dc_sync_1ms.exe src\ecat_dc_sync.c %INC% %LIB% || exit /b 1

echo [4/6] EcatUI.exe
gcc -O2 -mwindows -o EcatUI.exe src\launcher.c || exit /b 1

echo [5/6] EcatWeb.exe
gcc -O2 -mwindows -o EcatWeb.exe src\launcher_web.c -lshell32 -lws2_32 || exit /b 1

echo [6/6] EcatClient.exe
gcc -O2 -mwindows -o EcatClient.exe src\launcher_client.c || exit /b 1

echo build OK
