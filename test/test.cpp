#pragma once

#include"LinkList.h"
#include"SqList.h"
//#include"MyFun.h"
#include<iostream>
using namespace std;
// 测试SqList
void TestSqList() {
    cout << "=== 测试顺序表和链表操作 ===\n";
    
    // 测试顺序表
    cout << "\n--- 测试顺序表 ---\n";
    SqList sqList;
    ElemType e;

    // 初始化测试
    if (InitList_Sq(sqList) == OK) {
        cout << "顺序表初始化成功！\n";
    }

    // 插入测试
    for (int i = 1; i <= 5; i++) {
        if (ListInsert_Sq(sqList, i, i * 10) == OK) {
            cout << "插入元素 " << i * 10 << " 成功！\n";
        }
    }

    // 遍历测试
    cout << "当前顺序表内容:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // 获取元素测试
    if (GetElem_Sq(sqList, 3, e) == OK) {
        cout << "顺序表第3个元素是:" << e << "\n";
    }

    // 删除测试
    if (ListDelete_Sq(sqList, 2, e) == OK) {
        cout << "删除顺序表第2个元素:" << e << " 成功！\n";
    }

    cout << "删除后的顺序表:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // 顺序表合并测试
    SqList sqLa, sqLb, sqLc;
    InitList_Sq(sqLa);
    InitList_Sq(sqLb);
    InitList_Sq(sqLc);

    // 向sqLa插入有序数据
    ListInsert_Sq(sqLa, 1, 1);
    ListInsert_Sq(sqLa, 2, 3);
    ListInsert_Sq(sqLa, 3, 5);

    // 向sqLb插入有序数据
    ListInsert_Sq(sqLb, 1, 2);
    ListInsert_Sq(sqLb, 2, 4);
    ListInsert_Sq(sqLb, 3, 6);

    cout << "sqLa内容:";
    ListTraverse_Sq(sqLa, PrintElem);
    cout << "\n";

    cout << "sqLb内容:";
    ListTraverse_Sq(sqLb, PrintElem);
    cout << "\n";

    // 合并测试
    MergeList_Sq(sqLa, sqLb, sqLc);
    cout << "合并后sqLc的内容:";
    ListTraverse_Sq(sqLc, PrintElem);
    cout << "\n";

    // 顺序表边界条件测试
    cout << "\n--- 顺序表边界条件测试 ---\n";
    SqList sqListBoundary;
    InitList_Sq(sqListBoundary);

    // 空表测试
    if (ListEmpty_Sq(sqListBoundary)) {
        cout << "顺序表为空\n";
    }

    // 越界测试
    cout << "越界插入测试（位置0）：" <<
        (ListInsert_Sq(sqListBoundary, 0, 100) == ERROR ? "测试通过" : "测试失败") << "\n";

    // 插入后再删除，测试是否正确
    ListInsert_Sq(sqListBoundary, 1, 100);
    cout << "插入元素100后长度：" << ListLength_Sq(sqListBoundary) << "\n";
    ListDelete_Sq(sqListBoundary, 1, e);
    cout << "删除后长度：" << ListLength_Sq(sqListBoundary) << "\n";

    // 销毁顺序表
    DestroyList_Sq(sqList);
    DestroyList_Sq(sqLa);
    DestroyList_Sq(sqLb);
    DestroyList_Sq(sqLc);
    DestroyList_Sq(sqListBoundary);

    // 测试链表
    cout << "\n--- 测试链表 ---\n";
    LinkList linkList;

    cout << "=== 测试创建链表 ===\n";
    CreateList_L(linkList, 5);  // 假设输入: 5 4 3 2 1
    cout << "链表创建完成，顺序输出链表元素:\n";
    ListTraverse_L(linkList, PrintElem);
    cout << "\n";

    cout << "\n=== 测试链表插入操作 ===\n";
    ListInsert_L(linkList, 3, 99);  // 在第3个位置插入99
    cout << "在位置3插入99后的链表:\n";
    ListTraverse_L(linkList, PrintElem);
    cout << "\n";

    cout << "\n=== 测试链表获取元素 ===\n";
    if (GetElem_L(linkList, 3, e) == OK) {
        cout << "链表第3个位置的元素是:" << e << "\n";
    }

    cout << "\n=== 测试链表删除操作 ===\n";
    if (ListDelete_L(linkList, 3, e) == OK) {
        cout << "删除链表第3个位置的元素:" << e << "\n";
        cout << "删除后的链表:\n";
        ListTraverse_L(linkList, PrintElem);
        cout << "\n";
    }

    cout << "\n=== 测试链表合并操作 ===\n";
    LinkList linkList1, linkList2, linkList3;
    cout << "创建第一个有序链表:\n";
    CreateList_L(linkList1, 3);  // 假设输入: 5 3 1
    cout << "创建第二个有序链表:\n";
    CreateList_L(linkList2, 3);  // 假设输入: 6 4 2

    cout << "第一个链表:\n";
    ListTraverse_L(linkList1, PrintElem);
    cout << "\n第二个链表:\n";
    ListTraverse_L(linkList2, PrintElem);

    MergeList_L(linkList1, linkList2, linkList3);
    cout << "\n合并后的链表:\n";
    ListTraverse_L(linkList3, PrintElem);
    cout << "\n";
}
//测试LinkList
void TestLinkList() {
    LinkList L;
    ElemType e;

    std::cout << "=== 测试创建链表 ===" << std::endl;
    CreateList_L(L, 5);  // 假设输入: 5 4 3 2 1
    std::cout << "链表创建完成，顺序输出链表元素:" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试插入操作 ===" << std::endl;
    ListInsert_L(L, 3, 99);  // 在第3个位置插入99
    std::cout << "在位置3插入99后的链表:"<< std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试获取元素 ===" << std::endl;
    if (GetElem_L(L, 3, e) == OK) {
        std::cout << "第3个位置的元素是:" << e << std::endl;
    }

    std::cout << "\n=== 测试删除操作 ===" << std::endl;
    if (ListDelete_L(L, 3, e) == OK) {
        std::cout << "删除第3个位置的元素:" << e << std::endl;
        std::cout << "删除后的链表:" << std::endl;
        ListTraverse_L(L, PrintElem);
        std::cout << std::endl;
    }

    std::cout << "\n=== 测试合并操作 ===" << std::endl;
    LinkList L1, L2, L3;
    std::cout << "创建第一个有序链表:" << std::endl;
    CreateList_L(L1, 3);  // 假设输入: 5 3 1
    std::cout << "创建第二个有序链表:" << std::endl;
    CreateList_L(L2, 3);  // 假设输入: 6 4 2

    std::cout << "第一个链表:" << std::endl;
    ListTraverse_L(L1, PrintElem);
    std::cout << "\n第二个链表:" << std::endl;
    ListTraverse_L(L2, PrintElem);

    MergeList_L(L1, L2, L3);
    std::cout << "\n合并后的链表:" << std::endl;
    ListTraverse_L(L3, PrintElem);
    std::cout << std::endl;
}

void menu() {

}
