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
int ans[100005] = {};
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
    int n = read(),k = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    qsort(ans,0,n - 1); // will tle on 32 point fucking sequence

    int count = 0,temp;
    
    if(k == 0)
    {
        temp = ans[0] - 1;
    }
    else
    {
        temp = ans[k - 1];
    }
    
    for(int i = 0;i < n;i ++)
    {
        if(ans[i] <= temp)
        {
            count ++;   
        }
    }
    
    if(count != k || !(temp >= 1 && temp <= 1000 * 1000 * 1000))
    {
        printf("-1");
    }
    else
    {
        printf("%d",temp);
    }

    return 0;
}