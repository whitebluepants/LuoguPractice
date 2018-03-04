#include <stdio.h>
#include <stdbool.h>
int read()
{
    char ch = getchar();
    bool f = false;
    int x = 0;

    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = true;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f?-1*x:x;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max(int a[],int begin,int end)
{
    int dad = begin;
    int son = dad * 2 + 1;
    while(son <= end)
    {
        if(son + 1 <= end && a[son] < a[son + 1])
        {
            son ++;
        }
        if(a[dad] > a[son])
        {
            return;
        }
        else
        {
            swap(&a[dad],&a[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapsort(int a[],int end)
{
    int i;
    for(i = (end - 1) / 2;i >= 0;i --)
    {
        max(a,i,end - 1);
    }
    for(i = end - 1;i > 0;i --)
    {
        swap(&a[0],&a[i]);
        max(a,0,i - 1);
    }
}
int main()
{
    int a[100000];
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    heapsort(a,n);
    for(int i = 0;i < n;i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}