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
    long long a,b,c = 0,d = 0,da,db;

    a = read(),da = read(),b = read(),db = read();

    while(a > 0)
    {
        int temp = a % 10;
        a /= 10;
        if(da == temp)
        {
            c = c * 10 + temp;
        }
    }
    while(b > 0)
    {
        int temp = b % 10;
        b /= 10;
        if(db == temp)
        {
            d = d * 10 + temp;
        }
    }
    printf("%lld",c + d);

    return 0;
}