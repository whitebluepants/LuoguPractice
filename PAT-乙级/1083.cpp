#include <stdio.h>
#include <stdlib.h>
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
int ans[10005];
int main()
{
    int n = read();
    int max = -1;
    for(int i = 1;i <= n;i ++)
    {
        int t = read();
        if(t >= i)
        {
            ans[t - i] ++;
        }
        else
        {
            ans[i - t] ++;
        }
        if(abs(t - i) > max)
        {
            max = abs(t - i);
        }
    }

    for(int i = max;i >= 0;i --)
    {
        if(ans[i] > 1)
        {
            printf("%d %d\n",i,ans[i]);
        }
    }

    return 0;
}