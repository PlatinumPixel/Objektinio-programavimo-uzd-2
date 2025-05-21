@echo off
REM Create and enter build directory
if not exist build mkdir build
cd build

REM Run CMake and build
cmake ..
cmake --build .

cd ..
cd build
cd Debug
unit_test.exe