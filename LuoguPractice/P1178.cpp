#include <stdio.h>
#include <algorithm>
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
int anss[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int day(int a,int b)
{
    int d = b;
    a --;
    for(int i = a;i >= 1;i --)
    {
        d += anss[i];
    }
    return d;
}
int main()
{
    int n = read();
    int ans[367] = {};

    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        ans[day(a,b)] = 1;
    }
    
    int count = 0,maxx = -1;
    for(int i = 1;i <= 366;i ++)
    {
        if(ans[i] == 1)
        {
            count = 0;
        }
        else
        {
            count ++;
        }
        if(count > maxx)
        {
            maxx = count;
        }
    }

    double minus = 1.0*maxx / 366 * 24 * 60 * 60;

    printf("%d",(int)(minus + 0.5));

    return 0;
}