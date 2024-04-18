#pragma once
#include"../include/List.h"
/* 基于链表实现的栈 */
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
	ListNode* stackTop;// 将头节点作为栈顶
	int stkSize;// 栈的长度
};