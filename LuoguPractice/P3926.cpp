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
    long long a = read(),c = read(),p = read(),q = read(),r = read(),x = read();
    
    while(a < c)
    {
        if(x < p)
        {
            printf("%lld",a);
            return 0;
        }
        x -= p;
        a ++;
    }
    if(x <= q)
    {
        printf("%lld",a);
        return 0;
    }
    else if(a == c)
    {
        x -= q;
    }
    
    while(x >= r)
    {
        a ++;
        x -= r;
    }
    printf("%lld",a);

    return 0;
}