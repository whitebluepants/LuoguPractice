#include <stdio.h>
#include <queue>
using namespace std;
struct node
{
    int x,y,d;
};
int read()
{
    int f = 1;
    char ch = getchar();
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int map[1001][1001];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int used[1001][1001] = {};
int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    int min = 9999999;
    int x1 = read(),y1 = read(),x2 = read(),y2 = read();
    queue<node> q;
    node a = {x1,y1,0};
    used[x1][y1] = 1;
    q.push(a);
    
    while(q.size())
    {
        node p = q.front();
        q.pop();

        if(p.x == x2 && p.y == y2)
        {
            if(p.d < min)
            {
                min = p.d;
            }
        }

        for(int i = 0;i < 4;i ++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if(map[nx][ny] != 1 && used[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= n)
            {
                used[nx][ny] = 1;
                node xx = {nx,ny,p.d + 1};
                q.push(xx);
            }
        }
    }
    printf("%d",min);

    return 0;
}