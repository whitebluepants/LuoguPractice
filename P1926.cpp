#include <stdio.h>
#include <algorithm>
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
int main()
{
    int n = read(),m = read(),k = read(),r = read();
    int ans[11] = {};
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    qsort(ans,0,n - 1);
    int count = 0;
    
    int w[11] = {},v[11] = {};
    for(int i = 0;i < m;i ++)
    {
        w[i] = read();
    }
    for(int i = 0;i < m;i ++)  
    {
        v[i] = read();
    }
    int dp[151] = {};
    
    for(int i = 0;i < m;i ++)
    {
        for(int j = r;j >= w[i];j --)
        {
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
        }
    }
    int t = r;
    for(int i = 1;i <= r;i ++)
    {
        if(dp[i] >= k)
        {
            t = r - i;
            break;
        }
    }
    for(int i = 0;i < n;i ++)
    {
        if(ans[i] <= t)
        {
            count ++;
            t -= ans[i];
        }
        else
        {
            break;
        }
    }
    printf("%d",count);

    return 0;
}