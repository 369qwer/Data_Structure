# 创建一个静态库
# 查找所有的 .cpp 文件
file(GLOB SRC_SOURCES "*.cpp")
add_library(my_project STATIC ${SRC_SOURCES})

# 将 include 目录添加为头文件搜索路径
target_include_directories(my_project PRIVATE ${PROJECT_SOURCE_DIR}/include)
