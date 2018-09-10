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
int main()
{
    int n = read(),m = read();
    int dp[31][31] = {};
    
    dp[0][1] = 1;

    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            int a = j - 1,b = j + 1;
            if(a == 0)
            {
                a = n;
            }
            if(b == n + 1)
            {
                b = 1;
            }
            dp[i][j] = dp[i - 1][a] + dp[i - 1][b];
        }
    }
    printf("%d",dp[m][1]);

    return 0;
}