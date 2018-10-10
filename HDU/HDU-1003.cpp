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
        printf("Case %d:\n",i + 1);
        int m = read();
        // 最大值初始化应该小于-1000
        int Max = -9999,sum = 0,left = 1,right = 1;
        int l = 1;
        for(int j = 0;j < m;j ++)
        {
            int t = read();
            sum += t;

            if(sum > Max)
            {
                Max = sum;
                right = j + 1;
                left = l;
            }
            if(sum < 0)
            {
                l = j + 2;
                sum = 0;
            }
        }
        printf("%d %d %d\n",Max,left,right);
        if(i < n - 1)
        {
            printf("\n");
        }
    }

    return 0;
}