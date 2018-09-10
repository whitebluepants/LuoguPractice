#include <stdio.h>
#include <string.h>
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
char s[5001];
int ans[4] = {};
int main()
{
    scanf("%s",s);
    int t = read();
    int len = strlen(s);
    
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'N')
        {
            ans[3] ++;
        }
        if(s[i] == 'W')
        {
            ans[2] --;
        }
        if(s[i] == 'E')
        {
            ans[0] ++;
        }
        if(s[i] == 'S')
        {
            ans[1] --;
        }
    }
    long long x = 0,y = 0;
    if(t <= len)
    {
        for(int i = 0;i < t;i ++)
        {
            if(s[i] == 'N')
            {
                y ++;
            }
            if(s[i] == 'E')
            {
                x ++;
            }
            if(s[i] == 'S')
            {
                y --;
            }
            if(s[i] == 'W')
            {
                x --;
            }
        }
    }
    else
    {
        x = ans[0] + ans[2];
        y = ans[1] + ans[3];

        if(t % len == 0)
        {
            x *= t / len;
            y *= t / len;    
        }
        else
        {
            x *= t / len;
            y *= t / len;
            int temp = t % len;
            for(int i = 0;i < temp;i ++)
            {
                if(s[i] == 'N')
                {
                    y ++;
                }
                if(s[i] == 'E')
                {
                    x ++;
                }
                if(s[i] == 'S')
                {
                    y --;
                }
                if(s[i] == 'W')
                {
                    x --;
                }
            }
        }
    }

    printf("%lld %lld",x,y);

    return 0;
}