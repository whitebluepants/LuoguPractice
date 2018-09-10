#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return f?x:x*-1;
}
int ans[200000];
int main()
{
    int n = read(),t = read();
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    long long count = ans[0];

    int t = ans[0];
    for(int i = 1;i < n;i ++)
    {
        if(ans[i - 1] + t <= ans[i])
        {
            count += t;
        }
        else
        {
            int temp = ans[i - 1] + t - ans[i];
            count += t;
            count -= temp;
        }
    }
    printf("%lld",count);

    return 0;
}