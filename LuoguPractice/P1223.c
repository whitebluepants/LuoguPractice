#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '0')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int a[][2],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    int mid = a[(begin + end) / 2][0];

    while(i <= j)
    {
        while(a[i][0] < mid)
        {
            i ++;
        }
        while(a[j][0] > mid)
        {
            j --;
        }
        if(i <= j)
        {
            swap(&a[i][0],&a[j][0]);
            swap(&a[i][1],&a[j][1]);
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
    int n = read();
    int ans[1000][2] = {};
    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read();
        ans[i][1] = i + 1;
    }
    qsort(ans,0,n - 1);
    long long sum = 0;
    for(int i = 0,j = n - 1;i < n;i ++,j --)
    {
        printf("%d ",ans[i][1]);
        sum += ans[i][0] * j;
    }
    printf("\n%.2f",sum * 1.0 / n);

    return 0;
}