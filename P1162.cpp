#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
typedef pair<int, int> P;
int n;
int a[30][30] = {};
int dx[8] = {-1,0,0,1,-1,-1,1,1};
int dy[8] = {0,-1,1,0,-1,1,-1,1};
int isCo(int x,int y)
{
    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        {
            return 1;
        }
    }
    return 0;
}
void bfs(int x,int y)
{
    a[x][y] = 0;
    
    queue<P> m;
    m.push(P(x,y));
    while(m.size())
    {
        P p = m.front();
        m.pop();

        for(int i = 0;i < 4;i ++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 2)
            {
                P p1(nx,ny);
                a[nx][ny] = 0;
                m.push(p1);
            }
        }
    }
}
int main()
{
    n = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0)
            {
                a[i][j] = 2;
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(a[i][j] == 2 && isCo(i,j))
            {
                bfs(i,j);
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}