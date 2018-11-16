#include <stdio.h>
#define Max 999999999
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
int dp[101][101];
int main()
{
    int n = read(),m = read();

    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            if(i != j)
            {
                dp[i][j] = Max;
            }
        }
    }

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),k = read();
        if(dp[a][b] > k)
        {
            dp[a][b] = dp[b][a] = k;
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
    int t = 0,Min = Max;
    for(int i = 1;i <= n;i ++)
    {
        int flag = 0,max = -1;
        for(int j = 1;j <= n;j ++)
        {
            if(i != j && dp[i][j] == 0)
            {
                flag = 1; 
                break;
            }
            if(i != j && max < dp[i][j])
            {
                max = dp[i][j];
            }
        }
        if(flag == 0 && max < Min)
        {
            t = i;
            Min = max;
        }
    }
    if(t == 0)
    {
        printf("%d",0);
    }
    else
    {
        printf("%d %d",t,Min);
    }

    return 0;
}