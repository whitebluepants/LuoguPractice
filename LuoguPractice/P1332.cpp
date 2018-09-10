#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct node
{
    int x,y;
};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int used[501][501] = {};
int p[250001][2] = {};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int main()
{
    int n = read(),m = read(),a = read(),b = read();
    queue<node> q;

    memset(used,-1,sizeof(used));
    for(int i = 0;i < a;i ++)
    {
        int x = read(),y = read();
        used[x][y] = 0;
        node xx = {x,y};
        q.push(xx);    
    }
    for(int i = 0;i < b;i ++)
    {
        p[i][0] = read(),p[i][1] = read();
    }

    while(q.size())
    {
        node p = q.front();
        q.pop();
        
        for(int i = 0;i < 4;i ++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if(used[nx][ny] == -1 && nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                used[nx][ny] = used[p.x][p.y] + 1;
                node x = {nx,ny};
                q.push(x);
            }
        }
    }
    for(int i = 0;i < b;i ++)
    {
        printf("%d\n",used[p[i][0]][p[i][1]]);
    }
    return 0;
}