//线性表的动态分配顺序存储结构

#include"../include/SqList.h"

#include"MyFun.h"
#include<iostream>
int main() {
	SqList S1;
	SqList S2;
	SqList S3;
	int w, x;
	InitList_Sq(S1);
	InitList_Sq(S2);
	//插入元素
	ListInsert_Sq(S1, 1, 5);
	ListInsert_Sq(S1, 2, 66);
	ListInsert_Sq(S2, 1, 555);

	//测试归并
	MergeList_Sq(S1, S2, S3);
	std::cout << ListLength_Sq(S3) << std::endl;
	
	
	ListTraverse_Sq(S3, VisitFunction);

	//std::cout << ListLength_Sq((S) << std::endl;
	//std::cout << w << std::endl;
	//std::cout << DestroyList_Sq(S)<<std::endl;
	//GetElem_Sq(S, 1, w);
	//ListDelete_Sq(S, 1, x);
	//std::cout << x << std::endl;
	//std::cout << ListEmpty_Sq(S)<<std::endl;	

	//测试前驱、后继函数
#if 0
	PriorElem_Sq(S, 555, w);
	std::cout << w << std::endl;
	NextElem_Sq(S, 5, x);
	std::cout << x << std::endl;
#endif

	//测试LocateElem_Sq查找第一个值与e满足compare（）元素的位序
#if 0
	std::cout << LocateElem_Sq(S, 66, ComparisonFunction);
#endif 

	//测试 ListTraverse_Sq依次调用visit()




	return OK;
}