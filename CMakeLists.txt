cmake_minimum_required(VERSION 3.10)
project(data_structure)

set(CMAKE_CXX_STANDARD 11)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加src目录
add_subdirectory(src)

# 添加test目录
add_subdirectory(test)

