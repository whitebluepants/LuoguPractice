#include <stdio.h>
#include <algorithm>
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
    int d[1000][1000] = {};
    int dp[1001][1001] = {};
    int n = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j <= i;j ++)
        {
            d[i][j] = read();
            if(i == n - 1)
            {
                dp[i][j] = d[i][j];
            }
        }
    }
    for(int i = n - 2;i >= 0;i --)
    {
        for(int j = 0;j <= i;j ++)
        {
            dp[i][j] = max(d[i][j] + dp[i - 1][j],d[i][j] + dp[i - 1][j + 1]);
        }
    }

    printf("%d",dp[0][0]);

    return 0;
}