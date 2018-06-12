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
int visited[1010][1010];
char s[1010][1010];
int n,m,count = 0;
void dfs(int x,int y)
{
    visited[x][y] = 1;
    if(x - 1 >= 0 && s[x - 1][y] == 'd')
    {
        dfs(x - 1,y);
    }
    if(x + 1 < n && s[x + 1][y] == 'u')
    {
        dfs(x + 1,y);
    }
    if(y - 1 >= 0 && s[x][y - 1] == 'r')
    {
        dfs(x,y - 1);
    }
    if(y + 1 < m && s[x][y + 1] == 'l')
    {
        dfs(x,y + 1);
    }
}
int main()
{
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(s[i][j] == 'o')
            {
                dfs(i,j);
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(visited[i][j] == 1)
            {
                count ++;
            }
        }
    }
    printf("%d",count);

    return 0;
}