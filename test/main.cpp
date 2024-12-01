#include"LinkList.h"
#include"SLinkList.h"
#include "SqList.h"
#include <iostream>
using namespace std;
// 访问函数实现
Status PrintElem(ElemType e) {
    cout << e << " ";
    return OK;
}

// 比较函数实现
Status CompareElem(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE : FALSE;
}

// 基础功能测试
void TestBasicOperations() {
    cout << "=== 测试Sqlist基础操作 ===\n";
    SqList L;
    // 初始化测试
    if (InitList_Sq(L) == OK) {
        cout << "列表初始化成功！\n";
    }

    // 插入测试
    for (int i = 1; i <= 5; i++) {
        if (ListInsert_Sq(L, i, i * 10) == OK) {
            cout << "插入元素 " << i * 10 << " 成功！\n";
        }
    }

    // 遍历测试
    cout << "当前列表内容:";
    ListTraverse_Sq(L, PrintElem);
    cout << "\n";

    // 获取元素测试
    ElemType e;
    if (GetElem_Sq(L, 3, e) == OK) {
        cout << "第3个元素是:" << e << "\n";
    }

    // 删除测试
    if (ListDelete_Sq(L, 2, e) == OK) {
        cout << "删除第2个元素:" << e << " 成功！\n";
    }

    cout << "删除后的列表:";
    ListTraverse_Sq(L, PrintElem);
    cout << "\n";

    // 销毁测试
    if (DestroyList_Sq(L) == OK) {
        cout << "列表销毁成功！\n";
    }
}

// 合并操作测试
void TestMergeList() {
    cout << "\n=== 测试合并操作 ===\n";
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);

    // 向La插入有序数据
    ListInsert_Sq(La, 1, 1);
    ListInsert_Sq(La, 2, 3);
    ListInsert_Sq(La, 3, 5);

    // 向Lb插入有序数据
    ListInsert_Sq(Lb, 1, 2);
    ListInsert_Sq(Lb, 2, 4);
    ListInsert_Sq(Lb, 3, 6);

    cout << "La内容:";
    ListTraverse_Sq(La, PrintElem);
    cout << "\n";

    cout << "Lb内容:";
    ListTraverse_Sq(Lb, PrintElem);
    cout << "\n";

    // 合并测试
    MergeList_Sq(La, Lb, Lc);
    cout << "合并后Lc的内容:";
    ListTraverse_Sq(Lc, PrintElem);
    cout << "\n";

    // 清理资源
    DestroyList_Sq(La);
    DestroyList_Sq(Lb);
    DestroyList_Sq(Lc);
}

// 边界条件测试
void TestBoundaryConditions() {
    cout << "\n=== 测试边界条件 ===\n";
    SqList L;
    InitList_Sq(L);
    ElemType e;

    // 空表测试
    cout << "空表测试：\n";
    if (ListEmpty_Sq(L)) {
        cout << "列表为空\n";
    }

    // 越界测试
    cout << "越界插入测试（位置0）：" <<
        (ListInsert_Sq(L, 0, 100) == ERROR ? "测试通过" : "测试失败") << "\n";

    // 插入后再删除，测试是否正确
    ListInsert_Sq(L, 1, 100);
    cout << "插入元素100后长度：" << ListLength_Sq(L) << "\n";
    ListDelete_Sq(L, 1, e);
    cout << "删除后长度：" << ListLength_Sq(L) << "\n";

    DestroyList_Sq(L);
}

//测试LinkList
void TestLinkList() {
    LinkList L;
    ElemType e;

    std::cout << "=== 测试创建链表 ===" << std::endl;
    CreateList_L(L, 5);  // 假设输入: 5 4 3 2 1
    std::cout << "链表创建完成，顺序输出链表元素：" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试插入操作 ===" << std::endl;
    ListInsert_L(L, 3, 99);  // 在第3个位置插入99
    std::cout << "在位置3插入99后的链表：" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试获取元素 ===" << std::endl;
    if (GetElem_L(L, 3, e) == OK) {
        std::cout << "第3个位置的元素是：" << e << std::endl;
    }

    std::cout << "\n=== 测试删除操作 ===" << std::endl;
    if (ListDelete_L(L, 3, e) == OK) {
        std::cout << "删除第3个位置的元素：" << e << std::endl;
        std::cout << "删除后的链表：" << std::endl;
        ListTraverse_L(L, PrintElem);
        std::cout << std::endl;
    }

    std::cout << "\n=== 测试合并操作 ===" << std::endl;
    LinkList L1, L2, L3;
    std::cout << "创建第一个有序链表：" << std::endl;
    CreateList_L(L1, 3);  // 假设输入: 5 3 1
    std::cout << "创建第二个有序链表：" << std::endl;
    CreateList_L(L2, 3);  // 假设输入: 6 4 2

    std::cout << "第一个链表：" << std::endl;
    ListTraverse_L(L1, PrintElem);
    std::cout << "\n第二个链表：" << std::endl;
    ListTraverse_L(L2, PrintElem);

    MergeList_L(L1, L2, L3);
    std::cout << "\n合并后的链表：" << std::endl;
    ListTraverse_L(L3, PrintElem);
    std::cout << std::endl;
}



// 改进打印函数以更清晰地显示结果
void PrintList(SLinkList& space, int S) {
    if (!ValidateSLinkList(space, S)) {
        std::cout << "链表结构异常！" << std::endl;
        return;
    }

    int i = space[S].cur;
    if (i == 0) {
        std::cout << "空集" << std::endl;
        return;
    }

    std::cout << "差集(A-B)∪(B-A)的结果为：";
    while (i != 0) {
        std::cout << space[i].data << " ";
        i = space[i].cur;
    }
    std::cout << std::endl;
}


// 改进的测试函数
void TestSLinkList() {
    SLinkList space;
    int S;

    std::cout << "请输入两个集合的元素个数(m n): ";
    difference(space, S);

    if (ValidateSLinkList(space, S)) {
        PrintList(space, S);
    }
    else {
        std::cout << "链表创建失败！" << std::endl;
    }
}
int main() {
    TestSLinkList();
    return 0;
}
