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
int dp[1000][80000] = {};
int main()
{
    int t = read(),m = read();
    
    for(int i = 0;i < m;i ++)
    {
        int w = read(),v = read();
        for(int j = w;j <= t;j ++)
        {
            dp[i + 1][j] = max(dp[i][j],dp[i + 1][j - w] + v);
        }
    }

    printf("%d",dp[m][t]);

    return 0;
}