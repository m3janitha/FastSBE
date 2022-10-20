@ECHO off
set count=0
:Loop
if %count%==5 goto end
perf_test.exe
set count=%count%+1
goto Loop
:end