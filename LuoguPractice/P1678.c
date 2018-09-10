#include <stdio.h>
#include <stdlib.h>
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
int a[100000] = {};
int b[100000] = {};
int n,m;
int getmin(int t)
{
    int i = 0,j = n - 1,min = 9999999;
    while(i <= j)
    {
        int mid = (i + j) / 2;
        int m = a[mid];
        int ab = abs(m - t);
        if(m == t)
        {
            return 0;
        }
        if(ab < min)
        {
            min = ab;
        }
        if(m > t)
        {
            j = mid - 1;
        }
        if(m < t)
        {
            i = mid + 1;
        }
    }
    return min;
}
int main()
{
    n = read(),m = read();
    
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

    int count = 0;
    
    
    for(int i = 0;i < m;i ++)
    {
        count += getmin(b[i]);
    }

    printf("%d",count);

    return 0;
}