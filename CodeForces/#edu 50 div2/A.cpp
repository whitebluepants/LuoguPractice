#include <stdio.h>
using namespace std;
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    long long n = read(),m = read();
    if(n >= m)
    {
        printf("1");
    }
    else
    {
        long long t = m % n;
        long long h = m / n;
        printf("%I64d",t == 0?h:h + 1);
    }

    return 0;
}