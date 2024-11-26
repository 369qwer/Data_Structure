#pragma once
#include"define.h"
#include <malloc.h>
#include<iostream>
#include"MyFun.h"
//线性表的单链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;


//逆序位输入n个元素的值，建立带表头节点的单链线性表
Status CreateList_L(LinkList& L,int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = nullptr;//先建立一个带头结点的单链表
	std::cout << "enter " << n << " elem（逆序位输入）:";
	for (int i = n; i >0; i--)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));//生成新结点
		std::cin>>p->data;//输入元素值
		p->next = L->next;
		L->next = p;//插入到表头

	}
	return OK;
}

//当第i个元素存在时，赋值给e并返回OK，否则为ERROR
Status GetElem_L(LinkList L, int i, ElemType& e) {
	LNode* p = L->next;int j = 1;//初始化，p指向第一个结点，j为计数器
	while (p&&j<i)
	{
		p = p->next; ++j;
	}
	if (!p || j > i)return ERROR;	//第i个元素不存在
	e = p->data;		//取第i个元素
	return OK;
}


//删除L中第i个元素，用e返回
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
	LinkList p = L;
	int j = 0;
	while (p->next&&j<i-1)//寻找第i个结点，并令p指向其前驱
	{
		p = p->next; ++j;
	}
	if (!(p->next) || j > i - 1)return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}


//归并两个单链表
void MergeList_L(LinkList &La, LinkList &Lb, LinkList& Lc) {
	//已知单链表La和Lb的元素按值非递减排列
	//归并后Lc也按值非递减排列
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = La;//用La的头结点作为Lc的头结点
	Lc = pc;
	while (pa&&pb)
	{
		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else {
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;//插入剩余段
	free(Lb);
}


//依次调用visit()
Status ListTraverse_L(LinkList L, Visit myVisit) {
	LinkList p = L->next;
	if (p== nullptr)return ERROR;
	while(p->next) {
		if (myVisit(p->data) != OK)return ERROR;
		p = p->next;
	}
	myVisit(p->data);
	return OK;
}