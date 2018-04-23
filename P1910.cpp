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
    int n = read(),m = read(),x = read();
    int dp[1001] = {};
    int a,b,c;
    for(int i = 0;i < n;i ++)
    {
        a = read(),b = read(),c = read();
        for(int j = x;j >= c;j --)
        {
            if(b <= m)
            {
                if(dp[j - c] + a > dp[j])
                {
                    dp[j] = dp[j - c] + a;
                }
            }
        }
    }
    printf("%d",dp[x]);

    return 0;
}