#include <stdio.h>
#include <iostream>
#define INF 99999999
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
    int n = read(),k = read();
    int dp[21][21];
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }
    for(int i = 0;i < n;i ++)
    {
        int t = read();
        if(i < n - 1)
        {
            dp[i][i + 1] = t;
            dp[i + 1][i] = t;
        }
        else
        {
            dp[i][0] = t;
            dp[0][i] = t;
        }
    }
    for(int i = 0;i < k;i ++)
    {
        char a,b;
        int c;
        cin >> a >> b >> c;
        int x = a - 'A',y = b - 'A';
        if(dp[x][y] == INF)
        {
            dp[x][y] = c;
            dp[y][x] = c;
        }
        else if(dp[x][y] < c)
        {
            dp[x][y] = c;
            dp[y][x] = c;
        }
    }
    char a,b;
    cin >> a >> b;
    int x = a - 'A',y = b - 'A';

    for(int k = 0;k < n;k ++)
    {
        for(int i = 0;i < n;i ++)
        {
            if(i != k)
            {
                for(int j = 0;j < n;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    printf("%d",dp[x][y]);

    return 0;
}