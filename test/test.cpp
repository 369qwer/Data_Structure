#pragma once

#include"LinkList.h"
#include"SqList.h"
#include"SLinkList.h"
#include<iostream>
#include<stdexcept>
using namespace std;

// 测试SqList
void TestSqList() {
    cout << "=== 顺序表测试开始 ===\n";
    
    // 初始化顺序表
    cout << "\n--- 初始化顺序表 ---\n";
    SqList sqList;
    ElemType e;

    // 初始化顺序表
    if (InitList_Sq(sqList) == OK) {
        cout << "顺序表初始化成功\n";
    }

    // 插入元素
    for (int i = 1; i <= 5; i++) {
        if (ListInsert_Sq(sqList, i, i * 10) == OK) {
            cout << "成功插入元素 " << i * 10 << " 到顺序表\n";
        }
    }

    // 遍历顺序表
    cout << "顺序表当前内容:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // 获取指定位置元素
    if (GetElem_Sq(sqList, 3, e) == OK) {
        cout << "顺序表中第3个元素是:" << e << "\n";
    }

    // 删除指定位置元素
    if (ListDelete_Sq(sqList, 2, e) == OK) {
        cout << "从顺序表中删除第2个元素:" << e << " 成功\n";
    }

    cout << "删除后的顺序表:";
    ListTraverse_Sq(sqList, PrintElem);
    cout << "\n";

    // 顺序表的合并操作
    SqList sqLa, sqLb, sqLc;
    InitList_Sq(sqLa);
    InitList_Sq(sqLb);
    InitList_Sq(sqLc);

    // 为sqLa插入几个元素
    ListInsert_Sq(sqLa, 1, 1);
    ListInsert_Sq(sqLa, 2, 3);
    ListInsert_Sq(sqLa, 3, 5);

    // 为sqLb插入几个元素
    ListInsert_Sq(sqLb, 1, 2);
    ListInsert_Sq(sqLb, 2, 4);
    ListInsert_Sq(sqLb, 3, 6);

    cout << "sqLa内容:";
    ListTraverse_Sq(sqLa, PrintElem);
    cout << "\n";

    cout << "sqLb内容:";
    ListTraverse_Sq(sqLb, PrintElem);
    cout << "\n";

    // 合并操作
    MergeList_Sq(sqLa, sqLb, sqLc);
    cout << "合并后sqLc的内容:";
    ListTraverse_Sq(sqLc, PrintElem);
    cout << "\n";

    // 顺序表的边界测试案例
    cout << "\n--- 顺序表边界测试案例 ---\n";
    SqList sqListBoundary;
    InitList_Sq(sqListBoundary);

    // 空表测试
    if (ListEmpty_Sq(sqListBoundary)) {
        cout << "顺序表为空\n";
    }

    // 非法位置插入
    cout << "插入到位置0的元素（应该失败）:" <<
        (ListInsert_Sq(sqListBoundary, 0, 100) == ERROR ? "插入失败" : "插入成功") << "\n";

    // 插入和删除元素，检查长度变化
    ListInsert_Sq(sqListBoundary, 1, 100);
    cout << "插入元素后长度:" << ListLength_Sq(sqListBoundary) << "\n";
    ListDelete_Sq(sqListBoundary, 1, e);
    cout << "删除元素后长度:" << ListLength_Sq(sqListBoundary) << "\n";

    // 销毁顺序表
    DestroyList_Sq(sqList);
    DestroyList_Sq(sqLa);
    DestroyList_Sq(sqLb);
    DestroyList_Sq(sqLc);
    DestroyList_Sq(sqListBoundary);

}

