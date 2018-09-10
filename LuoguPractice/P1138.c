#include <stdio.h>

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
        while(begin < end && a[end] >= mid)
        {
            --end;
        }
        swap(&a[begin],&a[end]);
        while(begin < end && a[begin] <= mid)
        {
            ++begin;
        }
        swap(&a[begin],&a[end]);
    }

    return begin;
}

void QuickSort(int a[],int begin,int end)
{
    if(begin < end)
    {
        int mid = part(a,begin,end);
        QuickSort(a,begin,mid - 1);
        QuickSort(a,mid + 1,end);
    }
}

int main()
{
    int a[10000];
    int n,m,t;

    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }

    QuickSort(a,0,n - 1);

    if(m == 1)
    {
        printf("%d",a[0]);
    }
    else
    {
        m --;
        for(int i = 1;i < n;i ++)
        {
            if(a[i] != a[i - 1])
            {
                m --;
            }
            if(m == 0)
            {
                printf("%d",a[i]);
                return 0;
            }
        }
    }
    if(m != 0)
    {
        printf("NO RESULT");
    }
    return 0;
}