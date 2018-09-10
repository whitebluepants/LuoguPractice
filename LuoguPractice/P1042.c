#include <stdlib.h>
#include <math.h>
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
    char s[2500][21] = {};
    int i = 0;
    while(scanf("%s",s[i ++]) != EOF)
    {
    }
    
    int a = 0,b = 0,flag = 0;
    for(int j = 0;j < i;j ++)
    {
        for(int k = 0;s[j][k] != '\0';k ++)
        {
            if(s[j][k] == 'E')
            {
                flag = 1;
                break;
            }
            if(s[j][k] == 'W')
            {
                a ++;
            }
            else if(s[j][k] == 'L')
            {
                b ++;
            }
    
            if(abs(a - b) >= 2 && (a >= 11 || b >= 11) )
            {
                printf("%d:%d\n",a,b);
                a = 0,b = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    printf("%d:%d\n\n",a,b);

    a = 0,b = 0,flag = 0;
    for(int j = 0;j < i;j ++)
    {
        for(int k = 0;s[j][k] != '\0';k ++)
        {
            if(s[j][k] == 'E')
            {
                flag = 1;
                break;
            }
            if(s[j][k] == 'W')
            {
                a ++;
            }
            else if(s[j][k] == 'L')
            {
                b ++;
            }
            if(abs(a - b) >= 2 && (a >= 21 || b >= 21) )
            {
                printf("%d:%d\n",a,b);
                a = 0, b = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    printf("%d:%d",a,b);
    
    return 0;
}