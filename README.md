# 目录
- [数据结构](#数据结构)
- [目录结构](#目录结构)
- [环境](#环境)
- [可能遇到的问题](#可能遇到的问题)
  - [CMake的安装](#CMake的安装)
  - [vs2019中文乱码及含有换行符](#vs2019中文乱码及含有换行符)
  - [高级保存选项](#高级保存选项)
- [配置](#配置)
- [后续提交](#后续提交)

# 数据结构

基于《数据结构（C语言版）》清华大学出版社 

这是一个用于学习和实现常见数据结构的项目，包含了链表、栈、队列、树等常见数据结构的实现。



# 目录结构
Data_Structure/ # 项目根目录   
> CMakeLists.txt # CMake 构建文件，定义构建规则  
> README.md # 项目说明文件，包含项目简介、安装、使用说明  

> include/ # 存放所有头文件  
>> LinkList.h # 链表头文件  
>> Stack.h # 栈头文件  
>> Queue.h # 队列头文件  
>> Tree.h # 树头文件  

> src/ # 存放所有源文件（.cpp）  
>> LinkList.cpp # 链表实现文件  
>> Stack.cpp # 栈实现文件  
>> Queue.cpp # 队列实现文件  
>> Tree.cpp # 树实现文件  
>> main.cpp # 主程序入口（如果有）  

> test/ # 存放单元测试文件  
>> test_linklist.cpp # 链表单元测试  
>> test_stack.cpp # 栈单元测试  
>> test_queue.cpp # 队列单元测试  
>> test_tree.cpp # 树单元测试  

> build/ #构建目录


# 环境

windows 10

Visual Studio 2019

cmake  3.29.2

# 可能遇到的问题

## CMake的安装

直通点：[戳这里](https://blog.csdn.net/sanqima/article/details/132634898?ops_request_misc=&request_id=&biz_id=102&utm_term=cmake%20windows&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-132634898.142^v100^pc_search_result_base7&spm=1018.2226.3001.4187)

## vs2019中文乱码及含有换行符

直通点：[戳这里](https://blog.csdn.net/weixin_44153180/article/details/127592831?ops_request_misc=%257B%2522request%255Fid%2522%253A%252248d51ab21c1ba9fdf459c4d2ddee6c52%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=48d51ab21c1ba9fdf459c4d2ddee6c52&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-127592831-null-null.142^v100^pc_search_result_base1&utm_term=vs2019%20%E6%8F%90%E7%A4%BA%E5%B8%B8%E9%87%8F%E4%B8%AD%E6%9C%89%E6%8D%A2%E8%A1%8C%E7%AC%A6&spm=1018.2226.3001.4187)

## 高级保存选项

直通点：[戳这里](https://blog.csdn.net/L_Andy/article/details/126425393?ops_request_misc=%257B%2522request%255Fid%2522%253A%252238c4b6dddfb7e703ce1e5bf3f5092b47%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=38c4b6dddfb7e703ce1e5bf3f5092b47&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-126425393-null-null.142^v100^pc_search_result_base1&utm_term=vs2019%E7%9A%84%E9%AB%98%E7%BA%A7%E4%BF%9D%E5%AD%98%E9%80%89%E9%A1%B9&spm=1018.2226.3001.4187)

# 配置



- 清空build

   ![](https://github.com/369qwer/Data_Structure/blob/master/Sample%20Photos/1.png)

- 进入cmd
  
   ![](https://github.com/369qwer/Data_Structure/blob/master/Sample%20Photos/2.png)

- 使用cmake编译

  ```
  cmake ..
  ```
   ![](https://github.com/369qwer/Data_Structure/blob/master/Sample%20Photos/3.png)


- 打开.sln

- 设置启动项

- 进行调试
 
 ![](https://github.com/369qwer/Data_Structure/blob/master/Sample%20Photos/4.png)
  


  

# 后续提交


## 步骤 1: 拉取远程仓库的更改

使用以下命令拉取远程仓库中的最新更改，并尝试自动合并到您的本地分支：
```
git pull origin master
```
这里假设您正在使用名为 origin 的远程仓库，且您的分支名为 master。这个命令会从 origin 拉取 master 分支的更改，并尝试将这些更改合并到您当前的本地分支。

## 步骤 2: 上传

```
git add .
git commit -m "A brief description of changes"
git push
```



