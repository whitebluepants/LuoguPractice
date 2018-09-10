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
void qsort(int a[],int b[],int begin,int end)
{
    if(begin >= end)
    {
        return;
    }
    int i = begin,j = end;
    int mid = b[(begin + end) / 2];
    while(i <= j)
    {
        while(b[i] > mid)
        {
            i ++;
        }
        while(b[j] < mid)
        {
            j --;
        }
        if(i <= j)
        {
            swap(&b[i],&b[j]);
            swap(&a[i],&a[j]);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort(a,b,begin,j);
    }
    if(end > i)
    {
        qsort(a,b,i,end);
    }
}
int main()
{ 
    int n = read(), m = read();
    int a[5000] = {};
    int b[5000] = {};
    for(int i = 0;i < n;i ++)
    {
        a[i] = read(),b[i] = read();
    }
    int t = m * 1.5;
    qsort(a,b,0,n - 1);

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(b[j] == b[j + 1])
            {
                if(a[j] > a[j + 1])
                {
                    swap(&a[j],&a[j + 1]);
                }
            }
        }
    }
    int g = b[t - 1];
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        if(b[i] >= g)
        {
            count ++;
        }
    }
    printf("%d %d\n",g,count);

    for(int i = 0;i < count;i ++)
    {
        printf("%d %d\n",a[i],b[i]);
    }
    return 0;
}