#include <math.h>
#include <stdio.h>
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
int isprime(int x)
{
    if(x == 1 || x == 0)
    {
        return 0;
    }
    if(x == 2)
    {
        return 1;
    }
    for(int i = 2;i * i < x;i ++)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = read(),m = read();
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        if(isprime(t))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}