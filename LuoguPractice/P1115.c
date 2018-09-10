#include <stdio.h>
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();
    long long max = 0,ans = 0,t;
    for(int i = 0;i < n;i ++)
    {
        t = read();
        ans += t;
        if(ans > max)
        {
            max = ans;
        }
        if(ans < 0)
        {
            ans = 0;
        }
    }
    printf("%lld",max);

    return 0;
}