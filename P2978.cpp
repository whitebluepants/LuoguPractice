#include <stdio.h>
#define INF 99999999
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
int dp[1005][1005];
int main()
{
    int n = read(),m = read(),j = read();

    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            if(i != j)
            {
                dp[i][j] = INF;
            }
        }
    }

    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read();
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(dp[i][k] != INF)
            {
                for(int j = i + 1;j <= n;j ++)
                {
                    if(dp[k][j] != INF)
                    {
                        dp[i][j] = dp[j][i] = 1;
                    }
                }
            }
        }
    }

    for(int i = 1;i <= j;i ++)
    {
        int a = read(),b = read();
        if(dp[a][b] == INF)
        {
            printf("N\n");
        }
        else
        {
            printf("Y\n");
        }
    }

    return 0;
}