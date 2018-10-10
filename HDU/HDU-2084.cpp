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
        int m = read();
        int dp[101][101] = {};
        for(int j = 1;j <= m;j ++)
        {
            for(int k = 1;k <= j;k ++)
            {
                dp[j][k] = read();
            }
        }
        for(int j = m - 1;j >= 1;j --)
        {
            for(int k = 1;k <= j;k ++)
            {
                dp[j][k] = max(dp[j][k] + dp[j + 1][k],dp[j][k] + dp[j + 1][k + 1]);
            }
        }
        printf("%d\n",dp[1][1]);
    }

    return 0;
}