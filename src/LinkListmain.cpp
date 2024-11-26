#include"LinkList.h"
#include<iostream>
int main() {
	LinkList L1;
	LinkList L2;
	LinkList L3;
	ElemType e;
	CreateList_L(L1, 3);CreateList_L(L2, 3);
	
	MergeList_L(L1, L2, L3);
	ListTraverse_L(L3, VisitFunction);

	//GetElem_L(L1, 1, e);
	//std::cout << e << std::endl;
	
	//ListDelete_L(L, 2, e);
	//std::cout << e << std::endl;
	return 0;
}