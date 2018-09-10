#include <stdio.h>
#include <algorithm>
#include <string.h>
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
    int dp[201][201] = {};
    memset(dp,-9999,sizeof(dp));
    int n = read(),m = read();
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            dp[i][j] = read();
        }
    }
    
    for(int i = 2;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            dp[i][j] = max(dp[i - 1][j],max(dp[i - 1][j - 1],dp[i - 1][j + 1])) + dp[i][j];
        }
    }
    
    int maxx = -1,t = m / 2 + 1;
    for(int i = t - 1;i <= t + 1;i ++)
    {
        if(dp[n][i] > maxx)
        {
            maxx = dp[n][i];
        }        
    }
    printf("%d",maxx);
    
    return 0;
}