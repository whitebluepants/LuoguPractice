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
int isprime(int t)
{
    if(t == 1)
    {
        return 0;
    }
    if(t == 2)
    {
        return 1;
    }
    for(int i = 2;i <= sqrt(t);i ++)
    {
        if(t % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = read(),k = read();
    int count = 0;

    for(int i = 1;i <= n - k;i ++)
    {
        if(isprime(i))
        {
            if(isprime(i + k))
            {
                printf("%d %d\n",i,i + k);
                count = 1;
            }
        }
    }
    if(count == 0)
    {
        printf("empty");
    }
    return 0;
}