#include <stdio.h>
#include <math.h>
int main()
{
    long long sum = 0;
    int i = 0,a;
    while(scanf("%d",&a) != EOF)
    {
        i ++;
        sum += a;
    }
    printf("%lld",sum * (long long)pow(2,i - 1));

    return 0;
}