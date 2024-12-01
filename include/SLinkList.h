//线性表的静态单链表存储结构
#define MAXSIZE 1000 //链表的最大长度
#include"define.h"
#include<iostream>
typedef struct {
	ElemType data;
	int cur;
}Component,SLinkList[MAXSIZE];

//在静态单链表L中查找第一个值为e的元素
int LocateElem_SL(SLinkList L, ElemType e) {
//若找到，则返回在L中的位序，否则返回0
    int i = L[0].cur;
    while (i&&L[i].data != e)
    {
        i = L[i].cur;
    }
    return i;   
}

//将一维数组space中各分量链成一个备用链表，space[0].cur为头指针
void InitSpace_SL(SLinkList& space) {
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
}

//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SL(SLinkList& space) {
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}

//将下标为k的空闲结点回收到备用链表
void Free_SL(SLinkList& space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}



//依次输入集合A和B的元素值，在一维数组space中建立表示集合（A-B）U(B-A)
//的静态链表，S为其头指针。假设备用空间链表space的表头为0号下标
void difference(SLinkList& space, int& S) {
    // 初始化备用空间
    InitSpace_SL(space);

    // 创建头结点
    S = Malloc_SL(space);
    if (S == 0) {
        std::cout << "内存分配失败!" << std::endl;
        return;
    }
    space[S].cur = 0;  // 初始化头结点的游标为0
    int r = S;  // r指向当前最后一个结点

    // 输入集合大小
    int m, n;
    std::cin >> m >> n;

    // 验证输入的有效性
    if (m < 0 || n < 0 || m >= MAXSIZE || n >= MAXSIZE) {
        std::cout << "输入的集合大小无效！" << std::endl;
        return;
    }

    // 存储集合A的元素（去重）
    for (int j = 1; j <= m; j++) {
        ElemType elem;
        std::cin >> elem;

        // 检查是否已存在该元素
        bool isDuplicate = false;
        int check = space[S].cur;
        while (check != 0) {
            if (space[check].data == elem) {
                isDuplicate = true;
                break;
            }
            check = space[check].cur;
        }

        // 如果不是重复元素，则添加到链表
        if (!isDuplicate) {
            int i = Malloc_SL(space);
            if (i == 0) {
                std::cout << "内存分配失败!" << std::endl;
                return;
            }
            space[i].data = elem;
            space[i].cur = 0;
            space[r].cur = i;
            r = i;
        }
    }

    // 处理集合B的元素
    for (int j = 1; j <= n; j++) {
        ElemType b;
        std::cin >> b;

        // 查找b是否在当前链表中
        int p = S;
        int k = space[S].cur;
        bool found = false;

        while (k != 0) {
            if (space[k].data == b) {
                // 如果找到了，删除该元素
                space[p].cur = space[k].cur;
                if (r == k) {
                    r = p;
                }
                Free_SL(space, k);
                found = true;
                break;
            }
            p = k;
            k = space[k].cur;
        }

        // 如果b不在链表中，添加到链表末尾
        if (!found) {
            int i = Malloc_SL(space);
            if (i == 0) {
                std::cout << "内存分配失败!" << std::endl;
                return;
            }
            space[i].data = b;
            space[i].cur = 0;
            space[r].cur = i;
            r = i;
        }
    }
}


// 添加一个验证函数来检查静态链表的完整性
bool ValidateSLinkList(SLinkList& space, int S) {
    int count = 0;
    int curr = space[S].cur;

    // 检查是否存在循环
    while (curr != 0 && count < MAXSIZE) {
        count++;
        curr = space[curr].cur;
    }

    return count < MAXSIZE; // 如果count >= MAXSIZE，说明可能存在循环
}

