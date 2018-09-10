#include <algorithm>
#include <stdio.h>
#include <math.h>
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
int ans[1001];
int dp[1001];
int get(int n)
{
    int sum = 0;
    for(int i = 1;i <= n / 2;i ++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }    
    return sum;
}
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = get(i);
    }
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = n;j >= i;j --)
        {
            dp[j] = max(dp[j],dp[j - i] + ans[i]);
        }
    }

    printf("%d",dp[n]);

    return 0;
}