#include <stdio.h>
#include <algorithm>
#include <string.h>
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
long long flag[21][21][21];
long long cal(int a,int b,int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if(a > 20 || b > 20 || c > 20)
    {
        if(flag[20][20][20])
        {
            return flag[20][20][20];
        }
        else
        {
            return cal(20,20,20);
        }
    }
    if(a < b && b < c)
    {
        if(flag[a][b][c])
        {
            return flag[a][b][c];
        }
        else
        {
            return flag[a][b][c] = cal(a,b,c - 1) + cal(a,b - 1,c - 1) - cal(a,b - 1,c);
        }
    }
    else
    {
        if(flag[a][b][c])
        {
            return flag[a][b][c];
        }
        else
        {
            return flag[a][b][c] = cal(a - 1,b,c) + cal(a - 1,b - 1,c) + cal(a - 1,b,c - 1) - cal(a - 1,b - 1,c - 1);
        }
    }
}
int main()
{
    int a,b,c;

    while(scanf("%d %d %d",&a,&b,&c) && !(a == -1 && b == -1 && c == -1))
    {
        long long ans = cal(a,b,c);

        printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
    }

    return 0;
}