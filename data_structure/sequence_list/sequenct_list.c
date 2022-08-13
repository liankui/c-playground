#include <stdio.h>

typedef int ElemType;
typedef int bool;

// 静态分配
#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

// 动态分配
#define InitSize 100
typedef struct
{
    ElemType *data;
    int maxSize;
    int length;
} SeqList;

// 伪代码
// 插入，在顺序表L的第i个（1<=i<=L.length+1）位置插入新元素e
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length--;
    return true;
}

// 删除，删除顺序表L的第i个（1<=i<=L.length）位置的元素，用引用类型e返回
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

// 按值查找，在顺序表L中查找第一个元素值等于e的元素
int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i;
    return 0;
}

// --------作业
// 1.删除最小值的元素，返回被删元素的值
bool del_min(SqList &L, ElemType &value) {
    if (L.length == 0)  // 表空，终止操作返回
        return false;
    int pos = 0;
    value = L.data[0];
    for (int i = 1; i < L.length; i++)
        if (L.data[i] < value) {
            value = L.data[i]; 
            pos = i;
        }
    L.data[i] = L.data[L.length-1]; // 空出的位置由最后一个元素填补
    L.length--;
    return true;
}

// 2.将书序表L逆置，要求空间复杂度O(1)
void reverse(SqList &L) {
    ElemType temp;
    for (i = 0; i < L.length/2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[length-1-i];
        L.data[length-1-i] = temp;
    }
}

// 3.长度为n的顺序表L，删除所有值为x的元素。要求时间复杂度O(n)，空间复杂度O(1)
// 用k记录顺序表L不等于x元素的个数，扫描时将不等于x的元素移动到下标k的位置，并更新k值。扫描结束后修改L的长度。
void del_x_1(SqList &L, ElemType x) {
    int k = 0;
    for (i = 0; i < L.length; i++)
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    L.length = k;        
}

// 用k记录顺序表L等于x元素的个数，扫描将不等于x的元素前移k个位置。扫描结束后修改L的长度。
void del_x_2(SqList &L, ElemType x) {
    int k = 0;
    int i = 0;
    while(i<L.length) {
        if (L.data[i]==k)
            k++;
        else 
            L.data[i-k] = L.data[i]; // 当前元素前移k个位置
        i++;
    }
    L.length = L.length - k;
}

// 4.删除有序顺序表L中元素的值介于s与t(s<t)之间的所有元素
bool del_order_s_t(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t)
        reutrn false;
    int i, j;
    for (i = 0; i < L.length && L.data[i] < s; i++);  // i为第一个大于等于s的元素
    if (i > L.length)
        return false;
    for (j = 0; j < L.length && L.data[j] >= t; j++); // j为第一个小于t的元素
    for (; j<L.length; i++, j++)
        L.data[i] = L.data[j];
    L.length = k-(j-i+1);
    return true;
}

// 5.删除顺序表L中元素的值介于s与t(s<t)之间的所有元素
bool del_s_t(SqList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t)
        reutrn false;

    int i, k = 0;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] < s || L.data[i] > t) {
            L.data[k] = L.data[i]
            k++
        }   
    }    
    L.length = k;
    return true;

    // 方法二：前移k
    int i, k = 0;
    for (i = 0; i < L.length; i++) {  
        if (L.data[i] >= s && L.data[i] <= t) // 在s-t范围内，统计至k中
            k++;
        else 
            L.data[i-k] = L.data[i]; // 当前元素前移k个位置
    }
    L.length -= k;
    return true;
}

// 6.有序顺序表中删除所有值重复的元素
bool del_order_same(SqList &L) {
    if (L.length == 0)
        return false;
    int i; // 将L.data[i]看作一个非重复的有序表，把非重复的数据赋值到里面
    for (int j = 1; j < L.length; j++)
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    L.length = i + 1;
    return true;
}