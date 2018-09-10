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
int dp[100002] = {};
int main()
{
    int n = read(),k = read();

    dp[0] = 1;
    for(int i = 0;i <= n;i ++)
    {
        for(int j = 1;j <= k;j ++)
        {
            if(i - j < 0)
            {
                dp[i] = dp[i] % 100003;
            }
            else
            {
                dp[i] = (dp[i] + dp[i - j]) % 100003;
            }
        }
    }
    printf("%d",dp[n]);

    return 0;
}