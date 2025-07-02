# Creoflow - 游戏开发平台

> 基于GDevelop的开源游戏开发引擎，为中国开发者提供本地化支持

## 项目概述

Creoflow是基于GDevelop的现代化游戏开发平台，提供可视化开发环境，让开发者无需深入编程知识就能创造精美的2D和3D游戏。

## 核心特性

- **无代码开发**: 可视化事件系统
- **多平台支持**: Web、Android、iOS、桌面平台
- **2D/3D游戏**: 支持多种游戏类型
- **实时预览**: 边开发边测试
- **丰富扩展**: 物理引擎、粒子系统等

## 项目架构

- **Core**: C++核心库，项目管理和事件系统
- **GDJS**: TypeScript游戏引擎，基于PixiJS/Three.js
- **newIDE**: React编辑器，可视化开发界面
- **Extensions**: 扩展系统，功能模块
- **GDevelop.js**: C++到JavaScript的WebAssembly桥接

## 快速开始

### 系统要求
- Node.js 18.x LTS
- Python 3.8+
- CMake 3.16+

### 安装步骤

1. 克隆项目并安装依赖
```bash
cd newIDE/app && npm install
cd ../electron-app && npm install
```

2. 构建核心库
```bash
cd ../../GDevelop.js && npm run build
cd ../GDJS && npm run build
```

3. 启动开发环境
```bash
cd ../newIDE/app && npm start
```

## 技术栈

- **前端**: React, Material-UI, Electron
- **渲染**: PixiJS (2D), Three.js (3D)
- **物理**: Box2D (2D), Jolt Physics (3D)
- **构建**: CMake, Webpack, Emscripten

## 贡献指南

1. Fork项目
2. 创建特性分支
3. 提交更改
4. 创建Pull Request

## 许可证

MIT许可证开源发布

---
⭐ 如果觉得有用，请给我们一个Star！ 