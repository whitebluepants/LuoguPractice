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
    int n = read();
    int dp[101] = {};
    int dp1[101] = {};
    int dp2[101] = {};
    int ans[101] = {};
    
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    for(int i = 0;i < n;i ++)
    {
        dp1[i] = 1;
        for(int j = 0;j < i;j ++)
        {
            if(ans[j] < ans[i])
            {  
                dp1[i] = max(dp1[i],dp1[j] + 1);
            }
        }
        
        for(int j = n - 1;j >= i;j --)
        {
            dp2[j] = 1;
            for(int k = n - 1;k > j;k --)
            {
                if(ans[j] > ans[k])
                {
                    dp2[j] = max(dp2[j],dp2[k] + 1);
                }
            }
        }
        dp[i] = dp1[i] + dp2[i] - 1;
    }
    
    int minn = 99999999;
    for(int i = 0;i < n;i ++)
    {
        if(n - dp[i] < minn)
        {
            minn = n - dp[i];
        }
    }
    printf("%d",minn);

    return 0;
}