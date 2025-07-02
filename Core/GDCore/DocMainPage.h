/**
 * \mainpage Creoflow 核心库
 * \image html gdlogo.png
 * \section welcome Creoflow 核心库文档
 *
 * **Creoflow 核心库**包含了 Creoflow 游戏的结构、*平台*和*Creoflow IDE*使用的类和工具。
 *
 * \section gettingstarted 快速开始
 *
 * 在大多数情况下，您应该首先<a href="https://github.com/4ian/GDevelop/blob/master/newIDE/README.md">安装并启动 Creoflow 的开发版本</a>。
 *
 * - 如果您有兴趣为 Creoflow 编写扩展，请阅读<a href="https://github.com/4ian/GDevelop/blob/master/newIDE/README-extensions.md">关于扩展的文档</a>。
 * - 如果您想深入了解 Creoflow 的架构并在核心部分工作，请阅读<a href="https://github.com/4ian/GDevelop/blob/master/Core/GDevelop-Architecture-Overview.md">Creoflow 架构概述</a>。然后，您可以浏览此参考文档以获取有关类或函数的更多信息。
 *
 * \section other 其他文档
 *
 * Creoflow 围绕`核心库`（此库）、游戏引擎（`GDJS`）和扩展（`Extensions`文件夹）构建。编辑器（`newIDE`文件夹）使用所有这些库。
 *
 *  - [打开 Creoflow JS 平台文档](../GDJS Documentation/index.html)
 *  - <a href="https://github.com/4ian/GDevelop/blob/master/newIDE/README.md">编辑器入门指南</a>
 *  - <a href="https://github.com/4ian/GDevelop/blob/master/newIDE/README-extensions.md">扩展开发入门指南</a>
 */

/**
 * \defgroup PlatformDefinition 平台定义（所有平台使用的通用类）
 *
 * 定义所有平台使用的通用概念的类：gd::Project、gd::Layout...
 */

/**
 * \defgroup IDE IDE 类（用于实现开发环境的类）
 *
 * 用于实现开发环境的类。
 */

/**
 * \defgroup IDEDialogs IDE 对话框（用于实现开发环境的预制对话框）
 *
 * 用于实现开发环境的预制对话框
 */

/**
 * \defgroup IDEDialogsEventsEditor 事件编辑器相关类
 *
 * 用于实现事件编辑器的类和工具。
 * \ingroup IDEDialogs
 */

/**
 * \defgroup Events 事件（定义事件系统和与事件相关的一些工具的类）
 *
 * 定义事件系统和与事件相关的一些工具的类
 */

/**
 * \defgroup CommonProgrammingTools 通用编程工具
 *
 * 编程用的通用函数和工具。
 */

/**
 * \defgroup SpriteObjectExtension 标准精灵对象扩展
 * \ingroup BuiltinExtensions
 */