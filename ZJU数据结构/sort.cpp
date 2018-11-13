#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;    
}
void BubbleSort(int a[],int N);
void InsertSort(int a[],int N);
void ShellSort(int a[],int N);
void Sedgewick_ShellSort(int a[],int N);
void SelectSort(int a[],int N);
void PercDown(int a[],int p,int n);
void HeapSort(int a[],int N);
void Recursion_MergeSort(int a[],int N);
void Recursion_Merge(int a[],int tmp[],int begin,int mid,int end);
void Recursion_Msort(int a[],int tmp[],int begin,int end);
void UnRecursion_MergeSort(int a[],int N);
void UnRecursion_MergePass(int a[],int temp[],int length,int N);
void UnRecursion_Merge(int a[],int temp[],int b1,int e1,int b2,int e2);
void My_QuickSort(int a[],int N);
void My_Qsort(int a[],int begin,int end);
void QuickSort(int a[],int N);
void Qsort(int a[],int begin,int end);
int median3(int a[],int begin,int end);
void swap(int *a,int *b);
void printArray(int a[],int N);
int ans[100010];
int main()
{
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    
    // BubbleSort(ans,n);
    // InsertSort(ans,n);
    // ShellSort(ans,n);
    // Sedgewick_ShellSort(ans,n);
    // SelectSort(ans,n);
    // HeapSort(ans,n);
    // Recursion_MergeSort(ans,n);
    // UnRecursion_MergeSort(ans,n);
    // My_QuickSort(ans,n);
    // QuickSort(ans,n);
    printArray(ans,n);

    return 0;
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int a[],int N)
{
    int flag = 0;
    for(int i = 0;i < N;i ++)
    {
        if(flag)
        {
            printf(" ");
        }
        printf("%d",a[i]);
        flag = 1;
    }
    return ;
}

void BubbleSort(int a[],int N) // 冒泡排序
{
    for(int i = 0;i < N - 1;i ++) // 只需要排n-1次
    {
        int flag = 0; // 标志是否有不必要的排序 优化复杂度
        for(int j = 0;j < N - 1 - i;j ++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j],&a[j + 1]);
                flag = 1; 
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
    return ;
}


// 如果基本有序, 时效比冒泡好很多
void InsertSort(int a[],int N) // 插入排序
{
    int i,j;
    for(i = 0;i < N - 1;i ++)
    {
        for(j = i + 1;j > 0 && a[j - 1] > a[j];j --)
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }
    return ;
}


void ShellSort(int a[],int N)  // 正常的希尔排序
{
    for(int i = N / 2;i > 0;i /= 2) // 是i /= 2 不是i --  i --会慢很多
    {
        for(int j = i;j < N;j ++)
        {
            for(int k = j;k >= i && a[k - i] > a[k];k -= i)
            {
                int temp = a[k];
                a[k] = a[k - i];
                a[k - i] = temp;
            }
        }
    }
    return ;
}


// 用素数列也可以 但要保证最后一次要以1进行排一次
void Sedgewick_ShellSort(int a[],int N) // Sedgewick增量序列的希尔排序
{
    int Si[7] = { 929,505,209,41,19,5,1 }; // 9x4^i - 9x2^i + 1 || 4^i - 3x2^i + 1
    for(int i = 0;i < 7;i ++)
    {
        if(Si[i] >= N)
        {
            continue;
        }
        for(int j = Si[i];j < N;j ++)
        {
            for(int k = j;k >= Si[i] && a[k] < a[k - Si[i]];k -= Si[i])
            {
                int temp = a[k];
                a[k] = a[k - Si[i]];
                a[k - Si[i]] = temp;
            }
        }
    }
    return ;
}


void SelectSort(int a[],int N) // 选择排序
{
    for(int i = 0;i < N - 1;i ++)
    {
        int min = a[i],index = i;
        for(int j = i + 1;j < N;j ++)
        {
            if(a[j] < min)
            {
                min = a[j];
                index = j;
            }
        }
        swap(&a[i],&a[index]);
    }
    return ;
}


void HeapSort(int a[],int N) // 堆排
{
    for(int i = N / 2 - 1;i >= 0;i --)
    {
        PercDown(a,i,N);
    }

    for(int i = N - 1;i > 0;i --)
    {
        swap(&a[i],&a[0]);
        PercDown(a,0,i);
    }

    return ;
}
void PercDown(int a[],int p,int N)
{
    int parent = p,child = p * 2 + 1;
    int i,temp = a[parent];

    for(i = parent;i * 2 + 1 < N;i = child) // 条件的范围是i * 2 + 1 而不是单是i
    {
        child = i * 2 + 1;
        if(child + 1 < N && a[child] < a[child + 1])
        {
            child ++;
        }
        if(temp >= a[child]) // 注意是temp而不是a[i]
        {
            break;
        }
        a[i] = a[child];
    }
    a[i] = temp;
}


