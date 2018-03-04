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
int part(int a[],int begin,int end)
{
    int mid = a[begin];
    while(begin < end)
    {
        while(begin < end && mid <= a[end])
        {
            end --;
        }
        swap(&a[begin],&a[end]);
        while(begin < end && mid >= a[begin])
        {
            begin ++;
        }
        swap(&a[begin],&a[end]);
    }
    return begin; 
}
void quicksort(int a[],int begin,int end,int k)
{
    if(begin - end > k)
    {
        int mid = part(a,begin,end);
        quicksort(a,begin,mid - 1,k);
        quicksort(a,mid + 1,end,k);
    }
}
void quicksortimprove(int a[],int begin,int end,int k)
{
    quicksort(a,begin,end,k);

    int temp,j;
    for(int i = begin + 1;i <= end;i ++)
    {
        temp = a[i];
        for(j = i;j > 0 && a[j - 1] > temp;j --)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
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
    quicksortimprove(a,0,n - 1,8);
    for(int i = 0;i < n;i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}