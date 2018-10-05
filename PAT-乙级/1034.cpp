#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
void out(long long a,long long b)
{
    long long temp = a;
    if(b < 0)
    {
        b = -b;
        a = -a;
        temp = a;
    }
    long long c = a / b;
    a = abs(a);
    long long d = a % b;
    long long e = gcd(d,b);

    if(c == 0)
    {
        if(d == 0)
        {
            printf("0");
        }
        else if(temp > 0)
        {
            printf("%d/%d",d/e,b/e);
        }
        else if(temp < 0)
        {
            printf("(-%d/%d)",d/e,b/e);
        }
    }
    else if(c > 0)
    {
        if(d == 0)
        {
            printf("%d",c);
        }
        else
        {
            printf("%d %d/%d",c,d/e,b/e);
        }
    }
    else
    {
        if(d == 0)
        {
            printf("(%d)",c);
        }
        else
        {
            printf("(%d %d/%d)",c,d/e,b/e);
        }
    }
}
int main()
{
    long long a1,b1,a2,b2;

    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);

    out(a1,b1);cout<<" + ";out(a2,b2);cout<<" = ";out(a1*b2+a2*b1,b1*b2);cout<<endl;
    out(a1,b1);cout<<" - ";out(a2,b2);cout<<" = ";out(a1*b2-a2*b1,b1*b2);cout<<endl;
    out(a1,b1);cout<<" * ";out(a2,b2);cout<<" = ";out(a1*a2,b1*b2);cout<<endl;
    out(a1,b1);cout<<" / ";out(a2,b2);cout<<" = ";
    if(a2==0) cout<<"Inf";
    else out(a1*b2,b1*a2);

    return 0;
}