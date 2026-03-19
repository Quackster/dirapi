@echo off
REM ============================================================
REM  dirapi build script
REM  Configures and builds dirapi.dll using CMake + MSVC (x86)
REM ============================================================

setlocal enabledelayedexpansion

echo.
echo  dirapi.dll - Build Script
echo  ================================
echo.

REM ---- Check for CMake ----
where cmake >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo [ERROR] CMake not found. Install CMake 3.15+ and add it to PATH.
    echo         https://cmake.org/download/
    exit /b 1
)

REM ---- Check for Visual Studio / MSVC ----
where cl >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo [WARN]  cl.exe not found in PATH.
    echo         Run this script from a "Developer Command Prompt for VS 2022"
    echo         or "x86 Native Tools Command Prompt for VS 2022".
    echo.

    REM Try to find and invoke vcvarsall
    set "VCVARS="
    for %%P in (
        "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
        "%ProgramFiles%\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvarsall.bat"
        "%ProgramFiles%\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat"
        "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat"
        "%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat"
    ) do (
        if exist %%~P (
            set "VCVARS=%%~P"
            goto :found_vcvars
        )
    )

    echo [ERROR] Could not locate vcvarsall.bat. Install Visual Studio 2022 with C++ tools.
    exit /b 1

    :found_vcvars
    echo [INFO]  Found vcvarsall.bat, setting up x86 environment...
    call "!VCVARS!" x86
    if %ERRORLEVEL% neq 0 (
        echo [ERROR] vcvarsall.bat failed.
        exit /b 1
    )
    echo.
)

REM ---- Create build directory ----
if not exist build mkdir build

REM ---- Configure with CMake (Win32 = x86) ----
echo [1/2] Configuring with CMake (Win32 / x86)...
cmake -S . -B build -A Win32
if %ERRORLEVEL% neq 0 (
    echo [ERROR] CMake configuration failed.
    exit /b 1
)

echo.

REM ---- Build ----
echo [2/2] Building dirapi.dll (Release)...
cmake --build build --config Release
if %ERRORLEVEL% neq 0 (
    echo [ERROR] Build failed. Check output above for errors.
    exit /b 1
)

echo.
echo  Build complete!
echo  Output: build\Release\dirapi.dll
echo.

endlocal
