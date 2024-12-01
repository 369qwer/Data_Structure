#include"LinkList.h"
#include"SLinkList.h"
#include "SqList.h"
#include <iostream>
using namespace std;
// ���ʺ���ʵ��
Status PrintElem(ElemType e) {
    cout << e << " ";
    return OK;
}

// �ȽϺ���ʵ��
Status CompareElem(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}

// �������ܲ���
void TestBasicOperations() {
    cout << "=== ����Sqlist�������� ===\n";
    SqList L;
    // ��ʼ������
    if (InitList_Sq(L) == OK) {
        cout << "�б��ʼ���ɹ���\n";
    }

    // �������
    for (int i = 1; i <= 5; i++) {
        if (ListInsert_Sq(L, i, i * 10) == OK) {
            cout << "����Ԫ�� " << i * 10 << " �ɹ���\n";
        }
    }

    // ��������
    cout << "��ǰ�б�����:";
    ListTraverse_Sq(L, PrintElem);
    cout << "\n";

    // ��ȡԪ�ز���
    ElemType e;
    if (GetElem_Sq(L, 3, e) == OK) {
        cout << "��3��Ԫ����:" << e << "\n";
    }

    // ɾ������
    if (ListDelete_Sq(L, 2, e) == OK) {
        cout << "ɾ����2��Ԫ��:" << e << " �ɹ���\n";
    }

    cout << "ɾ������б�:";
    ListTraverse_Sq(L, PrintElem);
    cout << "\n";

    // ���ٲ���
    if (DestroyList_Sq(L) == OK) {
        cout << "�б����ٳɹ���\n";
    }
}

// �ϲ���������
void TestMergeList() {
    cout << "\n=== ���Ժϲ����� ===\n";
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);

    // ��La������������
    ListInsert_Sq(La, 1, 1);
    ListInsert_Sq(La, 2, 3);
    ListInsert_Sq(La, 3, 5);

    // ��Lb������������
    ListInsert_Sq(Lb, 1, 2);
    ListInsert_Sq(Lb, 2, 4);
    ListInsert_Sq(Lb, 3, 6);

    cout << "La����:";
    ListTraverse_Sq(La, PrintElem);
    cout << "\n";

    cout << "Lb����:";
    ListTraverse_Sq(Lb, PrintElem);
    cout << "\n";

    // �ϲ�����
    MergeList_Sq(La, Lb, Lc);
    cout << "�ϲ���Lc������:";
    ListTraverse_Sq(Lc, PrintElem);
    cout << "\n";

    // ������Դ
    DestroyList_Sq(La);
    DestroyList_Sq(Lb);
    DestroyList_Sq(Lc);
}

// �߽���������
void TestBoundaryConditions() {
    cout << "\n=== ���Ա߽����� ===\n";
    SqList L;
    InitList_Sq(L);
    ElemType e;

    // �ձ����
    cout << "�ձ���ԣ�\n";
    if (ListEmpty_Sq(L)) {
        cout << "�б�Ϊ��\n";
    }

    // Խ�����
    cout << "Խ�������ԣ�λ��0����" <<
        (ListInsert_Sq(L, 0, 100) == ERROR ? "����ͨ��" : "����ʧ��") << "\n";

    // �������ɾ���������Ƿ���ȷ
    ListInsert_Sq(L, 1, 100);
    cout << "����Ԫ��100�󳤶ȣ�" << ListLength_Sq(L) << "\n";
    ListDelete_Sq(L, 1, e);
    cout << "ɾ���󳤶ȣ�" << ListLength_Sq(L) << "\n";

    DestroyList_Sq(L);
}

//����LinkList
void TestLinkList() {
    LinkList L;
    ElemType e;

    std::cout << "=== ���Դ������� ===" << std::endl;
    CreateList_L(L, 5);  // ��������: 5 4 3 2 1
    std::cout << "��������ɣ�˳���������Ԫ�أ�" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== ���Բ������ ===" << std::endl;
    ListInsert_L(L, 3, 99);  // �ڵ�3��λ�ò���99
    std::cout << "��λ��3����99�������" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== ���Ի�ȡԪ�� ===" << std::endl;
    if (GetElem_L(L, 3, e) == OK) {
        std::cout << "��3��λ�õ�Ԫ���ǣ�" << e << std::endl;
    }

    std::cout << "\n=== ����ɾ������ ===" << std::endl;
    if (ListDelete_L(L, 3, e) == OK) {
        std::cout << "ɾ����3��λ�õ�Ԫ�أ�" << e << std::endl;
        std::cout << "ɾ���������" << std::endl;
        ListTraverse_L(L, PrintElem);
        std::cout << std::endl;
    }

    std::cout << "\n=== ���Ժϲ����� ===" << std::endl;
    LinkList L1, L2, L3;
    std::cout << "������һ����������" << std::endl;
    CreateList_L(L1, 3);  // ��������: 5 3 1
    std::cout << "�����ڶ�����������" << std::endl;
    CreateList_L(L2, 3);  // ��������: 6 4 2

    std::cout << "��һ������" << std::endl;
    ListTraverse_L(L1, PrintElem);
    std::cout << "\n�ڶ�������" << std::endl;
    ListTraverse_L(L2, PrintElem);

    MergeList_L(L1, L2, L3);
    std::cout << "\n�ϲ��������" << std::endl;
    ListTraverse_L(L3, PrintElem);
    std::cout << std::endl;
}



// �Ľ���ӡ�����Ը���������ʾ���
void PrintList(SLinkList& space, int S) {
    if (!ValidateSLinkList(space, S)) {
        std::cout << "����ṹ�쳣��" << std::endl;
        return;
    }

    int i = space[S].cur;
    if (i == 0) {
        std::cout << "�ռ�" << std::endl;
        return;
    }

    std::cout << "�(A-B)��(B-A)�Ľ��Ϊ��";
    while (i != 0) {
        std::cout << space[i].data << " ";
        i = space[i].cur;
    }
    std::cout << std::endl;
}


// �Ľ��Ĳ��Ժ���
void TestSLinkList() {
    SLinkList space;
    int S;

    std::cout << "�������������ϵ�Ԫ�ظ���(m n): ";
    difference(space, S);

    if (ValidateSLinkList(space, S)) {
        PrintList(space, S);
    }
    else {
        std::cout << "������ʧ�ܣ�" << std::endl;
    }
}
int main() {
    TestSLinkList();
    return 0;
}
