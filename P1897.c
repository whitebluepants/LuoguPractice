#include <stdio.h>
#include <stdbool.h>
int a[100000000] = {};
int read()
{
    char ch = getchar();
    bool f = false;
    int x = 0;

    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = true;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f?-1*x:x;
}
int main()
{
    long long sum = 0;
    int n,t,max = 0;
    n = read();
    
    for(int i = 0;i < n;i ++)
    {
        t = read();
        if(a[t] == 0)
        {
            sum += 5;
        }
        a[t] ++;
        sum ++;
        if(t > max)
        {
            max = t;
        }
    }
    sum += 10 * max;
    printf("%lld",sum);
    return 0;
}  