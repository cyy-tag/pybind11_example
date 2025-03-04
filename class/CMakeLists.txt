cmake_minimum_required(VERSION 3.4...3.18)

# 包含 Conan 生成的工具链文件
set(CMAKE_TOOLCHAIN_FILE
"${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/generators/conan_toolchain.cmake")
include(${CMAKE_TOOLCHAIN_FILE})

#lto-wrapper: warning
set(CMAKE_LINKER "gold")

# 使用 find_package 查找依赖项
find_package(pybind11 REQUIRED)

# 添加模块
pybind11_add_module(example pybind/pybind_foo.cpp)
