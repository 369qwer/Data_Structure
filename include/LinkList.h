#pragma once
#include"define.h"
//���Ա�ĵ�����洢�ṹ
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//����i��Ԫ�ش���ʱ����ֵ��e������OK������ΪERROR
Status GetElem_L(LinkList L, int i, ElemType& e) {
	return OK;
}