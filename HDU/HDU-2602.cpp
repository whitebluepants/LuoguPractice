#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int m = read(),v = read();
        int dp[1001] = {};
        int a1[1001] = {};
        for(int j = 0;j < m;j ++)
        {
            a1[j] = read();
        }
        int b1[1001] = {};
        for(int j = 0;j < m;j ++)
        {
            b1[j] = read();
        }

        for(int j = 0;j < m;j ++)
        {
            for(int k = v;k >= b1[j];k --)
            {
                dp[k] = max(dp[k],dp[k - b1[j]] + a1[j]);
            }
        }
        printf("%d\n",dp[v]);
    }

    return 0;
}