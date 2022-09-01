#include <stdio.h>

// 顺序栈
#define MaxSize 50  // 定义栈中元素的最大个数
typedef struct {
    ElemType data[MaxSize];   // 存放栈中元素
    int top;                  // 栈顶指针
} SqStack; 
/*
栈顶指针：S.top，初始化设置 S.top=-1；栈顶元素：S.data[S.top]
进栈操作：栈不满时，栈顶指针先加1，再送值到栈顶元素。
出栈操作：栈非空时，先取栈顶元素值，再将栈顶指针减1。
栈空条件：S.top==-1；
栈满条件：S.top==MaxSize-1；
栈长：S.top+1
*/

// 初始化
void InitStack(SqStack &S) {
    S.top = -1;     // 初始化栈顶指针
}

// 判栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1) 
        return true;
    else 
        return false;
}

// 进栈
bool Push(SqStack &S, ElemType x) {
    is (S.top == MaxSize-1) 
        return false;
    s.data[++S.top] = x;    // 指针先加1，再入栈
    return true;
}

// 出栈
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) 
        return false;
    x = S.data[S.top--];    // 先出栈，指针再减1
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1) 
        return false;
    x = S.data[S.top];
    return true;
}

// 链栈
typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} *LiStack;