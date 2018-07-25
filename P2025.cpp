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
    int n = read();

    int count = 0,t,tt;
    for(int i = 0;i < n;i ++)
    {
        t = read();
        if(i == 0)
        {
            count = t;
        }
        else
        {
            if(t > tt)
            {
                count += (t - tt);
            }
        }
        tt = t;
    }
    printf("%d",count);

    return 0;
}