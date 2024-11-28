
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
    cout << "=== 测试基础操作 ===\n";
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

int main() {
    TestBasicOperations();
    TestMergeList();
    TestBoundaryConditions();
    return 0;
}