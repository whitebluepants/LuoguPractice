#include <stdio.h>
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
    int ans1[100000] = {},ans2[100000] = {};

    for(int i = 0;i < n;i ++)
    {
        ans1[i] = read();
    }
    for(int i = 0;i < m;i ++)
    {
        ans2[i] = read();
    }

    qsort(ans1,0,n - 1);
    qsort(ans2,0,m - 1);

    int count = 0;
    int ans[100000] = {};
    int j = 0;
    for(int i = 0;i < m;i ++)
    {
        if(j < n && ans2[i] > ans1[j])
        {
            ans[i] = 1;
            j ++;
        }
    }
    if(j != n)
    {
        printf("0");
    }
    else
    {
        for(int i = 0;i < m;i ++)
        {
            if(ans[i] == 0)
            {
                count += ans2[i];
            }
        }
        printf("%d",count);
    }

    return 0;
}