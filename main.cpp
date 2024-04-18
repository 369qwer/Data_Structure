#include"include/SqList.h"
#include<iostream>
int main() {
	SqList S;
	int w,x;
	InitList_Sq(S);
	//std::cout << ListLength(S) << std::endl;
	//std::cout << w << std::endl;
	//std::cout << DestroyList_Sq(S)<<std::endl;
	ListInsert_Sq(S, 1, 5);
	ListInsert_Sq(S, 2, 66);
	ListInsert_Sq(S, 3, 555);
	//GetElem_Sq(S, 1, w);
	//ListDelete_Sq(S, 1, x);
	//std::cout << x << std::endl;
	//std::cout << ListEmpty_Sq(S)<<std::endl;	
	PriorElem(S, 555, w);
	std::cout <<w<<std::endl;

	return OK;
}