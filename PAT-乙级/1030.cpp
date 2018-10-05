#include <stdio.h>
using namespace std;
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
long long ans[100001];
void swap(long long *a,long long *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(long long a[],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    long long mid = a[(begin + end) / 2];

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
    long long n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    qsort(ans,0,n - 1);

    long long j = 0,len = 0,cnt = 1;
    for(int i = 0;i < n;i ++)
    {
        int min = ans[i];
        cnt --;
        while(j < n && ans[j] <= min * m)
        {
            j ++;
            cnt ++;
        }
        if(cnt > len)
        {
            len = cnt;
        }
    }

    printf("%d",len);
    
    return 0;
}