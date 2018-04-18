#include <stdio.h>
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
    int n = read();
    int t,index = n;
    for(int i = 0;i <= n;i ++,index --)
    {
        t = read();
        if(t == 0)
        {
            continue;
        }
        if(index == 0)
        {
            if(t > 0)
            {
                printf("+");
            }
            printf("%d",t);
            break;
        }

        if(i != 0 && t > 0)
        {
            if(t != 1)
            {
                printf("+%d",t);
            }
            else
            {
                printf("+");
            }
        }
        else if(t > 0)
        {
            if(t != 1)
            {
                printf("%d",t);
            }
        }

        if(t < 0 && t != -1)
        {
            printf("%d",t);
        }
        else if(t == -1)
        {
            printf("-");
        }

        if(index != 1)
        {
            printf("x^%d",index);
        }
        else
        {
            printf("x");
        }
    }
    return 0;
}