#include <stdio.h>
#include <string.h>
int main()
{
    char s[21],ss[21];
    char s1[11],s2[11];
    char t = '0';
    int len,flag = 0; // 如果有 /或者. 则flag = 1
    int p1;  // 用来记录,和/
    int zero = 0,f = 1,ff = 1; // 用来判断第一个数是否为0  
    gets(s);

    len = strlen(s) - 1;
    if(s[len] == '%')
    {
        int j = 0;
        for(int i = len - 1;i >= 0;i --)
        {
            if(s[i] != '0' && zero == 0)
            {
                ss[j] = s[i];
                zero = 1;
                j ++;
            }
            else if(zero == 1)
            {
                ss[j] = s[i];
                j ++;
            }
        }
        ss[j++] = '%';
        ss[j] = '\0';
        if(ss[0] == '%')
        {
            ss[0] = '0';
            ss[1] = '%';
            ss[2] = '\0';
        }
    }
    else
    {
        for(int i = 0;s[i] != '\0';i ++)
        {
            if(s[i] == '.' || s[i] == '/')
            {
                t = s[i];
                p1 = i;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            int j = 0;
            for(int i = len;i >= 0;i --)
            {
                if(s[i] != '0' && zero == 0)
                {
                    ss[j] = s[i];
                    zero = 1;
                    j ++;
                }
                else if(zero == 1)
                {
                    ss[j] = s[i];
                    j ++;
                }
            }
            ss[j] = '\0';
        }
        else
        {
            int i,j;
            for(i = 0,j = 0;i < p1;i ++)
            {
                s1[j] = s[i];
                j ++;
            }
            s1[j] = '\0';
            for(i = p1 + 1,j = 0;s[i] != '\0';i ++)
            {
                s2[j] = s[i];
                j ++;
            }
            s2[j] = '\0';

            int len1 = strlen(s1),len2 = strlen(s2);

            j = 0;
            // j是ss数组的下标
            for(int i = len1 - 1;i >= 0;i --)
            {
                if(s1[i] != '0' && zero == 0)
                {
                    ss[j] = s1[i];
                    zero = 1;
                    j ++;
                }
                else if(zero == 1)
                {
                    ss[j] = s1[i];
                    j ++;
                }
            }

            for(i = 0;s1[i] != '\0';i ++)
            {
                if(s1[i] != '0')
                {
                    ff = 0;
                }
            }
            if(ff == 1 && (t == '/' || t == '.'))
            {
                j = 0;
                ss[j ++] = '0';
            }
            ss[j ++] = t;
            zero = 0;
            for(i = 0;s2[i] != '\0';i ++)
            {
                if(s2[i] != '0')
                {
                    f = 0;
                    break;
                }
            }
            if(f == 1 && t == '.')
            {
                ss[j ++] = '0';
            }
            else
            {
                for(int i = len2 - 1;i >= 0;i --)
                {
                    if(s2[i] != '0' && zero == 0)
                    {
                        ss[j] = s2[i];
                        zero = 1;
                        j ++;
                    }
                    else if(zero == 1)
                    {
                        ss[j] = s2[i];
                        j ++;
                    }
                }
                if(t == '.')
                {
                    int len3 = strlen(ss);
                    for(int i = len3 - 1;i;i --)
                    {
                        if(ss[i] != '0')
                        {
                            ss[i + 1] = '\0';
                            break;
                        }
                    }
                }
            }
            ss[j] = '\0';
        }
    }
    int len4 = strlen(ss);
    if(len4 == 2 && t == '.')
    {
        ss[0] = '0';
        ss[1] = '.';
        ss[2] = '0';
        ss[3] = '\0';
    }
    else if(len4 == 0)
    {
        ss[0] = '0';
        ss[1] = '\0';
    }
    printf("%s",ss);
    return 0;
}
