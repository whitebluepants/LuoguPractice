#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
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
    int n = read(),d = read();
    int a[100001] = {};

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    qsort(a,0,n - 1);
    
    int count = 0;
    int temp = a[0] + d;

    for(int i = 1;i < n - 1;i ++)
    {
        if(a[i + 1] > temp)
        {
            temp = a[i] + d;
        }
        else
        {
            count ++;
        }
    }
    printf("%d",count);

    return 0;
}