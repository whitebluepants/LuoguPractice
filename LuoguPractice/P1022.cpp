#include <stdio.h>
#include <string.h>
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
    char s[10001] = {};
    char t;
    int a1 = 0,b1 = 0,a2 = 0,b2 = 0,mid;
    scanf("%s",s);

    for(int i = 0;s[i] != 0;i ++)
    {
        if(s[i] == '=')
        {
            mid = i;
        }
        if(s[i] >= 97 && s[i] <= 122)
        {
            t = s[i];
        }
    }

    int tt = 0,flag = 0;
    for(int i = 0;i <= mid;i ++)
    {
        if(s[i] == '-' && i == 0)
        {
            flag = 1;
        }
        if(s[i] == '-' && i != 0)
        {
            if(s[i - 1] != t)
            {
                b1 += flag?tt*-1:tt;
            }
            else
            {
                if(i - 2 < 0 || !(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a1 += flag?tt*-1:tt;
            }
            tt = 0;
            flag = 1;
        }
        if(s[i] == '+')
        {
            if(s[i - 1] != t)
            {
                b1 += flag?tt*-1:tt;
            }
            else
            {
                if(i - 2 < 0 || !(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a1 += flag?tt*-1:tt;
            }
            tt = 0;
            flag = 0;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            tt = tt * 10 + s[i] - '0';
        }
        if(s[i] == '=')
        {
            if(s[i - 1] != t)
            {
                b1 += flag?tt*-1:tt;
            }
            else
            {
                if(i - 2 < 0 || !(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a1 += flag?tt*-1:tt;
            }
        }
    }

    tt = 0,flag = 0;
    int len = strlen(s);
    for(int i = mid;i <= len;i ++)
    {
        if(i == len)
        {
            if(s[i - 1] != t)
            {
                b2 += flag?tt*-1:tt;
            }
            else
            {
                if(!(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a2 += flag?tt*-1:tt;
            }
            break;
        }
        if(s[i] == '-' && i == mid)
        {
            flag = 1;
        }
        if(s[i] == '-' && i != mid)
        {
            if(s[i - 1] != t)
            {
                b2 += flag?tt*-1:tt;
            }
            else
            {
                if(!(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a2 += flag?tt*-1:tt;
            }
            tt = 0;
            flag = 1;
        }
        if(s[i] == '+')
        {
            if(s[i - 1] != t)
            {
                b2 += flag?tt*-1:tt;
            }
            else
            {
                if(!(s[i - 2] >= '0' && s[i - 2] <= '9'))
                {
                    tt = 1;
                }
                a2 += flag?tt*-1:tt;
            }
            tt = 0;
            flag = 0;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            tt = tt * 10 + s[i] - '0';
        }
    }
    double a = a1 - a2,b = b2 - b1;
    
    printf("%c=%.3f",t,(b / a) == -0?0:(b / a));

    return 0;
}