// 测试LinkList
void TestLinkList() {
    LinkList L;
    ElemType e;

    std::cout << "=== 链表测试开始 ===" << std::endl;
    CreateList_L(L, 5);  // 创建一个包含5个元素的链表: 5 4 3 2 1
    std::cout << "创建一个包含5个元素的链表，内容如下:" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试插入操作 ===" << std::endl;
    ListInsert_L(L, 3, 99);  // 在第3个位置插入元素99
    std::cout << "在第3个位置插入元素99后，链表内容:" << std::endl;
    ListTraverse_L(L, PrintElem);
    std::cout << std::endl;

    std::cout << "\n=== 测试获取指定位置元素 ===" << std::endl;
    if (GetElem_L(L, 3, e) == OK) {
        std::cout << "第3个位置的元素是:" << e << std::endl;
    }

    std::cout << "\n=== 测试删除指定位置元素 ===" << std::endl;
    if (ListDelete_L(L, 3, e) == OK) {
        std::cout << "删除的第3个位置的元素是:" << e << std::endl;
        std::cout << "删除后的链表内容:" << std::endl;
        ListTraverse_L(L, PrintElem);
        std::cout << std::endl;
    }

    std::cout << "\n=== 测试链表的合并操作 ===" << std::endl;
    LinkList L1, L2, L3;
    std::cout << "创建两个有序链表进行合并测试:" << std::endl;
    CreateList_L(L1, 3);  // 创建一个包含3个元素的链表: 5 3 1
    std::cout << "创建第二个包含3个元素的链表:" << std::endl;
    CreateList_L(L2, 3);  // 创建一个包含3个元素的链表: 6 4 2

    std::cout << "第一个链表的内容:" << std::endl;
    ListTraverse_L(L1, PrintElem);
    std::cout << "\n第二个链表的内容:" << std::endl;
    ListTraverse_L(L2, PrintElem);

    MergeList_L(L1, L2, L3);
    std::cout << "\n合并后的链表内容:" << std::endl;
    ListTraverse_L(L3, PrintElem);
    std::cout << std::endl;
}

// 打印静态链表中的所有元素
void PrintList(SLinkList& space, int S) {
    int curr = space[S].cur;
    std::cout << "链表内容: ";
    while (curr != 0) {
        std::cout << space[curr].data << " ";
        curr = space[curr].cur;
    }
    std::cout << std::endl;
}

// 测试SLinkList
void TestSLinkList() {
    SLinkList space;
    int S;  // 头指针

    std::cout << "测试1:空集的对称差" << std::endl;
    std::cout << "输入:0 0" << std::endl;
    difference(space, S);
    PrintList(space, S);

    std::cout << "\n测试2:A={1,2,3}, B={2,4}" << std::endl;
    std::cout << "输入:3 2" << std::endl;
    std::cout << "1 2 3" << std::endl;
    std::cout << "2 4" << std::endl;
    difference(space, S);
    PrintList(space, S);

    std::cout << "\n测试3:重复元素测试 A={1,1,2}, B={2,2,3}" << std::endl;
    std::cout << "输入:3 3" << std::endl;
    std::cout << "1 1 2" << std::endl;
    std::cout << "2 2 3" << std::endl;
    difference(space, S);
    PrintList(space, S);

    // 验证链表结构
    if (ValidateSLinkList(space, S)) {
        std::cout << "链表结构完整性检测通过" << std::endl;
    } else {
        std::cout << "警告:链表可能存在循环或其他问题!" << std::endl;
    }
}

// 测试目录
void TestDir() {
    system("chcp 65001");//将控制台编码设置为UTF-8
    int choice;
    
    try {
        cout << "======================\n"
             << "    数据结构测试菜单    \n"
             << "======================\n"
             << "1. 测试SqList\n"
             << "2. 测试LinkList\n"
             << "3. 测试SLinkList\n"
             << "0. 退出menu\n"
             << "----------------------\n"
             << "请输入选择 (0-3): ";
             
        if (!(cin >> choice)) {
            // 处理输入非数字的情况
            cin.clear();  // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 清空输入缓冲区
            throw invalid_argument("输入必须是number");
        }
        
        switch (choice) {
        case 1:
            TestSqList();
            break;
        case 2:
            TestLinkList();
            break;
        case 3:
            TestSLinkList();
            break;
        case 0:
            cout << "退出程序\n";
            break;
        default:
            throw invalid_argument("选择必须在0-3之间!");
        }
    }
    catch (const invalid_argument& e) {
        cout << "错误: " << e.what() << "\n";
    }
    catch (const exception& e) {
        cout << "发生未知错误: " << e.what() << "\n";
    }
    catch (...) {
        cout << "发生未知异常!\n";
    }
}