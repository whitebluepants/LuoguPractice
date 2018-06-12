#include <stdio.h>
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
    int n = read(),k = read();
    int dp[7][201] = {};

    for(int i = 1;i <= k;i ++)
    {
        dp[i][i] = 1;
    }
    for(int i = 1;i <= n;i ++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2;i <= k;i ++)
    {
        for(int j = i;j <= n;j ++)
        {
            if(j - i >= i)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    printf("%d",dp[k][n]);

    return 0;
}