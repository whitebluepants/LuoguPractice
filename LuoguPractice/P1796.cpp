#include <stdio.h>
#include <algorithm>
#define INF 999999
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
    int n = read(),m;
    int dp[101][101] = {};
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        m = read();
        for(int j = 0;j < m;j ++)
        {
            dp[i + 1][j] = INF;
            int a,b;
            scanf("%d",&a);
            while(a != 0)
            {
                scanf("%d",&b);
                dp[i + 1][j] = min(dp[i + 1][j],dp[i][a - 1] + b);
                scanf("%d",&a);
            }
        }
    }
    int minn = INF;
    for(int i = 0;i < m;i ++)
    {
        if(dp[n][i] < minn)
        {
            minn = dp[n][i];
        }
    }
    printf("%d",minn);

    return 0;
}