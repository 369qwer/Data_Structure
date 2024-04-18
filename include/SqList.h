#pragma once
#include"define.h"
#include <malloc.h>
#include <cstdlib> 

//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100	//线性表存储空间的初始分配量
#define LISTINCREMENT  10   //线性表存储空间的分配增量

typedef struct {
	ElemType* elem;		//存储空间基址
	int length;			//当前长度
	int listsize;		//当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

//构造一个空的线性表L
Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);		//存储分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//销毁线性表
Status DestroyList_Sq(SqList& L)
{
	if (!L.elem) {

		free(L.elem);
		L.elem = nullptr;
		L.length = 0;
		L.listsize = 0;
		return OK;
	}
	return ERROR;
}
//将L重置成空表
Status ClearList_Sq(SqList& L)
{
	L.length = 0;
	return OK;
}
//判空（空返回TRUE,否则为FALSE）
Status ListEmpty_Sq(const SqList& L) {
	if (L.length == 0)return TRUE;
	return FALSE;
}
//返回L中数据元素个数
int ListLength_Sq(const SqList& L) {
	return L.length;
}
//用e返回L中第i个数据元素的值
Status GetElem_Sq(const SqList& L, int i, ElemType& e) {
	if (i > ListLength_Sq(L)+1 || i < 1)return ERROR;//i值不合法
	e = L.elem[i - 1];
	return OK;
}
//在L中第i个位置之前插入e
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	//i的合法位置为i>=1&&i<=ListLength_Sq(L)+1
	if (i > ListLength_Sq(L)+1 || i < 1)return ERROR;//i值不合法
	if (L.length >= L.listsize) {
		//储存空间已满，扩容
		ElemType *newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	//将i后的值后移
	for (int j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
//删除L中第i个元素，用e返回
Status ListDelete_Sq(SqList& L, int i, ElemType &e) {
	//i的合法位置为i>=1&&i<=ListLength_Sq(L)+1
	if (i > ListLength_Sq(L)|| i < 1)return ERROR;//i值不合法
	ElemType *p = &(L.elem[i - 1]);
	e = *p;//被删除元素的值
	ElemType *q = L.elem + L.length - 1;//表位元素的位置
	for (++p; p < q; ++p) {//被删除元素之后的元素左移
		*(p - 1) = *p;
	}
	--L.length;//表长减一
	return OK;
}
//在顺序线性表L中查找第一个值与e满足compare（）元素的位序
int LocateElem_Sq(SqList L, ElemType e, Compare myCompare) {
	//若找到，返回L中的位序，否则返回0
	int i = 1;
	ElemType *p = L.elem;
	while (i <= L.length && !myCompare(*p++, e))++i;
	if (i <= L.length)return i;
	return 0;
}
//pre_e返回前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	if (L.length < 2)return ERROR;
	int found = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.elem[i] == cur_e) {
			pre_e = L.elem[i - 1];
			found = 1;
			break;
		}
	}
	return found ? OK : ERROR;
}