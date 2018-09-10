#include <stdio.h>
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
    int n = read(),m = read();
    int dp[100][100] = {};
    int path[10000] = {};
    for(int i = 0;i < m;i ++)
    {
        path[i] = read();
    }
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            dp[i][j] = read();
        }
    }

    for(int k = 0;k < n;k ++)
    {
        for(int i = 0;i < n;i ++)
        {
            if(i != k)
            {
                for(int j = 0;j < n;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    int count = 0;
    int t = 0;
    for(int i = 0;i < m;i ++)
    {
        count += dp[t][path[i] - 1];
        t = path[i] - 1;
    }
    printf("%d\n",count);

    return 0;
}