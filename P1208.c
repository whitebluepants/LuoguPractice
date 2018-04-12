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
    int n = read(),m = read(),sum = 0;
    int a[5000][2] = {};
    
    for(int i = 0;i < m;i ++)
    {
        a[i][0] = read(),a[i][1] = read();
    }
    qsort(a,0,m - 1);

    for(int i = 0;i < n;i ++)
    {
        if(a[i][1] > n)
        {
            sum += n * a[i][0];
            n = 0;
        }
        else
        {
            sum += a[i][1] * a[i][0];
            n -= a[i][1];
        }

        if(n == 0)
        {
            break;
        }
    }

    printf("%d",sum);

    return 0;
}