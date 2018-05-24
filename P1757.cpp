#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
    int w,v,n;
};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
bool cmp(node a,node b)
{
    return a.n < b.n;
}
int main()
{
    int n = read(),m = read();
    int a[101] = {};
    int dp[1001] = {};
    node ans[1001] = {};
    int number = 0;
    for(int i = 0;i < m;i ++)
    {  
        ans[i].w = read(),ans[i].v = read(),ans[i].n = read();
        a[ans[i].n] ++;
        if(ans[i].n > number)
        {
            number = ans[i].n;
        }
    }
    sort(ans,ans + m,cmp);
    int t = 0,tt = a[1];
    for(int i = 1;i <= number;i ++)
    {
        for(int j = n;j >= 0;j --)
        {
            for(int k = t;k < tt;k ++)
            {
                if(j >= ans[k].w)
                {
                    dp[j] = max(dp[j],dp[j - ans[k].w] + ans[k].v);
                }
            }
        }
        t = tt;
        tt += a[i + 1];
    }

    printf("%d",dp[n]);

    return 0;
}