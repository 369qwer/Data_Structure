//���Ա�Ķ�̬����˳��洢�ṹ
#pragma once
#include"SqList.h"

#include"MyFun.h"
#include<iostream>
int main() {
	SqList S1;
	SqList S2;
	SqList S3;
	int w, x;
	InitList_Sq(S1);
	InitList_Sq(S2);
	//����Ԫ��
	ListInsert_Sq(S1, 1, 5);
	ListInsert_Sq(S1, 2, 66);
	ListInsert_Sq(S2, 1, 555);

	//���Թ鲢
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

	//����ǰ������̺���
#if 0
	PriorElem_Sq(S, 555, w);
	std::cout << w << std::endl;
	NextElem_Sq(S, 5, x);
	std::cout << x << std::endl;
#endif

	//����LocateElem_Sq���ҵ�һ��ֵ��e����compare����Ԫ�ص�λ��
#if 0
	std::cout << LocateElem_Sq(S, 66, ComparisonFunction);
#endif 

	//���� ListTraverse_Sq���ε���visit()




	return OK;
}