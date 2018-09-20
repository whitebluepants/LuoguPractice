#include <stdio.h>
#define INF 99999999
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();
    int ans = 0,Max = -INF,flag = 0;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        ans += t;
        if(t >= 0)
        {
            flag = 1;
        }
        if(ans > Max)
        {
            Max = ans;
        }
        if(ans < 0)
        {
            ans = 0;
        }
    }
    if(flag == 0)
    {
        Max = 0;
    }
    printf("%d",Max);

    return 0;
}