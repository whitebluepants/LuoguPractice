#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <='9'){x = x * 10 + ch - '0';ch = getchar();}
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
        return;
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
    if(j > begin)
    {
        qsort(a,begin,j);
    }
    if(i < end)
    {
        qsort(a,i,end);
    }
}
int ans[1000000] = {};
int main()
{
    int count = 0;
    int n = read(),d = read();

    for(int i = 0;i < n;++ i)
    {
        ans[i] = read();
    }
    qsort(ans,0,n - 1);
    for(int i = 0;i < n;++ i)
    {
        for(int j = i + 1;j < n && ans[j] - ans[i] <= d;++ j)
        {
            ++ count;
        }
    }
    printf("%d",count);

    return 0;
}