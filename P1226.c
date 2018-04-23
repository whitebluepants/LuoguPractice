#include <stdio.h>
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
long long k;
long long pow(long long x,long long n)
{
    long long ans = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            ans = ans * x % k;
        }
        x = x * x % k;
        n >>= 1;
    }
    return ans % k;
}
int main()
{
    long long b = read(),p = read();k = read();
    printf("%lld^%lld mod %lld=%lld",b,p,k,pow(b,p));

    return 0;
}   