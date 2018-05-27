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
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int m = read(),n = read();
        int dp[12][12] = {};

        for(int i = 0;i <= n;i ++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1;i <= n;i ++)
        {
            dp[i][1] = 1;

            for(int j = 2;j <= m;j ++)
            {
                if(i <= j)
                {
                    dp[i][j] = dp[i][j - i] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[j][j];
                }
            }
        }    
        printf("%d\n",dp[n][m]);    
    }
    return 0;
}