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
int n,m;
int a[100][100];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void bfs(int x,int y)
{
    queue<P> M;
    a[x][y] = 0;

    M.push(P(x,y));
    while(M.size())
    {
        P p = M.front(); M.pop();
        for(int i = 0;i < 4;i ++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != 0)
            {
                P p1(nx,ny);
                M.push(p1);
                a[nx][ny] = 0;
            }
        }
    }
}
int main()
{
    int count = 0;
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            scanf("%1d",&a[i][j]);
        }
    }
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(a[i][j] != 0)
            {
                bfs(i,j);
                count ++;
            }
        }
    }
    printf("%d",count);

    return 0;
}