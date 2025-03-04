cmake_minimum_required(VERSION 3.4...3.18)

# 包含 Conan 生成的工具链文件
set(CMAKE_TOOLCHAIN_FILE
"${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/generators/conan_toolchain.cmake")
include(${CMAKE_TOOLCHAIN_FILE})

find_package(pybind11 REQUIRED)

pybind11_add_module(example pybind/callback.cpp)
