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
    int n = read();
    n /= 2;
    double dp[1251][1251] = {};

    for(int i = 2;i <= n;i ++)
    {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1] * 0.5;
        }
    }
    printf("%.4f",dp[n][n]);

    return 0;
}