#include <algorithm>
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
int ans[100001];
int f[100001];
int a[100001];
int p[10001];
int main()
{
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        ans[a] = b;
        ans[b] = a;
    }
    int m = read();
    int j = 0;
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        p[i] = t;
        f[t] = 1;
    }
    for(int i = 0;i < m;i ++)
    {
        int aa = p[i];
        int bb = ans[aa];
        if(!f[bb])
        {
            a[j ++] = aa;
        }
    }
    printf("%d\n",j);
    sort(a,a + j);
    int flag = 0;
    for(int i = 0;i < j;i ++)
    {
        if(flag)
        {
            printf(" ");
        }
        printf("%05d",a[i]);
        flag = 1;
    }

    return 0;
}