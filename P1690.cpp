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
    int n = read();
    int dp[101][101];
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            dp[i][j] = read();
        }
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != k)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    int minn = 999999999;
    int ans[10] = {};
    
    int m = read();

    for(int i = 0;i < m;i ++)
    {
        ans[i] = read();
    }
    
    sort(ans, ans + m);
    
    do
    {
        int u = 1,dis = 0;
        for(int i = 0;i < m;i ++)
        {
            int v = ans[i];
            dis += dp[u][v];
            u = v;
        }
        dis += dp[u][n];
        if(dis < minn)
        {
            minn = dis;
        }
    }while(next_permutation(ans,ans + m));

    printf("%d",minn);

    return 0;
}