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
    int k = 0, i;
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

// 重点 7.将2个有序顺序表合并为一个新的有序顺序表
bool merge_2_order(SqList A, SqList B, SqList &C) {
    if (A.length + B.length > MaxSize) 
        return false;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length) { // 循环，两两比较，小的存入结果表
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else 
            C.data[k++] = B.data[j++];    
    }
    // 还剩下一个没有比较完的顺序表
    while (i < A.length) 
        c.data[k++] = A.data[i];
    while (j < B.length) 
        c.data[k++] = B.data[j];
    c.length = k;
    return true;
}

// 8.一位数组A[m+n]依次存放了两个线性表{a1,a2,...,am} {b1,b2,...bn}
// 将数组中两个顺序表的位置互换，即将{b1,b2,...bn}放在{a1,a2,...,am}前。
// 思路：先将数组A全部逆置，再对n和m分别逆置。
typedef int DataType;
// 逆转（left,left+1,...,right-1,right）为（right, right-1,...,left+1,left）
void reverse(DataType A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize)
        return false;
    int middle = (left + right)/2;
    for (int i = 0; i <= middle - left; i++) {
        DataType temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}

// 数组A[m+n]，0到m-1存放顺序表（a1,a2,...,am）,从m到m+n-1存放顺序表（b1,b2,...,bn），将这两个表的位置互换。
void Exchange(DataType A[], int m, int n, int arraySize) {
    reverse(A, 0, m+n-1, arraySize);
    reverse(A, 0, n-1, arraySize);
    reverse(B, n, m+n-1, arraySize);
}

// 9.长度为n的有序顺序表，查找值为x的元素。如有，将其与后继元素相交换；如没有将其插入表中并保持有序。要求：最少的时间
// 思路，使用折半查法
void search_exchange_or_insert(ElemType A[], ElemType x) {
    int low = 0, high = n-1, low;
    while (low <= high) {
        mid = (low + high)/2;
        if (A[mid] == x) break;  // 找到x，退出while循环
        else if (A[mid] < x) low = mid+1; // 到终点mid的右半部去查
        else high = mid - 1;              // 到终点mid的左半部去查
    }
    if (A[mid] == x && mid != n - 1) {     // 若最后一个元素与x相等，则不存在与其后继交换的操作
        tmp = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = t;
    }
    if (low > high) {   // 查找失败，插入数据元素x
        for (i = n - 1; i > high; i--) {    // 后移元素
            A[i+1] = A[i];
        }   
        A[i+1] = x;     // 插入x
    }
}

// 10.将n(n>1)个整数存放在一维数组R中。将R的序列循环左移p(0<p<n)个位置，
// 即将R中数据由(X0,X1,...,Xn-1)变为(Xp,Xp+1,...,Xn-1,X0,...,Xp-1)。要求时间和空间尽可能高效。
// 思路：同第8题，先逆转0至p-1，再逆转p-1至n-1，最后逆置全部元素。
// 对于abcdefg，向左循环移动3个位置（p=3），最终为defgabc
// reverse(0, p-1),cbadefg
// reverse(p, n-1),cbagfed
// reverse(0, n-1),defgabc
void reverse(int R[], int from, int to) {
    int i, temp;
    for (i = 0; i < (to-from+1)/2; i++) {
        temp = R[from+1];
        R[from+1] = R[to-1];
        R[to-1] = temp;
    }
}

void converse(int R[], int n, int p) {
    reverse(R, 0, p-1);
    reverse(R, p, n-1);
    reverse(R, 0, n-1);
}