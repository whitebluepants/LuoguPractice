#include <stdio.h>
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
int g[101];
int f[101];
int main()
{
    int n = read(),m = read();
    for(int i = 0;i < m;i ++)
    {
        g[i] = read();
    }
    for(int i = 0;i < m;i ++)
    {
        f[i] = read();
    }
    for(int i = 0;i < n;i ++)
    {
        int sum = 0;
        for(int j = 0;j < m;j ++)
        {
            int t = read();
            if(t == f[j])
            {
                sum += g[j];
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}