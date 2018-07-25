#include <stdio.h>
#include <math.h>
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
int main()
{
    int n = read();
    long long fib = 0;

    if(n == 1)
    {
        fib = 1;
    }
    else if(n == 2)
    {
        fib = 1;
    }
    else
    {
        int t1 = 1,t2 = 1;
        for(int i = 3;i <= n;i ++)
        {
            fib = t1 + t2;
            t1 = t2;
            t2 = fib;
        }
    }
    fib %= 2147483647;
    printf("%lld=",fib);
    
    int flag = 1;
    while(fib > 1)
    {
        int f = 0;
        for(int i = 2;i <= sqrt(fib);i ++)
        {
            if(fib % i == 0)
            {
                f = 1;
                if(flag == 1)
                {
                    printf("%d",i);
                    flag = 0;
                }
                else
                {
                    printf("*%d",i);
                }
                fib /= i;
                break;
            }
        }
        if(f == 0)
        {
            if(flag == 0)
            {
                printf("*");
            }
            printf("%lld",fib);
            break;
        }
    }
    
    return 0;
}