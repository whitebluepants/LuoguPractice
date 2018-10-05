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
int ans[501][501];
int main()
{
    int n = read(),m = read(),a = read(),b = read(),k = read();

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            ans[i][j] = read();
            if(ans[i][j] >= a && ans[i][j] <= b)
            {
                ans[i][j] = k;
            }
        }
    }
    for(int i = 0;i < n;i ++)
    {
        int flag = 0;
        for(int j = 0;j < m;j ++)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%03d",ans[i][j]);
            flag = 1;
        }
        printf("\n");
    }

    return 0;
}