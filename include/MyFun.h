#pragma once
#include"define.h"
#include<iostream>
//比较函数
Status ComparisonFunction(ElemType a, ElemType b) {
    return (a == b) ? TRUE : FALSE;
}
//访问函数
Status VisitFunction(ElemType a) {
    std::cout << a << std::endl;
    return TRUE;
}
