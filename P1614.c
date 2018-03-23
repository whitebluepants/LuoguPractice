#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read(),m = read();
    int ans[3000] = {};
    int sum = 0,max = 99999999;
    for(int i = 0;i < n;++ i)
    {
        ans[i] = read();
    }

    for(int i = 0;i + m - 1 < n;++ i)
    {
        sum = ans[i];
        for(int j = i + 1,t = 0;j < n && t != m - 1;++ j,++ t)
        {
            sum += ans[j];
        }
        if(sum < max)
        {
            max = sum;
        }
    }
    printf("%d",max);

    return 0;
}