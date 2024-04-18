#include"include/SqList.h"
#include"MyFun.h"
#include<iostream>
int main() {
	SqList S;
	int w,x;
	InitList_Sq(S);
	//std::cout << ListLength(S) << std::endl;
	//std::cout << w << std::endl;
	//std::cout << DestroyList_Sq(S)<<std::endl;
	ListInsert_Sq(S, 1, 5);
	GetElem_Sq(S, 1, w);
	ListDelete_Sq(S, 1, x);
	std::cout <<w<<std::endl;
	std::cout << x << std::endl;
	std::cout << ListEmpty_Sq(S)<<std::endl;	
	Compare f = ComparisonFunction;
	std::cout << LocateElem_Sq(S, 1, f) << std::endl;
	return OK;
}