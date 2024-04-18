#include"../include/List.h"
/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode* n0, ListNode* P) {
    ListNode* n1 = n0->next;
    P->next = n1;
    n0->next = P;
}
/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode* n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
    // 释放内存
    delete P;
}
/* 访问链表中索引为 index 的节点 */
ListNode* access(ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}
/* 在链表中查找值为 target 的首个节点 */
int find(ListNode* head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}