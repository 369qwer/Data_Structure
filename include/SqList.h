#pragma once
#include"define.h"
#include <malloc.h>
#include <cstdlib> 

//���Ա�Ķ�̬����˳��洢�ṹ
#define LIST_INIT_SIZE 100	//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10   //���Ա�洢�ռ�ķ�������

typedef struct {
	ElemType* elem;		//�洢�ռ��ַ
	int length;			//��ǰ����
	int listsize;		//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;

//����һ���յ����Ա�L
Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);		//�洢����ʧ��
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//�������Ա�
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
//��L���óɿձ�
Status ClearList_Sq(SqList& L)
{
	L.length = 0;
	return OK;
}
//�пգ��շ���TRUE,����ΪFALSE��
Status ListEmpty_Sq(const SqList& L) {
	if (L.length == 0)return TRUE;
	return FALSE;
}
//����L������Ԫ�ظ���
int ListLength_Sq(const SqList& L) {
	return L.length;
}
//��e����L�е�i������Ԫ�ص�ֵ
Status GetElem_Sq(const SqList& L, int i, ElemType& e) {
	if (i > ListLength_Sq(L)+1 || i < 1)return ERROR;//iֵ���Ϸ�
	e = L.elem[i - 1];
	return OK;
}
//��L�е�i��λ��֮ǰ����e
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	//i�ĺϷ�λ��Ϊi>=1&&i<=ListLength_Sq(L)+1
	if (i > ListLength_Sq(L)+1 || i < 1)return ERROR;//iֵ���Ϸ�
	if (L.length >= L.listsize) {
		//����ռ�����������
		ElemType *newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	//��i���ֵ����
	for (int j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
//ɾ��L�е�i��Ԫ�أ���e����
Status ListDelete_Sq(SqList& L, int i, ElemType &e) {
	//i�ĺϷ�λ��Ϊi>=1&&i<=ListLength_Sq(L)+1
	if (i > ListLength_Sq(L)|| i < 1)return ERROR;//iֵ���Ϸ�
	ElemType *p = &(L.elem[i - 1]);
	e = *p;//��ɾ��Ԫ�ص�ֵ
	ElemType *q = L.elem + L.length - 1;//��λԪ�ص�λ��
	for (++p; p < q; ++p) {//��ɾ��Ԫ��֮���Ԫ������
		*(p - 1) = *p;
	}
	--L.length;//����һ
	return OK;
}
//��˳�����Ա�L�в��ҵ�һ��ֵ��e����compare����Ԫ�ص�λ��
int LocateElem_Sq(SqList L, ElemType e, Compare myCompare) {
	//���ҵ�������L�е�λ�򣬷��򷵻�0
	int i = 1;
	ElemType *p = L.elem;
	while (i <= L.length && !myCompare(*p++, e))++i;
	if (i <= L.length)return i;
	return 0;
}
//pre_e����ǰ��
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