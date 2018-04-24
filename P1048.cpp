#include <stdio.h>
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
    int t = read(),n = read();
    int dp[1001] = {};
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        for(int j = t;j >= a;j --)
        {
            if(dp[j - a] + b > dp[j])
            {
                dp[j] = dp[j - a] + b;
            }
        }
    }
    printf("%d",dp[t]);
    
    return 0;
}