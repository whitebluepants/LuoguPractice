#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '0')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,m;
int w[3402] = {};
int v[3402] = {};
int dp[12882] = {};

int main()
{
    n = read(),m = read();
    
    for(int i = 0;i < n;i ++)
    {
        w[i] = read(),v[i] = read();
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = m;j >= w[i];j --)
        {
            if(dp[j - w[i]] + v[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + v[i];
            }
        }
    }

    printf("%d",dp[m]);

    return 0;
}