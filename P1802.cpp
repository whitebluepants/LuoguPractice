#include <stdio.h>
#include <algorithm>
using namespace std;
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    long long dp[1001] = {};
    int n = read(),m = read();
    
    for(int i = 0;i < n;i ++)
    {
        long long a = read(),b = read(),c = read();
        for(int j = m;j >= 0;j --)
        {
            if(j < c)
            {
                dp[j] = dp[j] + a;
            }
            else
            {
                dp[j] = max(dp[j] + a,dp[j - c] + b);
            }
        }
    }

    printf("%lld",dp[m] * 5);

    return 0;
}