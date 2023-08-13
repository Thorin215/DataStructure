// 习题1.9 有序数组的插入
// 分数 20
// 作者 陈越
// 单位 浙江大学
// 本题要求将任一给定元素插入从大到小排好序的数组中合适的位置，以保持结果依然有序。

// 函数接口定义：
// bool Insert( List L, ElementType X );
// 其中List结构定义如下：

// typedef int Position;
// typedef struct LNode *List;
// struct LNode {
//     ElementType Data[MAXSIZE];
//     Position Last; /* 保存线性表中最后一个元素的位置 */
// };
// L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递减有序的。函数Insert要将X插入Data[]中合适的位置，以保持结果依然有序（注意：元素从下标0开始存储）。但如果X已经在Data[]中了，就不要插入，返回失败的标记false；如果插入成功，则返回true。另外，因为Data[]中最多只能存MAXSIZE个元素，所以如果插入新元素之前已经满了，也不要插入，而是返回失败的标记false。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>

// #define MAXSIZE 10
// typedef enum {false, true} bool;
// typedef int ElementType;

// typedef int Position;
// typedef struct LNode *List;
// struct LNode {
//     ElementType Data[MAXSIZE];
//     Position Last; /* 保存线性表中最后一个元素的位置 */
// };

// List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
// void PrintList( List L ); /* 裁判实现，细节不表 */
// bool Insert( List L, ElementType X );

// int main()
// {
//     List L;
//     ElementType X;

//     L = ReadInput();
//     scanf("%d", &X);
//     if ( Insert( L, X ) == false )
//         printf("Insertion failed.\n");
//     PrintList( L );

//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例1：
// 5
// 35 12 8 7 3
// 10
// 输出样例1：
// 35 12 10 8 7 3
// Last = 5
// 输入样例2：
// 6
// 35 12 10 8 7 3
// 8
// 输出样例2：
// Insertion failed.
// 35 12 10 8 7 3
// Last = 5

bool Insert( List L, ElementType X ){
    if(L->Last == MAXSIZE-1){
        return false;
    }else if(L->Data[0] < X){
        for(int i = L->Last;i > -1;i--){
        L->Data[i+1] = L->Data[i];
        }
        L->Data[0] = X;
        L->Last += 1;
        return true;
    }
    
    int left = 0;
    int right = L->Last;
    int mid;
    while(left <= right){
        mid = (left+right)/2;
        if (L->Data[mid] > X) left = mid+1;
        else if (L->Data[mid] < X) right = mid-1;
        else return false;
    }
    for(int i = L->Last;i > mid;i--){
        L->Data[i+1] = L->Data[i];
    }
    L->Data[mid+1] = X;
    L->Last += 1;
    return true;
}