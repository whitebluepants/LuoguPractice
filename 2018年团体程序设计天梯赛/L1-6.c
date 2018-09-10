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
    char ch = getchar(), n = read();
    char s1[100][101] = {};
    char s2[100][101] = {};
    char s3[100][101] = {};

    for(int i = 0;i < n;i ++)
    {
        gets(s1[i]);
    }

    for(int i = 0,j = n - 1;i < n;i ++,j --)
    {
        for(int k = 0,l = n - 1;k < n;k ++,l --)
        {
            if(s1[j][l] == '@')
            {
                s2[i][k] = ch;
            }
            else
            {
                s2[i][k] = s1[j][l];
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(s2[i][j] == ch)
            {
                s3[i][j] = '@';
            }
            else
            {
                s3[i][j] = s2[i][j];
            }
        }
    }

    int flag = 0;
    for(int i = 0;i < n;i ++)
    {
        if(strcmp(s3[i],s1[i]) != 0)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("bu yong dao le\n");
    }
    for(int i = 0;i < n;i ++)
    {
        printf("%s\n",s2[i]);
    }

    return 0;
}
