#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
char map[6][7] = {};
int vis[6][7] = {};
int n,m,time,flag,xx,yy;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(int x,int y,int count)
{
    if(flag)
    {
        return ;
    }
    if(map[x][y] == 'D' && count == 0)
    {
        flag = 1;
        return ;
    }
    int t = abs(x - xx) + abs(y - yy);
    if(t % 2 != count % 2)
    {
        return ;
    }
    
    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 'X' && vis[nx][ny] == 0)
        {
            vis[nx][ny] = 1;
            dfs(nx,ny,count - 1);
            vis[nx][ny] = 0;
        }
    }
}
int main()
{
    n,m,time;
    while(scanf("%d %d %d",&n,&m,&time) && n && m && time)
    {
        memset(map,0,sizeof(map));
        for(int i = 0;i < n;i ++)
        {
            scanf("%s",map[i]);
        }

        int x,y;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                if(map[i][j] == 'S')
                {
                    x = i,y = j;
                }
                if(map[i][j] == 'D')
                {
                    xx = i,yy = j;
                }
            }
        }
        flag = 0;
        vis[x][y] = 1;
        dfs(x,y,time);
        vis[x][y] = 0;

        if(flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}