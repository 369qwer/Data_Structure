# 查找 include 文件夹下的所有 .h 文件
file(GLOB HEADER_FILES "include/*.h")

#add_executable(include
#       define.h List.h
#      SqList.h Stack.h SLinkList.h
#      MyFun.h
#      )
# 添加可执行文件，并包含所有找到的头文件
add_executable((include
    ${HEADER_FILES}   # 这里将所有的 .h 文件传递给 add_executable
)