#include <stdio.h>
#include <algorithm>
#define INF 9999999
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
    int n = read(),m = read(),t = read();
    int dp[301][301] = {};
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }
    
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        if(dp[a][b] > c)
        {
            dp[a][b] = c;
        }
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != k && dp[i][k] != INF)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(dp[i][j] > max(dp[i][k],dp[k][j]))
                    {
                        dp[i][j] = max(dp[i][k],dp[k][j]);
                    }
                }
            }
        }
    }

    for(int i = 0;i < t;i ++)
    {
        int a = read(),b = read();

        if(dp[a][b] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",dp[a][b]);
        }
    }

    return 0;
}