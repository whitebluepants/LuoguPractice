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
    int n,a,b;
    scanf("%d",&n);

    for(int i = 4;i <= n;i += 2)
    {
        for(int j = 2;j <= i / 2;j ++)
        {
            if(prime(j))
            {
                if(prime(i - j))
                {
                    printf("%d=%d+%d\n",i,j,i - j);
                    break;
                }
            }
        }
    }
    return 0;
}