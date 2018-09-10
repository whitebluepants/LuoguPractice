#include <stdio.h>
#include <algorithm>
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
    int n = read();
    char s[1000][1001] = {};

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    char t[1000][1001] = {};
    int l = 0;
    
    for(int i = 0;i < n;i ++)
    {
        char ss[1001] = {};
        int len = strlen(s[i]);
        sort(s[i],s[i] + len);
        int k = 0;
        ss[0] = s[i][0];
        for(int j = 1;s[i][j] != '\0';j ++)
        {
            if(s[i][j] != ss[k])
            {
                ss[++ k] = s[i][j];
            }
        }

        if(l == 0)
        {
            strcpy(t[0],ss);
            l ++;
        }
        else
        {
            int flag = 0,j;
            for(j = 0;j < l;j ++)
            {
                if(strcmp(t[j],ss) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                strcpy(t[j],ss);
                l ++;
            }
        }
    }
    printf("%d",l);

    return 0;
}