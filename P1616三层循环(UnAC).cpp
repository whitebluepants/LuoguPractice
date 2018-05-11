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
int dp[2001][50001];
int main()
{
    int m = read(),t = read();

    for(int i = 0;i < t;i ++)
    {
        int w = read(),v = read();
        for(int j = 0;j <= m;j ++)
        {
            for(int k = 1;k * w <= j;k ++)
            {
                dp[i + 1][j] = max(dp[i + 1][j],dp[i][j - k * w] + k * v);
            }
        }
    }

    printf("%d",dp[t][m]);

    return 0;
}