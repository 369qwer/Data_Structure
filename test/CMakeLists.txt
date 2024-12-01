# 查找 test 目录下所有的 .cpp 文件
file(GLOB TEST_SOURCES "*.cpp")

# 创建测试目标：这是一个可执行文件
add_executable(Tests ${TEST_SOURCES})

#add_executable(Tests main.cpp)

# 添加 include 目录，以便测试代码可以访问头文件
target_include_directories(Tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# 将静态库 my_project 链接到测试可执行文件
target_link_libraries(Tests PRIVATE my_project)


# 注册测试
add_test(NAME MyTests COMMAND Tests)