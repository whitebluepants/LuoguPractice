#include <stdio.h>
#include <string.h>
int main()
{
    char a = '0',b = '0',c = '0',o;
    char s[256];
    scanf("%s",s);
    int t = 0,n = 0,len = strlen(s);
    for(int i = 0;i < len;i ++)
    {
        if(i == 0 || s[i - 1] == ';')
        {
            switch(s[i])
            {
                case 'a': t = 1; break;
                case 'b': t = 2; break;
                case 'c': t = 3;
            }
        }
        if(s[i] == '=')
        {
            switch(s[i + 1])
            {
                case 'a': n = 1; break;
                case 'b': n = 2; break;
                case 'c': n = 3; break;
                default: o = s[i + 1];
            }

            switch(t)
            {
                case 1:
                    if(n != 0)
                    {
                        switch(n)
                        {
                            case 1: a = a; break;
                            case 2: a = b; break;
                            case 3: a = c;
                        }
                    }
                    else
                    {
                        a = o;
                    }
                    break;
                case 2:
                    if(n != 0)
                    {
                        switch(n)
                        {
                            case 1: b = a; break;
                            case 2: b = b; break;
                            case 3: b = c;
                        }
                    }
                    else
                    {
                        b = o;
                    }
                    break;
                case 3:
                    if(n != 0)
                    {
                        switch(n)
                        {
                            case 1: c = a; break;
                            case 2: c = b; break;
                            case 3: c = c;
                        }
                    }
                    else
                    {
                        c = o;
                    }
            }
            n = 0;
        }
    }
    printf("%c %c %c",a,b,c);

    return 0;
}