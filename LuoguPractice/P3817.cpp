#include <stdio.h>
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
    int n = read(),x = read();
    int ans[100000] = {};
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    long long count = 0;
    for(int i = 0;i < n - 1;i ++)
    {
        if(ans[i] + ans[i + 1] > x)
        {
            long long t = ans[i] + ans[i + 1] - x;
            if(ans[i + 1] >= t)
            {
                ans[i + 1] -= t;
            }
            else
            {
                ans[i + 1] = 0;
            }
            count += t;
        }
    }
    printf("%lld",count);

    return 0;
}