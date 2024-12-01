#pragma once
#include"define.h"
#include<iostream>

//比较函数 - 比较两个元素是否相等
inline Status ComparisonFunction(ElemType a, ElemType b) {
    return (a == b) ? TRUE : FALSE;
}

//访问函数 - 打印元素
inline Status PrintElem(ElemType a) {
    std::cout << a << " ";  // 改为空格分隔,不换行
    return TRUE;
}

//交换函数 - 交换两个元素
inline void Swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

//大小比较函数 - 判断a是否大于b
inline Status Greater(ElemType a, ElemType b) {
    return (a > b) ? TRUE : FALSE;
}

//大小比较函数 - 判断a是否小于b  
inline Status Less(ElemType a, ElemType b) {
    return (a < b) ? TRUE : FALSE;
}
