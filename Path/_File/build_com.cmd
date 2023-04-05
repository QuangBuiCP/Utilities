@echo off

echo g++ com.cpp -o com.exe -O2
g++ com.cpp -o com.exe -O2

if errorlevel 1 (
	echo bucakcho
	exit /b
)

echo g++ com.cpp -o com.exe -O2
g++ com.cpp -o com32.exe -O2 -m32

if errorlevel 1 (
	echo bucakcho
	exit /b
)