void Recursion_MergeSort(int a[],int N) // 递归实现的归并排序
{
    int temp[100010] = {};

    Recursion_Msort(a,temp,0,N - 1);

    return ;
}
void Recursion_Msort(int a[],int tmp[],int begin,int end)
{
    if(begin < end)
    {
        int mid = (begin + end) / 2;
        
        Recursion_Msort(a,tmp,begin,mid);
        Recursion_Msort(a,tmp,mid + 1,end);
        Recursion_Merge(a,tmp,begin,mid,end);
    }
}
void Recursion_Merge(int a[],int tmp[],int begin,int mid,int end)
{
    int b = begin,e = end;

    int i = begin,j = mid + 1;
    int k = begin;

    while(i <= mid && j <= end)
    {
        if(a[i] > a[j])
        {
            tmp[k ++] = a[j ++];
        }
        else
        {
            tmp[k ++] = a[i ++];
        }
    }
    
    while(i <= mid)
    {
        tmp[k ++] = a[i ++];
    }
    while(j <= end)
    {
        tmp[k ++] = a[j ++];
    }

    for(int i = b;i <= e;i ++)
    {
        a[i] = tmp[i];
    }
}


void UnRecursion_MergeSort(int a[],int N) // 速度比递归性的稍微快点
{
    int temp[100010] = {};
    int length = 1;

    while(length < N)
    {
        UnRecursion_MergePass(a,temp,length,N);
        length *= 2;
        UnRecursion_MergePass(temp,a,length,N);
        length *= 2;
    }

    return ;
}
void UnRecursion_MergePass(int a[],int temp[],int length,int N)
{
    int i;
    for(i = 0;i < N - 2 * length;i += 2 * length)
    {
        UnRecursion_Merge(a,temp,i,i + length - 1,i + length,i + 2 * length - 1);
    }

    if(i + length < N)
    {
        UnRecursion_Merge(a,temp,i,i + length - 1,i + length,N - 1);
    }
    else
    {
        for(int j = i;j < N;j ++)
        {
            temp[j] = a[j];
        }
    }
}
void UnRecursion_Merge(int a[],int temp[],int b1,int e1,int b2,int e2)
{
    int k = b1;

    while(b1 <= e1 && b2 <= e2)
    {
        if(a[b1] <= a[b2])
        {
            temp[k ++] = a[b1 ++];
        }
        else
        {
            temp[k ++] = a[b2 ++];
        }
    }

    while(b1 <= e1)
    {
        temp[k ++] = a[b1 ++];
    }
    while(b2 <= e2)
    {
        temp[k ++] = a[b2 ++];
    }
}

void My_QuickSort(int a[],int N) // 自用快速排序 以中间值为pivot
{
    My_Qsort(a,0,N - 1);

    return ;
}
void My_Qsort(int a[],int begin,int end)
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
        My_Qsort(a,begin,j);
    }
    if(i < end)
    {
        My_Qsort(a,i,end);
    }
}

void QuickSort(int a[],int N) // ZJU的快排
{
    Qsort(a,0,N - 1);
}
int Cutoff = 5; // 阀值 在5附近最好 当设置为10以上的时候 会变的很慢
void Qsort(int a[],int begin,int end)
{
    if(Cutoff <= end - begin)
    {
        int pivot = median3(a,begin,end);
        int i = begin,j = end - 1;
        while(1)
        {
            while(a[++ i] < pivot)
            {
                ;
            }
            while(a[-- j] > pivot)
            {
                ;
            }
            if(i < j)
            {
                swap(&a[i],&a[j]);
            }
            else
            {
                break;
            }
        }
        swap(&a[i],&a[end - 1]);
        Qsort(a,begin,i - 1);
        Qsort(a,i,end);
    }
    else
    {
        InsertSort(a + begin,end - begin + 1);
    }
}
int median3(int a[],int begin,int end)
{
    int center = (begin + end) / 2;
    if(a[begin] > a[center])
    {
        swap(&a[begin],&a[center]);
    }
    if(a[begin] > a[end])
    {
        swap(&a[begin],&a[end]);
    }
    if(a[center] > a[end])
    {
        swap(&a[center],&a[end]);
    }
    swap(&a[center],&a[end - 1]);

    return a[end - 1];
}