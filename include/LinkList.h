#pragma once
#include"define.h"
//线性表的单链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//当第i个元素存在时，赋值给e并返回OK，否则为ERROR
Status GetElem_L(LinkList L, int i, ElemType& e) {
	return OK;
}