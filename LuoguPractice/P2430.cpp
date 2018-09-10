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
int dp[5001] = {};
int knowledge[5001] = {};
int problem[5001][2] = {};
int main()
{
    int a = read(),b = read();
    int tt = b / a;
    int m = read(),n = read();

    for(int i = 1;i <= n;i ++)
    {
        knowledge[i] = read();
    }
    for(int i = 1;i <= m;i ++)
    {
        problem[i][0] = read(),problem[i][1] = read();
    }
    int time = read();
    for(int i = 1;i <= m;i ++)
    {
        int w = tt * knowledge[problem[i][0]];
        int v = problem[i][1];
        for(int j = time;j >= w;j --)
        {
            dp[j] = max(dp[j],dp[j - w] + v);
        }
    }

    printf("%d",dp[time]);

    return 0;
}
