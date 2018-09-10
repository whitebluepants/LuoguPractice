#include <stdio.h>
using namespace std;
#define INF 9999999
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
    int dp[101][101] = {};

    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read();
        dp[a][b] = 1;
        dp[b][a] = -1;
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != k)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(dp[i][k] == 1 && dp[k][j] == 1)
                    {
                        dp[i][j] = 1;
                        dp[j][i] = -1;
                    }
                }
            }
        }
    }
    int count = 0;

    for(int i = 1;i <= n;i ++)
    {
        int flag = 0;
        for(int j = 1;j <= n;j ++)
        {
            if(i == j)
            {
                continue;
            }
            if(!(dp[i][j] == 1 || dp[i][j] == -1))
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            count ++;
        }
    }
    printf("%d",count);
    return 0;
}