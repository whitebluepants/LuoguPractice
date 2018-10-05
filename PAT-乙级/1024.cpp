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
char s[10010];
int main()
{
    scanf("%s",s);

    int f1 = 1,f2 = 1,numlen = 0,e = 0;
    
    if(s[0] == '-')
    {
        f1 = -1;
    }

    int i;
    for(i = 1;s[i] != 'E';i ++)
    {
        if(s[i] != '.')
        {
            numlen ++;
        }
    }
    if(s[i + 1] == '-')
    {
        f2 = -1;
    }
    for(int j = i + 2;s[j] != '\0';j ++)
    {
        e = e * 10 + s[j] - '0';
    }
    
    if(f2 == 1)
    {
        if(f1 == -1)
        {
            printf("-");
        }
        if(numlen - 1 > e)
        {
            int cnt = 0;
            for(int i = 1;s[i] != 'E';i ++)
            {
                if(s[i] != '.')
                {
                    printf("%c",s[i]);
                    cnt ++;
                }
                if(cnt == e + 1)
                {
                    printf(".");
                }
            }
        }
        else
        {
            for(int i = 1;s[i] != 'E';i ++)
            {
                if(s[i] != '.')
                {
                    printf("%c",s[i]);
                }
            }
            for(int i = 0;i < e - (numlen - 1);i ++)
            {
                printf("0");   
            }
        }
    }
    else
    {
        if(f1 == -1)
        {
            printf("-");
        }
        
        for(int i = 0;i < e;i ++)
        {
            printf("0");
            if(i == 0)
            {
                printf(".");
            }
        }
        for(int i = 1;s[i] != 'E';i ++)
        {
            if(s[i] != '.')
            {
                printf("%c",s[i]);
            }
            if(e == 0)
            {
                if(i == 1)
                {
                    printf(".");
                }
            }
        }
    }
    
    return 0;
}