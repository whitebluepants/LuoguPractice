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
    int v = read(),n = read(),c = read();
    int dp[10001] = {};
    
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        for(int j = c;j >= b;j --)
        {
            dp[j] = max(dp[j],dp[j - b] + a);
        }
    }
    int maxx = -1;
    for(int i = 1;i <= c;i ++)
    {
        if(dp[i] >= v)
        {
            maxx = i;
            break;
        }
    }
    if(maxx == -1)
    {
        printf("Impossible");
    }
    else
    {
        printf("%d",c - maxx);
    }
    return 0;
}