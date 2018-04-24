#include <stdio.h>
#include <algorithm>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read(),m = read();
    int dp[101][10001] = {};

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        for(int j = 1;j <= m;j ++)
        {
            if(j > t)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - t];
            }
            else if(j == t)
            {
                dp[i][j] = dp[i][j - t] + 1;
            }
            else if(j < t)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d",count);

    return 0;
}