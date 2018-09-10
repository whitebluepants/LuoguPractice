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
int dp[30001];
int ans[30001];
int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }
    dp[1] = ans[1];
    int len = 1;
    for(int i = 2;i <= n;i ++)
    {
        if(ans[i] >= dp[len])
        {
            len ++;
            dp[len] = ans[i];
        }
        else
        {
            int l = 1, r = len;
            int mid = (l + r) / 2;
            while(l <= r)
            {
                if(dp[mid] <= ans[i])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
                mid = (l + r) / 2;
            }
            dp[l] = ans[i];
        }
    }

    printf("%d",n - len);

    return 0;
}