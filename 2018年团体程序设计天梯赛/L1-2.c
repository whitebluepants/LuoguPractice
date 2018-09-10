#include <stdio.h>
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
    int n = read(), m = read();

    char s[1000000] = {};
    for(int i = 0;i < n;i ++)
    {
        s[i] = 'z';
    }

    for(int i = 1;i < m;i ++)
    {
        s[n - 1] --;
        if(n - 2 >= 0 && s[n - 1] < 97)
        {
            s[n - 1] = 'z';
            s[n - 2] --;
            
            if(n - 3 >= 0 && s[n - 2] < 97)
            {
                s[n - 2] = 'z';
                s[n - 3] --;
                
                if(n - 4 >= 0 && s[n - 3] < 97)
                {
                    s[n - 3] = 'z';
                    s[n - 4] --;

                    if(n - 5 >= 0 && s[n - 4] < 97)
                    {
                        s[n - 4] = 'z';
                        s[n - 5] --;
                    }
                }
            }
        }
    }
    printf("%s",s);

    return 0;
}