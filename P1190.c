#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-1*x;
}
int main()
{
    int n = read(),m = read();
    int a[10000] = {};
    int w[100] = {};
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }

    int j;
    for(j = 0;j < m;j ++)
    {
        w[j] = a[j];
    }

    while(j != n)
    {
        int temp = w[0],t = 0;
        for(int i = 1;i < m;i ++)
        {
            if(w[i] < temp)
            {
                temp = w[i];
                t = i;
            }
        }
        w[t] += a[j ++];
    }
    int max = 0;
    for(int i = 0;i < m;i ++)
    {
        if(w[i] > max)
        {
            max = w[i];
        }
    }
    printf("%d",max);

    return 0;
}