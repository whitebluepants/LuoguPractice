#include <stdio.h>
#include <string.h>
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
int main()
{
    int dp[202][202] = {};
    int n = read(),m = read();
    memset(dp,-9999,sizeof(dp));
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            dp[i][j] = read();
        }
    }
    int t = m / 2 + 1,x = 1,f = 1;
    
    for(int i = n - 1;i >= 1;i --)
    {
        f ++;
        if(x < t - 1)
        {
            x ++;
        }
        for(int j = t - x;j <= t + x;j ++)
        {
            if(f < t && j == t - x)
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i][j];
            }
            else if(f < t && j == t + x)
            {
                dp[i][j] = dp[i + 1][j - 1] + dp[i][j];
            }
            else if(f < t && j == t - x + 1)
            {
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j + 1]) + dp[i][j];
            }
            else if(f < t && j == t + x - 1)
            {
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - 1]) + dp[i][j];
            }
            else
            {
                dp[i][j] = max(max(dp[i + 1][j],dp[i + 1][j - 1]),dp[i + 1][j + 1]) + dp[i][j];
            }
        }
    }
    int maxx = -1;
    for(int i = 1;i <= m;i ++)
    {
        if(dp[1][i] > maxx)
        {
            maxx = dp[1][i];
        }
    }
    printf("%d",maxx);

    return 0;
}