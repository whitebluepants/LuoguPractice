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
    int n = read(),sum = 0;
    int a[50] = {};

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
        sum += a[i];
    }

    int l = read(),r = read();

    if(sum < l * n || sum > r * n)
    {
        printf("-1");
    }
    else
    {
        int x = 0,y = 0;
        for(int i = 0;i < n;i ++)
        {
            if(a[i] < l)
            {
                x += l - a[i];
            }
            if(a[i] > r)
            {
                y += a[i] - r;
            }
        }
        printf("%d",x>y?x:y);
    }
    
    return 0;
}