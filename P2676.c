#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int low,int high)
{
    int privotKey = a[low];
    while(low < high)
    {
        while(low < high && a[high] <= privotKey)
        {
            --high;
        }
        swap(&a[low], &a[high]);
        while(low < high && a[low] >= privotKey)
        {
            ++low;
        }
        swap(&a[low],&a[high]);
    }
    return low;
}

void quicksort(int a[],int low,int high)
{
    if(low < high)
    {
        int privotLoc = partition(a,low,high);
        quicksort(a,low,privotLoc - 1);
        quicksort(a,privotLoc + 1,high);
    }
}

int main()
{
    int n,b,a[20000],count = 0,sum = 0;
    scanf("%d %d",&n,&b);

    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }

    quicksort(a,0,n - 1);

    // int high = n -1, low = 0,temp;
    // while(low < high)
    // {
    //     for(int i = high;i > low;i --)
    //     {
    //         if(a[i] > a[i - 1])
    //         {
    //             temp = a[i];
    //             a[i] = a[i - 1];
    //             a[i - 1] = temp;
    //         }
    //     }
    //     ++low;
    //     for(int i = low;i < high;i ++)
    //     {
    //         if(a[i] < a[i + 1])
    //         {
    //             temp = a[i];
    //             a[i] = a[i + 1];
    //             a[i + 1] = temp;
    //         }
    //     }
    //     --high;
    // }

    for(int i = 0;i < n;i ++)
    {
        sum += a[i];
        count ++;
        if(sum >= b)
        {
            printf("%d",count);
            break;
        }
    }

    return 0;
}