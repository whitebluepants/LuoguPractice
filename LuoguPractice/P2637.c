#include <stdio.h>

int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = 0;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f?x:x*-1;
}

int main()
{
    int n,m,price,total = 0,p,price2;
    int t[1001] = {};
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i ++)
    {
        scanf("%d",&t[i]);
    }
    for(int i = 0;i < m;i ++)
    {
        price = t[i];
        p = 0;

        for(int j = 0;j < m;j ++)
        {
            if(t[j] >= price)
            {
                p ++;
            }
        }

        p = p>n?n:p;

        if(p * price > total)
        {
            total = p * price;
            price2 = price;
        }
    }

    printf("%d %d",price2,total);

    return 0;
}