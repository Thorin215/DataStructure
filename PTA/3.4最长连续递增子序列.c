// 习题3.4 最长连续递增子序列
// 分数 20
// 作者 DS课程组
// 单位 浙江大学
// 给定一个顺序存储的线性表，请设计一个算法查找该线性表中最长的连续递增子序列。例如，(1,9,2,5,7,3,4,6,8,0)中最长的递增子序列为(3,4,6,8)。

// 输入格式:
// 输入第1行给出正整数n（≤10 
// 5
//  ）；第2行给出n个整数，其间以空格分隔。

// 输出格式:
// 在一行中输出第一次出现的最长连续递增子序列，数字之间用空格分隔，序列结尾不能有多余空格。

// 输入样例：
// 15
// 1 9 2 5 7 3 4 6 8 0 11 15 17 17 10
// 输出样例：
// 3 4 6 8

#include<stdio.h>
int lenght = 0;
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int left=0 , right=0;
    int temp=0;
    while(right<n){
        if(num[right+1]>num[right]) temp += 1;
        else{
            if(temp>lenght){
                lenght = temp;
                left = right - temp;
            }
            temp = 0;
        }
        right += 1;
    }
    for(int i=0;i<lenght;i++){
        printf("%d ",num[i+left]);
    }
    printf("%d\n",num[left+lenght]);
}
