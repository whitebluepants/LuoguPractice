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
int mmin[100005];
int mmax[100005];
int ans[100005];
int a[100005];
int main()
{
    int n = read();
    
    int Min = -1;
    for(int i = 0;i < n;i ++)
    {
        mmin[i] = Min;
        ans[i] = read();
        if(ans[i] > Min)
        {
            Min = ans[i];
        }
    }
    int Max = 2000000000;
    for(int i = n - 1;i >= 0;i --)
    {
        mmax[i] = Max;
        if(ans[i] < Max)
        {
            Max = ans[i];
        }
    }   
    int k = 0;
    
    for(int i = 0;i < n;i ++)
    {
        if(ans[i] > mmin[i] && ans[i] < mmax[i])
        {
            a[k ++] = ans[i];
        }
    }
    printf("%d\n",k);
    sort(a,a + k);
    for(int i = 0;i < k;i ++)
    {
        if(i == 0)
        {
            printf("%d",a[i]);
        }
        else
        {
            printf(" %d",a[i]);
        }
    }
    printf("\n"); // 没有该换行符第3个点会显示格式错误

    return 0;
}