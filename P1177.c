#include <stdbool.h>
#include <stdio.h>
int read()
{
    char c = getchar();
    int x = 0;
    bool f = false;

    while(c < '0' || c > '9')
    {
        if(c == '-')
        {
            f = true;
        }
        c = getchar();
    }    
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return f?-1*x:x;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int a[],int begin,int end)
{
    if(begin >= end)
    {
        return;
    }
    int mid = a[(begin + end) / 2];
    int i = begin, j = end;
    while(i <= j)   // = ?    (= 76ms != 88ms)
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
        quicksort(a,begin,j);
    }
    if(i < end)
    {
        quicksort(a,i,end);
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
    quicksort(a,0,n - 1);
    for(int i = 0;i < n;i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}