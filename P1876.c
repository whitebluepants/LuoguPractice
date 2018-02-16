#include <stdio.h>
#include <math.h>
int main()
{
    long long n;
    scanf("%lld",&n);

    for(int i = 1;i <= sqrt(n);i ++)
    {
        printf("%d ",i * i);
    }
    return 0;
}