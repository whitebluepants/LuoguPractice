#include <stdio.h>
int main()
{
    long long sum = 1;
    int x,n;
    scanf("%d %d",&x,&n);
    for(int i = 0;i < n;i ++)
    {
        sum += x * sum;
    }
    printf("%lld",sum);

    return 0;
}
