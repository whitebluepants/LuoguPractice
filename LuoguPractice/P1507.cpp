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
int dp[401][401];
int main()
{
    int maxw = read(),maxv = read();
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read(),c = read();
        for(int j = maxw;j >= a;j --)
        {
            for(int k = maxv;k >= b;k --)
            {
                dp[j][k] = max(dp[j][k],dp[j - a][k - b] + c);
            }
        }
    }
    
    printf("%d",dp[maxw][maxv]);

    return 0;
}