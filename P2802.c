#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,m,count = 0,hp = 6,min = 999;
int ans[9][9];
int r[9][9] = {}; // record
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(int a,int b,int hp,int time)
{
    if(hp == 0)
    {
        return;
    }
    if(ans[a][b] == 3)
    {
        if(time < min)
        {
            min = time;
        }
        return;
    }

    if(ans[a][b] == 4)
    {
        hp = 6;
    }

    int nx,ny;
    for(int i = 0;i < 4;i ++)
    {
        nx = a + dx[i];
        ny = b + dy[i];
        
        if(nx >= 0 && nx <= n && ny >= 0 && ny <= m)
        {
            if(r[nx][ny] == 1 || ans[nx][ny] == 0)
            {
                continue;
            }
            r[nx][ny] = 1;
            dfs(nx,ny,hp - 1,time + 1);
            r[nx][ny] = 0;
        }
    }
}
int main()
{
    int a,b;
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            ans[i][j] = read();
            if(ans[i][j] == 2)
            {
                a = i,b = j;
                r[a][b] = 1;
            }
        }
    }
    dfs(a,b,6,0);

    if(min == 999)
    {
        printf("-1");
    }
    else
    {
        printf("%d",min);
    }
}