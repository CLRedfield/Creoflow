# 这是用于构建 GDevelop 的 CMake 文件。
# 更多信息请参阅 README.md 文件。

# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.5)

# 添加实用工具函数
# 引入CMakeClangUtils.txt脚本，为目标添加clang-format和clang-tidy支持
include(scripts/CMakeClangUtils.txt) 

# 用于定义选项的宏
macro(gd_set_option var default type docstring)
	# 如果变量未定义，则设置默认值
	if(NOT DEFINED ${var})
		set(${var} ${default})
	endif()
	# 将变量设置为缓存条目，以便在CMake GUI中可见
	set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# 设置构建选项
gd_set_option(BUILD_CORE TRUE BOOL "TRUE 以构建 GDevelop核心库")
gd_set_option(BUILD_GDJS TRUE BOOL "TRUE 以构建 GDevelop JS平台")
gd_set_option(BUILD_EXTENSIONS TRUE BOOL "TRUE 以构建扩展")
gd_set_option(BUILD_TESTS TRUE BOOL "TRUE 以构建测试")

# 禁用已弃用的代码
# 强制禁用旧的GUI相关代码
set(NO_GUI TRUE CACHE BOOL "" FORCE)

# 为Linux设置安装目录（必须在“project”命令之前完成）。
if(NOT WIN32)
	if(NOT APPLE)
		# 设置Linux下的安装前缀
		gd_set_option(GD_INSTALL_PREFIX "/opt/gdevelop/" STRING "GDevelop 应安装的目录")
	else()
		# 设置macOS下的安装前缀
		gd_set_option(GD_INSTALL_PREFIX "." STRING "GDevelop 应安装的目录")
	endif()

	# 由于我们嵌入了SFML，防止其被安装到系统范围
	set(CMAKE_INSTALL_PREFIX "${GD_INSTALL_PREFIX}/useless")
endif()

# 定义项目名称
project(GDevelop)
# 生成compile_commands.json，供clangd等工具使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 在非Windows、非Apple且不构建测试时，跳过构建rpath，以避免Linux打包时出错
if(NOT WIN32 AND NOT APPLE AND NOT BUILD_TESTS)
	set(CMAKE_SKIP_BUILD_RPATH TRUE)
endif()
# macOS特定设置
if(APPLE)
	set(CMAKE_MACOSX_RPATH 1)
	set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
	set(CMAKE_INSTALL_RPATH ".")
	set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
	add_compile_options(
		-D_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_
		-Wno-potentially-evaluated-expression)
endif()
# 合法性检查
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
	# 如果未指定构建类型，则默认为Release
	message(STATUS "CMAKE_BUILD_TYPE is empty, assuming build type is Release")
	set(CMAKE_BUILD_TYPE Release)
endif()

# 在Release模式下，非Windows且使用GCC时，强制剥离符号，以避免Linux打包时出错
if("${CMAKE_BUILD_TYPE}" STREQUAL "Release" AND NOT WIN32 AND CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_SHARED_LINKER_FLAGS "-s")
endif()

# 激活C++11
set(CMAKE_CXX_STANDARD 11) # 应该尝试升级到 C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 将一些警告标记为错误
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	# 激活尽可能多的警告，以避免诸如未初始化变量或其他难以调试的错误
	add_compile_options(
		-Wall
		-Wextra
		-Wuninitialized
		-Wconditional-uninitialized
		-Wno-unknown-warning-option
		-Wno-reorder-ctor
		-Wno-reorder
		-Wno-unused-parameter
		-Wno-pessimizing-move
		-Wno-unused-variable # 不是好的风格，但没有风险
		-Wno-unused-private-field
		-Wno-ignored-qualifiers # 没有风险
		-Wno-sign-compare # 风险不大

		# 将尽可能多的警告视为错误（目前只有一个）
		-Werror=return-stack-address
		-Werror=return-type)
endif()

# 定义通用目录:
set(GD_base_dir ${CMAKE_CURRENT_SOURCE_DIR})

# 添加所有的CMakeLists:
add_subdirectory(ExtLibs)
if(BUILD_CORE)
	add_subdirectory(Core)
endif()
if(BUILD_GDJS)
	add_subdirectory(GDJS)
endif()
if(EMSCRIPTEN)
	add_subdirectory(GDevelop.js)
endif()
if(BUILD_EXTENSIONS)
	add_subdirectory(Extensions)
endif()
