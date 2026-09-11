@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul

cd /d "%~dp0"

REM ==== 超时时间（毫秒），固定 10 秒 ====
set "TIMEOUT_MS=10000"

where g++ >nul 2>nul
if errorlevel 1 (
    echo [错误] 未找到 g++，请确认已安装 MinGW / TDM-GCC 并加入 PATH
    exit /b 1
)

REM ==== 编译（-Wall） ====
echo.
echo [编译] g++ -std=c++17 -O2 -Wall -o test.exe test.cpp
set "CLOG=%TEMP%\compile_%RANDOM%_%RANDOM%.log"
g++ -std=c++17 -O2 -Wall -o test.exe test.cpp > "%CLOG%" 2>&1
set "CRC=%errorlevel%"

if not "%CRC%"=="0" goto :compile_error

set HASWARN=
for /f "delims=" %%a in ('findstr /i /c:"warning" "%CLOG%" 2^>nul') do set HASWARN=1

if defined HASWARN goto :compile_warn

del /f /q "%CLOG%" >nul 2>nul
echo [编译] 成功（无警告）

REM ==== 编译成功后再询问测试组数 ====
echo.
set NUM=
set /p NUM=请输入要比对的测试组数（如 2，表示只跑 1 和 2）: 
if "%NUM%"=="" (
    echo [错误] 未输入组数
    if exist "test.exe" del /f /q "test.exe" >nul 2>nul
    exit /b 1
)
echo.

set PASS=0
set FAIL=0
set TOTAL=0

for /l %%i in (1,1,%NUM%) do (
    if exist "%%i.in" (
        if exist "%%i.ans" (
            set /a TOTAL+=1
            call :run_test %%i
        ) else (
            echo [跳过] %%i.ans 不存在
        )
    ) else (
        echo [跳过] %%i.in 不存在
    )
)

echo.
echo ==============================
echo 总计 %TOTAL% 组   通过 %PASS%   失败 %FAIL%
echo ==============================
goto :finish

REM ============================================
REM 编译错误退出
REM ============================================
:compile_error
echo.
echo ============================================
echo [编译错误] 编译失败，终止后续执行
echo ============================================
type "%CLOG%"
del /f /q "%CLOG%" >nul 2>nul
if exist "test.exe" del /f /q "test.exe" >nul 2>nul
exit /b 1

REM ============================================
REM 编译警告退出
REM ============================================
:compile_warn
echo.
echo ============================================
echo [编译警告] 检测到 -Wall 警告，终止后续执行
echo ============================================
type "%CLOG%"
del /f /q "%CLOG%" >nul 2>nul
if exist "test.exe" del /f /q "test.exe" >nul 2>nul
exit /b 1

REM ============================================
REM 正常结束
REM ============================================
:finish
if exist "test.exe" del /f /q "test.exe" >nul 2>nul
exit /b 0

REM ============================================
REM 子过程：单组测试
REM ============================================
:run_test
echo ==============================
echo 测试点 %1
echo ==============================

REM ==== 清理上一轮可能残留的同名文件 ====
if exist "%1.out" del /f /q "%1.out" >nul 2>nul
if exist "%1.err" del /f /q "%1.err" >nul 2>nul

REM ==== 带超时运行程序 ====
REM 退出码：0=正常，1001=TLE，1003=RE
powershell -NoProfile -Command "$ErrorActionPreference='SilentlyContinue'; $p = Start-Process -FilePath '.\test.exe' -RedirectStandardInput '%1.in' -RedirectStandardOutput '%1.out' -RedirectStandardError '%1.err' -PassThru -NoNewWindow; $sw = [System.Diagnostics.Stopwatch]::StartNew(); $reason = 0; while (-not $p.HasExited) { if ($sw.ElapsedMilliseconds -gt %TIMEOUT_MS%) { $reason = 1; break }; Start-Sleep -Milliseconds 20 }; if ($reason -eq 1) { try { $p.Kill() } catch {}; try { $p.WaitForExit(2000) | Out-Null } catch {}; exit 1001 }; try { $p.WaitForExit() } catch {}; $ec = 0; try { $ec = [int]$p.ExitCode } catch { $ec = 0 }; if ($ec -ne 0) { exit 1003 }; exit 0"
set "RC=%errorlevel%"

if "%RC%"=="1001" (
    echo [结果] TLE  超时（超过 10 秒）
    if exist "%1.err" del /f /q "%1.err" >nul 2>nul
    set /a FAIL+=1
    echo.
    exit /b 0
)

if "%RC%"=="1003" (
    echo [结果] RE   运行时错误（异常退出）
    if exist "%1.err" (
        echo ---- 标准错误 ----
        type "%1.err"
        echo ------------------
        del /f /q "%1.err" >nul 2>nul
    )
    set /a FAIL+=1
    echo.
    exit /b 0
)

if not "%RC%"=="0" (
    echo [结果] RE   未知错误，退出码 = %RC%
    if exist "%1.err" (
        echo ---- 标准错误 ----
        type "%1.err"
        echo ------------------
        del /f /q "%1.err" >nul 2>nul
    )
    set /a FAIL+=1
    echo.
    exit /b 0
)

if not exist "%1.out" (
    echo [结果] RE   未产生输出文件（可能崩溃）
    if exist "%1.err" (
        echo ---- 标准错误 ----
        type "%1.err"
        echo ------------------
        del /f /q "%1.err" >nul 2>nul
    )
    set /a FAIL+=1
    echo.
    exit /b 0
)

REM ==== 比对：忽略行末空格 + 忽略末尾换行（保留行首缩进，区分大小写） ====
powershell -NoProfile -Command "$o = [IO.File]::ReadAllText('%1.out'); $a = [IO.File]::ReadAllText('%1.ans'); $o = (($o -split '\r?\n') | ForEach-Object { $_.TrimEnd() }) -join [char]10; $a = (($a -split '\r?\n') | ForEach-Object { $_.TrimEnd() }) -join [char]10; $o = $o.TrimEnd([char]10); $a = $a.TrimEnd([char]10); if ($o -ceq $a) { exit 0 } else { exit 1 }"

if errorlevel 1 (
    echo [结果] WA   答案错误
    if exist "%1.err" del /f /q "%1.err" >nul 2>nul
    echo ---- 你的输出 ^(%1.out^) ----
    type "%1.out"
    echo ---- 标准答案 ^(%1.ans^) ----
    type "%1.ans"
    set /a FAIL+=1
) else (
    echo [结果] AC   通过
    if exist "%1.out" del /f /q "%1.out" >nul 2>nul
    if exist "%1.err" del /f /q "%1.err" >nul 2>nul
    set /a PASS+=1
)
echo.
exit /b 0