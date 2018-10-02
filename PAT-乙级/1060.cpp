#include <stdio.h>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
/*
题意理解的有些问题 题目中说到E天
不是刚好E天 超过也是可以的
*/
int ans[100010];
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int a[],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    int mid = a[(begin + end) / 2];

    while(i <= j)
    {
        while(a[i] > mid)
        {
            i ++;
        }
        while(a[j] < mid)
        {
            j --;
        }

        if(i <= j)
        {
            swap(&a[i],&a[j]);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort(a,begin,j);
    }
    if(i < end)
    {
        qsort(a,i,end);
    }
}
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }
    
    qsort(ans,1,n);

    int count = 0,i = 1;

    while(count <= n && ans[i] > i)
    {
        count ++;
        i ++;
    }

    printf("%d",count);

    return 0;
}