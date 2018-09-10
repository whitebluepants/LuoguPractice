#include <stdio.h>
int main()
{
    int f = 0, z = 0,n,t;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&t);
        if(t == 5)
        {
            f ++;
        }
        else
        {
            z ++;
        }
    }
    if(z == 0)
    {
        printf("-1");
    }
    else
    {
        f /= 9;
        f *= 9;
        for(int i = 0;i < f;i ++)
        {
            printf("5");
        }
        if(f == 0)
        {
            printf("0");
            return 0;
        }
        for(int i = 0;i < z;i ++)
        {
            printf("0");
        }
    }
    return 0;
}