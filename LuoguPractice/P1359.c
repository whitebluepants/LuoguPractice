#include <stdio.h>
#include <string.h>
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
    int n = read();
    int dp[201][201] = {};
    memset(dp,9999,sizeof(dp));

    for(int i = 1;i < n;i ++)
    {
        for(int j = i + 1;j <= n;j ++)
        {
            dp[i][j] = read();
        }
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != k)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }    
            }
        }
    }

    printf("%d",dp[1][n]);

    return 0;
}