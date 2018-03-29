#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read(),t,temp,flag = 0;
    int ans[1000] = {};
    for(int i = 0;i < n;i ++)
    {
        t = read();
        if(i == 0)
        {
            temp = t;
        }
        else
        {
            if(abs(t - temp) > 1000 || ++ ans[abs(t - temp)] > 1)
            {
                flag = 1;
                break;
            }
            temp = t;
        }
    }
    if(flag == 1)
    {
        printf("Not jolly");
    }
    else
    {
        printf("Jolly");
    }

    return 0;
}