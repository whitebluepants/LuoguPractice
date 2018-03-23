#include <stdio.h>
#include <string.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-1*x;
}
int main()
{
    char s[20][100];
    char a[100];
    int count = 0;
    int n = read(),m = read();
    getchar();
    for(int i = 0;i < n;++ i)
    {
        fgets(s[i],100,stdin);
        int len = strlen(s[i]) - 2;
        if(s[i][len] == 13)
        {
            s[i][len] = '\0';
        }
    }
    for(int i = 0;i < m;++ i)
    {
        fgets(a,100,stdin);
        int len = strlen(a) - 2;
        if(a[len] == 13)
        {
            a[len] = '\0';
        }
        for(int j = 0;j < n;++ j)
        {
            if(strcmp(a,s[j]) == 0)
            {
                ++ count;
                break;
            }
        }
    }
    printf("%d",count);
    return 0;
}