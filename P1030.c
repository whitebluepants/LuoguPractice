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
char mid[9],back[9],front[9] = {};

void dfs(int ms,int me,int rs,int re)
{
    if(ms > me)
    {
        return;
    }
    for(int i = ms;i <= me;i ++)
    {
        if(mid[i] == back[re])
        {
            printf("%c",mid[i]);
            dfs(ms,i - 1 , rs,i - 1);
            dfs(i + 1,me , i,re - 1);
            // dfs(ms,i - 1 , rs,i - 1 - ms + rs);
            // dfs(i + 1,me , re + i - me,re - 1);
            break;
        }
    }
}
int main()
{
    scanf("%s%s",mid,back);
    int len = strlen(mid);

    dfs(0,len - 1,0,len - 1);

    return 0;
}