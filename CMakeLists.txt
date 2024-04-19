cmake_minimum_required(VERSION 3.10)
project(data_structure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
include_directories(./include)	# 搜索头文件方式

add_executable(main_app main.cpp)
