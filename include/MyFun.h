#pragma once
#include"define.h"
#include<iostream>
//�ȽϺ���
Status ComparisonFunction(ElemType a, ElemType b) {
    return (a == b) ? TRUE : FALSE;
}
//���ʺ���
Status VisitFunction(ElemType a) {
    std::cout << a << std::endl;
    return TRUE;
}