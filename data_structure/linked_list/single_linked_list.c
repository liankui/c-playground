#include <stdio.h>

typedef int ElemType;

// 单链表
typedef struct LNode {
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L) { // 逆向建立单链表
    LNode *s, int x;
    L = (LinkList)malloc(sizeof(LNode));  // 创建头结点
    L->next = NULL;
    scanf("%d", &x);    // 输入结点的值
    while (x != 999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;        // 将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}
// 头插法建单链表，读入数据的顺序和生成的链表中的元素的顺序是相反的。
// 每个结点插入的时间复杂度为O(1)，总时间复杂度为O(n)。

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L) { // 正向建立单链表
    int x;
    L = (LinkList)malloc(sizeof(LNode));  // 创建头结点
    LNode *s, *r = L;   // r为尾指针
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;          // r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;   // 尾结点指针置空
    return L;
}
// 每个结点插入的时间复杂度为O(1)，总时间复杂度为O(n)。

// 按序号查找结点值
LNode *GetElem(LinkList L, int i) {
    int j = 1;  // 计数
    LNode *p = L->next;   // 第一个结点指针赋给p
    if (i == 0) 
        return L;       // 若i为0，则返回头结点
    if (i < 0) 
        return NULL;    // 若i无效，则返回NULL    
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;       // 返回第i个结点，若i大于表长，则返回NULL
}
// 按序号查找操作的时间复杂度O(n)

// 按值查找表结点
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) { // 从第1个结点开始查找data域为e的结点
        p = p->next;
    }
    return p;       // 找到后返回该结点指针，否则返回NULL
}
// 按值查找操作的时间复杂度为O(n)

// 插入结点（将值为x的新结点插入到单链表的第i个位置上）
void insert(LinkList L, int i, ElemType x) {
    LNode *p = GetElem(L, i-1); // 找到待插入位置的前驱结点，即第i-1个结点，在其后插入新结点
    s = (LNode*)malloc(sizeof(LNode)); // 创建新结点
    s->data = x;
    s->next = p->next;  // 令新结点*s的指针域指向*p的后继结点
    p->next = s;      // 令结点*p的指针域指向新插入的结点*s
}
// 遍历i-1个元素时间复杂度为O(n)

// 前插操作（将*s结点插入到*p之前）
// 思路：1.在第i个位置前插可以转化为在第i-1位置上后插
// 2.先将*s插入到*p，再将*p和*s进行交换
void demo2() {
    s->next = p->next; 
    p->next = s;
    temp = p->data;
    p->data = s->data;
    s->data = temp;
}
// 插入的时间复杂度为O(1)

// 删除结点（将单链表上第i个结点删除），p -> q
void del_demo() {
    p = GetElem(L, i-1); // 查找删除位置的前驱结点
    q = p->next;         // 令q指向被删除结点
    p->next = q->next;   // 将*q结点从链中“断开”
    free(q);             // 释放结点的存储空间
}
// 主要时间用于查找操作，时间复杂度为O(n)

// 删除结点*p
// 思路：删除结点*p转化为删除结点*p的后继结点，但要先将后续结点的值赋值给p
void demo() {
    q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
}
// 删除结点*p的时间复杂度为O(1)

// 求表长，需设置一个计数器，遍历每个结点，时间复杂度为O(n)

// ====作业
// 1.删除不带头结点的单链表L中所有值为x的结点。要求：使用递归
void Del_x_3(LinkList &L, ElemType x) {
    LNode *p;           // p指向待删除结点
    if (L == Null ) {   // 递归出口
        return;
    }
    if (L->data == x) { // 若L所指结点的值为x
        p = L;
        L = L->next;
        free(p);
        Del_x_3(L, x);
    } else {
        Del_x_3(L->next, x);
    }
}
// 时间复杂度O(n)

// 2.删除带头结点的单链表L中所有值为x的结点。
// 解法1：用p从头到尾扫描单链表，pre指向*p结点的前驱
// 若p所指向的结点的值为x，则删除，并让p移向下一个结点，否则让pre、p指针同步后移一个结点。
void Del_x_1(LinkList &L, ElemType x) {
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;          // q指向该结点
            p = p->next;
            pre->next = p;  // 删除*q结点
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}
// 采用尾插法建立单链表。用p指针扫描L的所有结点，当其值不为x时，将其链接到L之后，否则将其释放。
void Del_x_2(LinkList &L, ElemType x) {
     LNode *p = L->next, *r = L, *q;    // r指向尾结点，其初始值为头结点
     while (p != NULL) {
        if (p->data != x) {     // *p结点值不为x时将其链接到L尾部
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
     }
     r->next = NULL;        // 插入结束后，置尾结点指针为NULL
}


