#include <stdio.h>
int main()
{
    long long m = 1,n = 1,t;
    int k;
    scanf("%d",&k);
    
    for(;n + m < k;)
    {
        t = m + n;
        m = n;
        n = t;
    }
    printf("m=%lld\nn=%lld",m,n);
    return 0;
}