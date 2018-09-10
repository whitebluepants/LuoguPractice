#include <stdio.h>
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
int dx[9] = {-2,-2,-1,1,0,2,2,1,-1};
int dy[9] = {-1,1,2,2,0,1,-1,-2,-2};
int main()
{
    int x1 = read(),y1 = read(),x2 = read(),y2 = read();
    long long dp[21][21] = {};
    int map[21][21] = {};
    
    // for(int i = 1;i <= 20;i ++)
    // {
    //     dp[0][i] = 1;
    //     dp[i][0] = 1;
    // }
    dp[0][0] = 1;
    for(int i = 0;i < 9;i ++)
    {
        int nx = x2 + dx[i];
        int ny = y2 + dy[i];
        if(nx >= 0 && nx <= 20 && ny >= 0 && ny <= 20)
        {
            dp[nx][ny] = 0;
            map[nx][ny] = 1;
        }
    }
    for(int i = 0;i <= x1;i ++)
    {
        for(int j = 0;j <= y1;j ++)
        {
            // if(dp[i][j] == -1)
            // {
            //     continue;
            // }
            // if(i == 0)
            // {
            //     dp[i][j] = dp[i][j - 1];
            // }  
            // else if(j == 0)
            // {
            //     dp[i][j] = dp[i - 1][j];
            // }
            // else if(dp[i][j - 1] == -1 && dp[i - 1][j] == -1)
            // {
            //     dp[i][j] = 0;
            // }
            // else if(dp[i - 1][j] == -1)
            // {
            //     dp[i][j] = dp[i][j - 1];
            // }
            // else if(dp[i][j - 1] == -1)
            // {
            //     dp[i][j] = dp[i - 1][j];
            // }
            // else 
            // {
            //     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            // }
            if(i == 0 && j == 0)
            {
                continue;
            }
            if(map[i][j] == 0)
            {
                if(i == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if(j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
    }

    printf("%lld",dp[x1][y1]);

    return 0;
}