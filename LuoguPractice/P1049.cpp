#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int dp[20001] = {};
    int n = read(),m = read();
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        for(int j = n;n >= t;j --)
        {
            if(dp[j - t] + t > dp[j])
            {
                dp[j] = dp[j - t] + t;
            }
        }
    }
    printf("%d",n - dp[n]);

    return 0;
}