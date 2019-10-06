@echo on

set PATH=%QTDIR%\bin;%PATH%
set CMAKE_PREFIX_PATH=%QTDIR%\lib\cmake

REM Note: Following removes sh.exe from PATH so that CMake can generate MinGW Makefile.
if DEFINED MINGW_PATH set PATH=%MINGW_PATH%\bin;%PATH:C:\Program Files\Git\usr\bin;=%

if DEFINED CMD_VCVARSALL call %CMD_VCVARSALL%
