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
int isprime(int n)
{
    if(n == 1)
    {
        return 0;
    }
    for(int i = 2;i <= sqrt(n);i ++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = read();

    for(int i = 1;i <= sqrt(n);i ++)
    {
        if(isprime(i))
        {
            for(int j = i;j <= sqrt(n);j ++)
            {
                if(isprime(j))
                {
                    if(isprime(n - i - j))
                    {
                        printf("%d %d %d",i,j,n - i - j);
                        return 0;
                    }
                }
            }
        }
    }
}