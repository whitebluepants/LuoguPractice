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
int ans[500001];
int flag[10000000];
int main()
{
    int t = read();
    int maxcnt = 1;
    ans[0] = 0;
    flag[0] = 1;

    for(int i = 1;i <= 500000;i ++)
    {
        int temp = ans[i - 1] - i;
        if(temp > 0 && flag[temp] == 0)
        {
            ;
        }
        else
        {
            temp += 2 * i;
        }
        ans[i] = temp;
        flag[temp] = 1;
    }

    while(t != -1)
    {
        printf("%d\n",ans[t]);
        t = read();
    }
    
    return 0;
}