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
struct node
{
    int x,y;
};
node ans[1000002];
int visited[1010][1010];
char s[1010][1010];
int n,m,count = 1;
void dfs(int x,int y,int k)
{
    if( !(x >= 0 && x < n && y >= 0 && y < m) || visited[x][y] == 2)
    {
        for(int i = 0;i < k;i ++)
        {
            visited[ans[i].x][ans[i].y] = 2;
        }
        return;
    }
    if(s[x][y] == 'o')
    {
        for(int i = 0;i < k;i ++)
        {
            if(visited[ans[i].x][ans[i].y] != 3)
            {
                printf("%d %d\n",ans[i].x,ans[i].y);
                count ++;
                visited[ans[i].x][ans[i].y] = 3;
            }
        }
        printf("\n");
        return;
    }
    if(visited[x][y] != 1)
    {
        ans[k].x = x,ans[k].y = y;
        if(s[x][y] == 'u')
        {
            visited[x][y] = 1;
            dfs(x - 1,y,k + 1);
            visited[x][y] = 0;
        }
        if(s[x][y] == 'd')
        {
            visited[x][y] = 1;
            dfs(x + 1,y,k + 1);
            visited[x][y] = 0;
        }
        if(s[x][y] == 'l')
        {
            visited[x][y] = 1;
            dfs(x,y - 1,k + 1);
            visited[x][y] = 0;
        }
        if(s[x][y] == 'r')
        {
            visited[x][y] = 1;
            dfs(x,y + 1,k + 1);
            visited[x][y] = 0;
        }
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
        for(int j = 0;j < n;j ++)
        {
            if(visited[i][j] == 0)
            {
                dfs(i,j,0);
            }
        }
    }

    printf("%d",count);

    return 0;
}