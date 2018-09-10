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
int main()
{
    int p1 = read(),p2 = read(),p3 = read();
    char s1[103] = {},s2[10001] = {};
    scanf("%s",s1);
    int j = 0;
    int len = strlen(s1);
    
    for(int i = 0;s1[i] != '\0';i ++)
    {
        if( (i == 0 && s1[i] == '-') || (i == len - 1 && s1[i] == '-'))
        {
            s2[j ++] = '-';
            continue;
        }
        if(i - 1 == 0 && s1[i - 1] == '-' && s1[i] == '-')
        {
            s2[j ++] = '-';
            continue;
        }
        if(s1[i] == '-' && s1[i + 1] == '-')
        {
            s2[j ++] = '-';
            continue;
        }
        
        if(s1[i] == '-')
        {
            continue;
        }
        s2[j ++] = s1[i];
        if(s1[i + 1] != '-')
        {
            continue;
        }
        
        if(s1[i + 2] == '\0')
        {
            continue;   
        }
        
        if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i + 2] >= '0' && s1[i + 2] <= '9')
        {
            s2[j ++] = '-';
            continue;
        }
        if(s1[i] >= '0' && s1[i] <= '9' && s1[i + 2] >= 'a' && s1[i + 2] <= 'z')
        {
            s2[j ++] = '-';
            continue;
        }
        if(s1[i + 2] == s1[i] + 1)
        {
            continue;
        }
        if(s1[i + 2] <= s1[i])
        {
            s2[j ++] = '-';
            continue;
        }
        
        char t = s1[i] + 1;
        
        if(p1 == 2)
        {
            if(s1[i] >= 'a' && s1[i] <= 'z')
            {
                t -= 32;
            }
        }
        
        if(p3 == 1)
        {
            int end = s1[i + 2] - 1;
            if(p1 == 2 && s1[i] >= 'a' && s1[i] <= 'z')
            {
                end -= 32;
            }
            for(char temp = t;temp <= end;temp ++)
            {
                for(int k = 1;k <= p2;k ++)
                {
                    if(p1 == 3)
                    {
                        s2[j ++] = '*';
                    }
                    else
                    {
                        s2[j ++] = temp;    
                    }
               }
            }    
        }
        else
        {
            int end = s1[i] + 1;
            if(p1 == 2 && s1[i] >= 'a' && s1[i] <= 'z')
            {
                end -= 32;
            }
            t += s1[i + 2] - s1[i];
            t -= 2;
            for(char temp = t;temp >= end;temp --)
            {
                for(int k = 1;k <= p2;k ++)
                {
                    if(p1 == 3)
                    {
                        s2[j ++] = '*';
                    }
                    else
                    {
                        s2[j ++] = temp;
                    }
                }
            }
        }
    }

    printf("%s",s2);
    return 0;
}