#pragma once
#include"../include/List.h"
/* ��������ʵ�ֵ�ջ */
class LinkedListStack
{
public:
	LinkedListStack() {
		stackTop = nullptr;
		stkSize = 0;
	};
	~LinkedListStack() {
		
	};

private:
	ListNode* stackTop;// ��ͷ�ڵ���Ϊջ��
	int stkSize;// ջ�ĳ���
};