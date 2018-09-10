#include <stdio.h>
#define Max 99999999
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
    int p = read(),f = read(),c = read();
    int dp[501][501] = {};
    int fav[500] = {};
    
    for(int i = 1;i <= p;i ++)
    {
        for(int j = 1;j <= p;j ++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = Max;    
            }
        }
    }
    for(int i = 0;i < f;i ++)
    {
        fav[i] = read();
    }
    
    for(int i = 0;i < c;i ++)
    {
        int a  = read(),b = read(),c = read();
        if(dp[a][b] > c)
        {
            dp[a][b] = c;
            dp[b][a] = c;
        }
    }
    
    for(int k = 1;k <= p;k ++)
    {
        for(int i = 1;i <= p;i ++)
        {
            if(i != k)
            {
                for(int j = 1;j <= p;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        dp[j][i] = dp[i][j];
                    }
                }
            }
        }
    }
    
    double min = 99999;
    int ans = -1;
    for(int i = 1;i <= p;i ++)
    {
        double count = 0;
        for(int j = 0;j < f;j ++)
        {
            count += dp[i][fav[j]];
        }
        count /= f;
        if(count < min)
        {
            min = count;
            ans = i;
        }
    }
    printf("%d",ans);

    return 0;
}