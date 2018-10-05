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
int ans[10005];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    sort(ans,ans + n);

    double count = ans[0] * 1.0 / 2 + ans[1] * 1.0 / 2;

    for(int i = 2;i < n;i ++)
    {
        count = count / 2 + ans[i] * 1.0 / 2;
    }

    printf("%d",(int)count);

    return 0;
}