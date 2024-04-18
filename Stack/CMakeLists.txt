cmake_minimum_required(VERSION 3.10)
project(Stack)

add_library(Stack STATIC Stack.cpp)
target_include_directories(Stack PUBLIC ../include)