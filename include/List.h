#pragma once
#include"define.h"
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
/* ������Ľڵ� n0 ֮�����ڵ� P */
void insert(ListNode* n0, ListNode* P);
/* ɾ������Ľڵ� n0 ֮����׸��ڵ� */
void remove(ListNode* n0);
/* ��������������Ϊ index �Ľڵ� */
ListNode* access(ListNode* head, int index);
/* �������в���ֵΪ target ���׸��ڵ� */
int find(ListNode* head, int target);
