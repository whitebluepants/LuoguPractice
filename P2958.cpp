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
int r,c;
int visited[41][41];
int map[41][41];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int dfs(int x,int y,int count)
{
    if(x == r && y == c)
    {
        return count;
    }
    int k,t = -1;
    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny] != 1 && map[nx][ny] > t)
        {
            t = map[nx][ny];
            k = i;
        }
    }
    int nx = x + dx[k];
    int ny = y + dy[k];
    visited[nx][ny] = 1;
    dfs(nx,ny,count + map[nx][ny]);
}
int main()
{
    r = read(),c = read();
    for(int i = 1;i <= r;i ++)
    {
        for(int j = 1;j <= c;j ++)
        {
            map[i][j] = read();
        }
    }
    visited[1][1] = 1;
    int count = dfs(1,1,map[1][1]);

    printf("%d",count);

    return 0;
}