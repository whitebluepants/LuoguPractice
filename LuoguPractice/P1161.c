#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int ans[2000000] = {};
int main()
{
    int n = read();
    double f;
    int t;

    for(int i = 0;i < n;i ++)
    {
        scanf("%lf %d",&f,&t);
        for(int j = 1;j <= t;j ++)
        {
            ans[(int)f * j] ^= 1;
        }
    }
    for(int i = 0;i < 2000000;i ++)
    {
        if(ans[i] == 1)
        {
            printf("%d",i);
            return 0;
        }
    }
}