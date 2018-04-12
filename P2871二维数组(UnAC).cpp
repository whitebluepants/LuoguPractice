#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int dp[3403][12881] = {};
int main()
{
    int n = read(),m = read();
    int a,b;

    for(int i = 0;i < n;i ++)
    {
        a = read(),b = read();
        for(int j = 1;j <= m;j ++)
        {
            if(j < a)
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j],dp[i][j - a] + b);
            }
        }
    }
    printf("%d",dp[n][m]);

    return 0;
}