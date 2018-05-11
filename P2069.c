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
int n,m;
void deletee(int a[],int i)
{
    for(int j = i;j <= n - 1;j ++)
    {
        a[j] = a[j + 1];
    }
    n--;
}
int main()
{
    n = read(),m = read();
    int ans[205] = {};
    for(int i = 1;i <= n;i ++)
    {
        ans[i] = i;
    }

    int f = 1,flag = 1;
    for(int i = 1;i <= m;i ++)
    {
        int temp = (i * i * i) % 5 + 1;
        f += temp;
        if(f > n)
        {
            f = 1;
            f += temp;
        }
        flag = ans[f];
        deletee(ans,f);
    }

    printf("%d",flag);

    return 0;
}