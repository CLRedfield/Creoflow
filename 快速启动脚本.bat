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
if not exist "Creoflow\newIDE\app" (
    echo ❌ 项目目录不存在，请确保在正确的目录运行此脚本
    pause
    exit /b 1
)

cd Creoflow\newIDE\app

echo.
echo [3/3] 启动开发服务器...
echo 🚀 正在启动Creoflow编辑器...
echo 📝 启动后将在浏览器打开 http://localhost:3000
echo 💡 按 Ctrl+C 停止服务器
echo.

npm start

pause 