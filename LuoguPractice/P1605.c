#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,m,t;
int x1,y1,x2,y2;
int ans[5][5];
int used[5][5];
int count;
int dx[4] = {-1,0,0,2};
int dy[4] = {0,-1,1,0};
void dfs(int x,int y)
{
    if(x == x2 && y == y2)
    {
        count ++;
        return ;
    }
    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(used[nx][ny] != 0 && ans[nx][ny] != 1)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    n = read(),m = read();
    t = read();
    x1 = read() - 1,y1 = read() - 1,x2 = read() - 1,y2 = read() - 1;
    for(int i = 0;i < t;i ++)
    {
        int a = read(),b = read();
        ans[a - 1][b - 1] = 1;
    }
    used[x1][y1] = 1;
    dfs(x1,y1);

    printf("%d",count);

    return 0;
}