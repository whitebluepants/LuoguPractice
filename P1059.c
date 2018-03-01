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

    return end;
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
    int n;
    int a[100],b[100] = {};
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n - 1);
    
    int j = 1;
    b[0] = a[0];
    for(int i = 1;i < n;i ++)
    {
        if(b[j - 1] != a[i])
        {
            b[j] = a[i];
            j ++;
        }
    }
    printf("%d\n",j);
    for(int i = 0;i < j;i ++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}