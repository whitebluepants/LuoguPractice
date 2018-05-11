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
int dp[10001];
int main()
{
    int m = read(), n = read();

    for(int i = 0;i < n;i ++)
    {
        int v = read(), w = read();
        for(int j = w;j <= m;j ++)
        {
            dp[j] = max(dp[j],dp[j - w] + v);
        }
    }

    printf("%d",dp[m]);
    
    return 0;
}