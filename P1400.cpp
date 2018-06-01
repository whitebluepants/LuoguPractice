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
int ans[600001];
long long count = 1;
int main()
{
    int n = read(),d = read();
    
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    qsort(ans,0,n - 1);
    
    for(int i = 0;i < n - 1;i ++)
    {
        int num = 1;
        for(int j = i + 1;j < n;j ++)
        {
            if(ans[i] + d >= ans[j])
            {
                num ++;
            }
            else
            {
                break;
            }
        }
        count *= num;
        count %= 1000000009;
    }
    printf("%lld",count);

    return 0;
}