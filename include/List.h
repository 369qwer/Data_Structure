#pragma once
#include"define.h"
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode* n0, ListNode* P);
/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode* n0);
/* 访问链表中索引为 index 的节点 */
ListNode* access(ListNode* head, int index);
/* 在链表中查找值为 target 的首个节点 */
int find(ListNode* head, int target);
