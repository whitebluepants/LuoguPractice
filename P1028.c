#include <stdio.h>
int a[10001];
long long calcu(int n);

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
    {
        a[i] = -1;
    }
    a[1] = 1;
    printf("%lld",calcu(n));
    
    return 0;
}

long long calcu(int n)
{
    if(a[n] != -1)
    {
        return a[n];
    }
    long long count = 1;
    for(int i = 1;i <= (n / 2);i ++)
    {
        count += calcu(i);
    }
    a[n] = count;
    return count;
}
