#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int dp[50001] = {};
int main()
{
    int c = read(),h = read();
    
    for(int i = 0;i < h;i ++)
    {
        int t = read();
        for(int j = c;j >= t;j --)
        {
            if(t + dp[j - t] > dp[j])
            {
                dp[j] = dp[j - t] + t;
            }
        }
    }
    printf("%d",dp[c]);

    return 0;
}