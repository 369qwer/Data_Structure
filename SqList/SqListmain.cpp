//���Ա�Ķ�̬����˳��洢�ṹ

#include"../include/SqList.h"

#include"MyFun.h"
#include<iostream>
int main() {
	SqList S;
	int w, x;
	InitList_Sq(S);
	//����Ԫ��
	ListInsert_Sq(S, 1, 5);
	ListInsert_Sq(S, 2, 66);
	ListInsert_Sq(S, 3, 555);

	//std::cout << ListLength(S) << std::endl;
	//std::cout << w << std::endl;
	//std::cout << DestroyList_Sq(S)<<std::endl;
	//GetElem_Sq(S, 1, w);
	//ListDelete_Sq(S, 1, x);
	//std::cout << x << std::endl;
	//std::cout << ListEmpty_Sq(S)<<std::endl;	

	//����ǰ������̺���
#if 1
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
#if 0
	ListTraverse_Sq(S, VisitFunction);
#endif // 1

	return OK;
}