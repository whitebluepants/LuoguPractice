#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
int ans[101];
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }

    for(int i = 1;i < n;i ++)
    {
        for(int j = i + 1;j <= n;j ++)
        {
            vector<int> a(n + 1,1);
            int b[105] = {};
            int cnt = 0;
            a[i] = a[j] = -1;
            
            for(int k = 1;k <= n;k ++)
            {
                if(ans[k] * a[abs(ans[k])] < 0)
                {
                    b[cnt ++] = k;
                }
            }
            if(cnt == 2 && a[b[0]] + a[b[1]] == 0)
            {
                printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");

    return 0;
}