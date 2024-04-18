#pragma once

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//status 是函数类型，值为函数结果状态代码
typedef int Status;

typedef int ElemType;//int 可更换为需要的数据类型

typedef Status(*Compare)(ElemType, ElemType); // 定义了一个名为Compare的指向函数的指针类型