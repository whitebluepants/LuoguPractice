#include <string.h>
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
    char s[101] = {};

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        int len = strlen(s);
        int a = 0,b = 0,c = 0;
        int p = 0,t = 0;
        int f1 = 0,f2 = 0,flag = 0;
        for(int j = 0;j < len;j ++)
        {
            if(s[j] != 'A' && s[j] != 'P' && s[j] != 'T')
            {
                flag = 1;
                break;
            }
            if(s[j] == 'P')
            {
                f1 = 1;
                p ++;
            }
            if(s[j] == 'T')
            {
                f2 = 1;
                t ++;
            }
            if(s[j] == 'A')
            {
                if(!f1)
                {
                    a ++;
                }
                else if(!f2)
                {
                    b ++;
                }
                else 
                {
                    c ++;
                }
            }
        }
        if(flag == 1 || p != 1 || t != 1 || b == 0 || len == 0)
        {
            printf("NO\n");
            continue;
        }

        if(a * b == c)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}