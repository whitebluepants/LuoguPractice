#include <stdio.h>
#include <algorithm>
#define Max 9999999
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
    int n = read();
    int dp[101][101] = {};
    int ans[101] = {};
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
                dp[i][j] = Max;
            }
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        int a = read(),b = read(),c = read();
        ans[i] = a;
        dp[i][b] = 1;
        dp[i][c] = 1;
        dp[b][i] = 1;
        dp[c][i] = 1;
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

    int min = Max;
    for(int i = 1;i <= n;i ++)
    {
        int count = 0;
        for(int j = 1;j <= n;j ++)
        {
            count += dp[i][j] * ans[j];
        }
        if(count < min)
        {
            min = count;
        }
    }
    printf("%d",min);

    return 0;
}