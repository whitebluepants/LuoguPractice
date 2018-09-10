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
long long gcd(long long a,long long b)
{
    return b == 0?a:gcd(b,a%b);
}
int main()
{
    long long a = read(),b = read(),c = read();
    long long temp = gcd(a,b);
    long long t = a * b / temp;
    printf("%lld",c * t / gcd(c,t));
    return 0;
}