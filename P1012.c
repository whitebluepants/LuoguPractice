#include <stdio.h>
#include <string.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
void qsort(char s[][200],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    char temp[200];
    strcpy(temp,s[(begin + end) / 2]);
    while(i <= j)
    {
        while(strcmp(s[i],temp) > 0)
        {
            i ++;
        }
        while(strcmp(s[j],temp) < 0)
        {
            j --;
        }
        if(i <= j)
        {
            char t[200];
            strcpy(t,s[i]);
            strcpy(s[i],s[j]);
            strcpy(s[j],t);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort(s,begin,j);
    }
    if(end > i)
    {
        qsort(s,i,end);
    }
}
int main()
{
    int n = read();
    char s[20][200] = {};

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    qsort(s,0,n - 1);
    for(int i = 0;i < n;i ++)
    {
        for(int j = i;j < n;j ++)
        {
            int len1 = strlen(s[j]);
            int len2 = strlen(s[j + 1]);
            if(len1 - len2 == 1 && strstr(s[j],s[j + 1]) != NULL)
            {
                if(s[j][len1 - 1] < s[j + 1][0])
                {
                    char t[200];
                    strcpy(t,s[j]);
                    strcpy(s[j],s[j + 1]);
                    strcpy(s[j + 1],t);
                }
            }
        }
    }
    for(int i = 0;i < n;i ++)
    {
        printf("%s",s[i]);
    }

    return 0;
}