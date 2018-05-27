#include <stdio.h>
#include <queue>
#include <iostream>
#define INF 9999999
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
int dp[53][53];
int map[124];
int main()
{
    int n = read();

    int num = 1;
    for(char i = 'A';i <= 'Z';i ++)
    {
        map[i] = num ++;
    }
    for(char i = 'a';i <= 'z';i ++)
    {
        map[i] = num ++;
    }

    for(int i = 1;i <= 52;i ++)
    {
        for(int j = 1;j <= 52;j ++)
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

    for(int i = 1;i <= n;i ++)
    {
        char a,b;
        int c;
        cin >> a >> b >> c;
        
        if(dp[map[a]][map[b]] > c)
        {
            dp[map[a]][map[b]] = c;
            dp[map[b]][map[a]] = c;
        }
    }
    for(int k = 1;k <= 52;k ++)
    {
        for(int i = 1;i <= 52;i ++)
        {
            if(i != k && dp[i][k] != INF)
            {
                for(int j = 1;j <= 52;j ++)
                {
                    if(dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }

    char t;
    int min = INF;
    for(int i = 1;i <= 25;i ++)
    {
        if(dp[i][26] < min)
        {
            min = dp[i][26];
            t = i + 'A' - 1;
        }
    }

    printf("%c %d",t,min);

    return 0;
}