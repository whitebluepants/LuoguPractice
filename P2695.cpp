#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
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
        while(a[i] < mid)
        {
            i ++;
        }
        while(a[j] > mid)
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
    if(end > i)
    {
        qsort(a,i,end);
    }
}
int main()
{
    int n = read(),m = read();
    int a[20000] = {},b[20000] = {};
    
    if(n > m)
    {
        printf("you died!");
        return 0;
    }
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    for(int i = 0;i < m;i ++)
    {
        b[i] = read();
    }
    qsort(a,0,n - 1);
    qsort(b,0,m - 1);
    
    int i,j;
    for(i = 0,j = 0;i < n && j < m;j ++)
    {
        if(a[i] <= b[j])
        {
            i ++;
            count += b[j];
        }
    }
    if(i != n)
    {
        printf("you died!");
    }
    else
    {
        printf("%d",count);
    }

    return 0;
}