#pragma once

#include"LinkList.h"
#include"SqList.h"
//#include"MyFun.h"
#include<iostream>
using namespace std;
// ����SqList
void TestSqList() {
    cout << "=== ����˳����������� ===\n";
    
    // ����˳���
    cout << "\n--- ����˳��� ---\n";
    SqList sqList;
    ElemType e;

    // ��ʼ������
    if (InitList_Sq(sqList) == OK) {
        cout << "˳����ʼ���ɹ���\n";
    }

    // �������
    for (int i = 1; i <= 5; i++) {
        if (ListInsert_Sq(sqList, i, i * 10) == OK) {
            cout << "����Ԫ�� " << i * 10 << " �ɹ���\n";
        }
    }

    // ��������
    cout << "��ǰ˳�������:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // ��ȡԪ�ز���
    if (GetElem_Sq(sqList, 3, e) == OK) {
        cout << "˳����3��Ԫ����:" << e << "\n";
    }

    // ɾ������
    if (ListDelete_Sq(sqList, 2, e) == OK) {
        cout << "ɾ��˳����2��Ԫ��:" << e << " �ɹ���\n";
    }

    cout << "ɾ�����˳���:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // ˳���ϲ�����
    SqList sqLa, sqLb, sqLc;
    InitList_Sq(sqLa);
    InitList_Sq(sqLb);
    InitList_Sq(sqLc);

    // ��sqLa������������
    ListInsert_Sq(sqLa, 1, 1);
    ListInsert_Sq(sqLa, 2, 3);
    ListInsert_Sq(sqLa, 3, 5);

    // ��sqLb������������
    ListInsert_Sq(sqLb, 1, 2);
    ListInsert_Sq(sqLb, 2, 4);
    ListInsert_Sq(sqLb, 3, 6);

    cout << "sqLa����:";
    ListTraverse_Sq(sqLa, PrintElem);
    cout << "\n";

    cout << "sqLb����:";
    ListTraverse_Sq(sqLb, PrintElem);
    cout << "\n";

    // �ϲ�����
    MergeList_Sq(sqLa, sqLb, sqLc);
    cout << "�ϲ���sqLc������:";
    ListTraverse_Sq(sqLc, PrintElem);
    cout << "\n";

    // ˳���߽���������
    cout << "\n--- ˳���߽��������� ---\n";
    SqList sqListBoundary;
    InitList_Sq(sqListBoundary);

    // �ձ����
    if (ListEmpty_Sq(sqListBoundary)) {
        cout << "˳���Ϊ��\n";
    }

    // Խ�����
    cout << "Խ�������ԣ�λ��0����" <<
        (ListInsert_Sq(sqListBoundary, 0, 100) == ERROR ? "����ͨ��" : "����ʧ��") << "\n";

    // �������ɾ���������Ƿ���ȷ
    ListInsert_Sq(sqListBoundary, 1, 100);
    cout << "����Ԫ��100�󳤶ȣ�" << ListLength_Sq(sqListBoundary) << "\n";
    ListDelete_Sq(sqListBoundary, 1, e);
    cout << "ɾ���󳤶ȣ�" << ListLength_Sq(sqListBoundary) << "\n";

    // ����˳���
    DestroyList_Sq(sqList);
    DestroyList_Sq(sqLa);
    DestroyList_Sq(sqLb);
    DestroyList_Sq(sqLc);
    DestroyList_Sq(sqListBoundary);

    // ��������
    cout << "\n--- �������� ---\n";
    LinkList linkList;

    cout << "=== ���Դ������� ===\n";
    CreateList_L(linkList, 5);  // ��������: 5 4 3 2 1
    cout << "��������ɣ�˳���������Ԫ��:\n";
    ListTraverse_L(linkList, PrintElem);
    cout << "\n";

    cout << "\n=== �������������� ===\n";
    ListInsert_L(linkList, 3, 99);  // �ڵ�3��λ�ò���99
    cout << "��λ��3����99�������:\n";
    ListTraverse_L(linkList, PrintElem);
    cout << "\n";

    cout << "\n=== ���������ȡԪ�� ===\n";
    if (GetElem_L(linkList, 3, e) == OK) {
        cout << "�����3��λ�õ�Ԫ����:" << e << "\n";
    }

    cout << "\n=== ��������ɾ������ ===\n";
    if (ListDelete_L(linkList, 3, e) == OK) {
        cout << "ɾ�������3��λ�õ�Ԫ��:" << e << "\n";
        cout << "ɾ���������:\n";
        ListTraverse_L(linkList, PrintElem);
        cout << "\n";
    }

    cout << "\n=== ��������ϲ����� ===\n";
    LinkList linkList1, linkList2, linkList3;
    cout << "������һ����������:\n";
    CreateList_L(linkList1, 3);  // ��������: 5 3 1
    cout << "�����ڶ�����������:\n";
    CreateList_L(linkList2, 3);  // ��������: 6 4 2

    cout << "��һ������:\n";
    ListTraverse_L(linkList1, PrintElem);
    cout << "\n�ڶ�������:\n";
    ListTraverse_L(linkList2, PrintElem);

    MergeList_L(linkList1, linkList2, linkList3);
    cout << "\n�ϲ��������:\n";
    ListTraverse_L(linkList3, PrintElem);
    cout << "\n";
}
//����LinkList
void TestLinkList() {
    LinkList L;
    ElemType e;

    std::cout << "=== ���Դ������� ===" << std::endl;
    CreateList_L(L, 5);  // ��������: 5 4 3 2 1
    std::cout << "��������ɣ�˳���������Ԫ��:" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== ���Բ������ ===" << std::endl;
    ListInsert_L(L, 3, 99);  // �ڵ�3��λ�ò���99
    std::cout << "��λ��3����99�������:"<< std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== ���Ի�ȡԪ�� ===" << std::endl;
    if (GetElem_L(L, 3, e) == OK) {
        std::cout << "��3��λ�õ�Ԫ����:" << e << std::endl;
    }

    std::cout << "\n=== ����ɾ������ ===" << std::endl;
    if (ListDelete_L(L, 3, e) == OK) {
        std::cout << "ɾ����3��λ�õ�Ԫ��:" << e << std::endl;
        std::cout << "ɾ���������:" << std::endl;
        ListTraverse_L(L, PrintElem);
        std::cout << std::endl;
    }

    std::cout << "\n=== ���Ժϲ����� ===" << std::endl;
    LinkList L1, L2, L3;
    std::cout << "������һ����������:" << std::endl;
    CreateList_L(L1, 3);  // ��������: 5 3 1
    std::cout << "�����ڶ�����������:" << std::endl;
    CreateList_L(L2, 3);  // ��������: 6 4 2

    std::cout << "��һ������:" << std::endl;
    ListTraverse_L(L1, PrintElem);
    std::cout << "\n�ڶ�������:" << std::endl;
    ListTraverse_L(L2, PrintElem);

    MergeList_L(L1, L2, L3);
    std::cout << "\n�ϲ��������:" << std::endl;
    ListTraverse_L(L3, PrintElem);
    std::cout << std::endl;
}

void menu() {

}
