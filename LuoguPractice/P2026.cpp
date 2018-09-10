#include <stdio.h>
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
int ggcd(int a,int b)
{
    return b == 0?a:ggcd(b,a % b);
}
int main()
{
    int x1 = read(),y1 = read(),x2 = read(),y2 = read();
    int y = y1 - y2 , x = x1 - x2;
    int flag = 0,f = 1;
    double k;

    if(abs(y) > abs(x) && y % x == 0)
    {
        k = 1.0 * y / x;
    }
    else
    {
        flag = 1;
        int gcd = ggcd(y,x);
        y /= gcd;
        x /= gcd;
        if(y < 0)
        {
            f *= -1;
        }
        if(x < 0)
        {
            f *= -1;
        }
        k = 1.0 * y / x;
    }
    double c;
    c = y1 - (k * x1);
    
    printf("y=");
    if(flag == 0)
    {
        printf("%dx",(int)k);
    }
    else
    {
        if(f == -1)printf("-");
        printf("%d/%d*x",abs(y),abs(x));
    }
    
    if(c == 0)
    {
        return 0;
    }
    printf("%c",c > 0?'+':'-');
    if(c == 0.5 || c == -0.5)
    {
        printf("1/2");
    }
    else
    {
        printf("%d",(int)c);
    }

    return 0;
}