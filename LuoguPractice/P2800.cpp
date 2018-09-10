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
int ans[1000002];
int dp[1000002];
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }

    for(int i = 1;i <= n + 1;i ++)
    {
        dp[i] = dp[i - 1] + ans[i];
        if(i >= 2)
        {
            dp[i] = min(dp[i],dp[i - 3] + ans[i]);
        }
        if(i >= 1)
        {
            dp[i] = min(dp[i],dp[i - 2] + ans[i]);
        }
    }
    printf("%d",dp[n + 1]);
    
    return 0;
}