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
int main()
{
    int n = read(),m = read();
    int dp[45001] = {};

    int t;
    for(int i = 0;i < m;i ++)
    {
        t = read();
        for(int j = n;j >= t;j --)
        {
            dp[j] = max(dp[j],dp[j - t] + t);
        }
    }
    printf("%d",dp[n]);

    return 0;
}