cmake_minimum_required(VERSION 3.10)
project(List)

add_library(SqList STATIC SqList.cpp)
target_include_directories(SqList PUBLIC ../include)