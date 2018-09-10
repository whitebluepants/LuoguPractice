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
    int n = read(),m = read(),t = read();
    int dp[201][201] = {};
    
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        for(int j = m;j >= a;j --)
        {
            for(int k = t;k >= b;k --)
            {
                dp[j][k] = max(dp[j][k],dp[j - a][k - b] + 1);
            }
        }
    }
    printf("%d",dp[m][t]);

    return 0;
}