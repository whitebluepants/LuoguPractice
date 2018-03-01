#include <stdio.h>
int main()
{
    int n,a,b,u = 0,sum = 0;

    scanf("%d",&n);
    while(n > 0)
    {
        scanf("%d %d",&a,&b);
        u = a + b + u - 8;
        sum += u;

        n --;
    }
    printf("%d",sum);

    return 0;
}