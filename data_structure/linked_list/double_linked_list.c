#include <stdio.h>

// 双链表
typedef struct DNode {
    ElemType data;              // 数据域
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;

// 插入 (在双链表中p所指的结点之后插入结点*s)
void demo() {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

// 插入（p之前插入结点*s）
void demo() {
    p->prior->next = s;
    s->next = p;
    s->prior = p->prior;
    p->prior = s;
}

// 删除 （删除双链表中结点*p的后继结点*q）
void demo() {
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

// 静态链表
#define MaxSize 50
typedef struct {
    ElemType data;
    int next;       // 下一个元素的数组下标
}
// next == -1作为其结束的标志。


// 1.递归删除，不带头结点的的单链表L中所有值为x的结点
void del_x_3(LinkList &L, ElemType x) {
    LNode *p;           // p指向待删除结点
    if (L == NULL) {    // 递归出口
        return;
    }
    if (L->data == x) { // 若L所指结点的值为x
        p = L;          // 删除*L，并让L指向下一结点
        L = L->next;
        free(p);
        del_x_3(L, x);
    }
    else {              // 若L所指及诶单的值不为x
        del_x_3(L->next, x);  
    }
}