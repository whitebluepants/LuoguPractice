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
int ans[37];
int main()
{
    int n = read(),count = 0;;
    for(int i = 0;i < n;i ++)
    {
        int sum = 0;
        int t = read();
        while(t > 0)
        {
            int temp = t % 10;
            t /= 10;
            sum += temp;
        }
        if(ans[sum] == 0)
        {
            count ++;
            ans[sum] = 1;
        }
    }
    int flag = 0;
    printf("%d\n",count);
    for(int i = 0;i < 37;i ++)
    {
        if(ans[i] == 1)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%d",i);
            flag = 1;
        }
    }

    return 0;
}