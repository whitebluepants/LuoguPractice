#include <stdio.h>
#include <math.h>
int prime(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    for(int i = 2;i <= sqrt(n);i ++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n,t;
    int a[10001] = {};
    scanf("%d",&n);

    for(int i = 2;i <= n;i ++)
    {
        t = i;
        if(prime(t))
        {
            a[t] ++;
        }
        else
        {
            while(!prime(t))
            {
                for(int j = 2;j <= t / 2;j ++)
                {
                    if(t % j == 0)
                    {
                        a[j] ++;
                        t = t / j;
                        j = 1;  // wa后新添加 没有这个 16将会产生为4的质因数 不符合
                    }
                }
            }
            a[t] ++;
        }
    }
    for(int i = 2;i <= n;i ++)
    {
        if(a[i] != 0)
        {
            printf("%d %d\n",i,a[i]);
        }
    }
    return 0;
}