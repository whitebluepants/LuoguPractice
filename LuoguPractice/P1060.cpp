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
int n,m;
int a[25] = {};
int b[25] = {};
int dp[30001] = {};
int main()
{
    n = read(),m = read();
    for(int i = 0;i < m;i ++)
    {
        a[i] = read(),b[i] = read();
    }
    
    for(int i = 0;i < m;i ++)
    {
        for(int j = n;j >= a[i];j --)
        {
            dp[j] = max(dp[j],dp[j - a[i]] + a[i] * b[i]);
        }
    }
    
    printf("%d",dp[n]);
    return 0;
}