@echo off
REM 创建并切换到build目录
if not exist build mkdir build
cd build

REM 配置项目
cmake -G "MinGW Makefiles" -S .. -B .

REM 构建项目
cmake --build .

REM 运行编译后的程序，假设可执行文件名为 TeachingCPP.exe
TeachingCPP.exe

REM 返回到原始目录
cd ..
