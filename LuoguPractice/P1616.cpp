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
    int dp[100001] = {};
    int t = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int w = read(),v = read();
        for(int j = w;j <= t;j ++)
        {
            dp[j] = max(dp[j],dp[j - w] + v);
        }
    }
    printf("%d",dp[t]);

    return 0;
}