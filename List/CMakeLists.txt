cmake_minimum_required(VERSION 3.10)
project(List)

add_library(List STATIC List.cpp)
target_include_directories(List PUBLIC ../include)