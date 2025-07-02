@echo off
chcp 65001 >nul
title Creoflow 快速启动脚本

echo ================================================
echo            Creoflow 游戏开发平台
echo ================================================
echo.

echo [1/3] 检查环境...
node --version >nul 2>&1
if errorlevel 1 (
    echo ❌ 未找到Node.js，请先安装Node.js 18.x LTS
    echo 📥 下载地址: https://nodejs.org/
    pause
    exit /b 1
)

echo ✅ Node.js版本: 
node --version

echo.
echo [2/3] 进入项目目录...
if not exist "newIDE\app" (
    echo ❌ 项目目录不存在，请确保在正确的目录运行此脚本
    pause
    exit /b 
)

cd newIDE\app

echo.
echo [3/4] 检查并安装依赖...
if not exist "node_modules" (
    echo 📦 首次运行，正在安装依赖包...
    echo ⏳ 这可能需要几分钟时间，请耐心等待...
    npm install
    if errorlevel 1 (
        echo ❌ 依赖安装失败，请检查网络连接
        pause
        exit /b 1
    )
) else (
    echo ✅ 依赖已存在，跳过安装
)

echo.
echo [4/4] 启动开发服务器...
echo 🚀 正在启动Creoflow编辑器...
echo 📝 启动后将在浏览器打开 http://localhost:3000
echo 💡 按 Ctrl+C 停止服务器
echo.

npm start

pause 