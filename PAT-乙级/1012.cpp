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
int main()
{
    int a1 = 0,a2 = 0,flag2 = 1,f2 = 0,a3 = 0,cnt4 = 0,a5 = 0;
    double a4 = 0;

    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        int t = read();
        if(t % 5 == 0 && t % 2 == 0)
        {
            a1 += t;
        }
        if(t % 5 == 1)
        {
            f2 = 1;
            a2 += t * flag2;
            flag2 *= -1;
        }
        if(t % 5 == 2)
        {
            a3 ++;
        }
        if(t % 5 == 3)
        {
            a4 += t;
            cnt4 ++;
        }
        if(t % 5 == 4)
        {
            if(t > a5)
            {
                a5 = t;
            }
        }
    }
    
    if(a1)
    {
        printf("%d",a1);
    }
    else
    {
        printf("N");
    }
    if(f2)
    {
        printf(" %d",a2);
    }
    else
    {
        printf(" N");
    }
    if(a3)
    {
        printf(" %d",a3);
    }
    else
    {
        printf(" N");
    }
    if(a4)
    {
        printf(" %.1f",a4 / cnt4);
    }
    else
    {
        printf(" N");
    }
    if(a5)
    {
        printf(" %d",a5);
    }
    else
    {
        printf(" N");
    }

    return 0;
}