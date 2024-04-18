#include"../include/List.h"
/* ������Ľڵ� n0 ֮�����ڵ� P */
void insert(ListNode* n0, ListNode* P) {
    ListNode* n1 = n0->next;
    P->next = n1;
    n0->next = P;
}
/* ɾ������Ľڵ� n0 ֮����׸��ڵ� */
void remove(ListNode* n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
    // �ͷ��ڴ�
    delete P;
}
/* ��������������Ϊ index �Ľڵ� */
ListNode* access(ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}
/* �������в���ֵΪ target ���׸��ڵ� */
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