#pragma once
#include"define.h"
#include<iostream>
//比较函数
inline Status ComparisonFunction(ElemType a, ElemType b) {
    return (a == b) ? TRUE : FALSE;
}
//访问函数
inline Status PrintElem(ElemType a) {
    std::cout << a << std::endl;
    return TRUE;
}
