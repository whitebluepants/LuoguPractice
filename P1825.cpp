#include <stdio.h>
#include <queue>
#include <utility>
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
struct letter
{
    int x1,y1,x2,y2;
};
struct node
{
    int x,y,count;
};
letter l[27];
char s[300][301];
int visited[300][301];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int n,m;
int main()
{
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    int x,y,xx,yy;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(s[i][j] == '@')
            {
                x = i,y = j;
            }
            if(s[i][j] >= 'A' && s[i][j] <= 'Z')
            {
                if(l[s[i][j] - 'A'].x1 == 0)
                {
                    l[s[i][j] - 'A'].x1 = i;
                    l[s[i][j] - 'A'].y1 = j;
                }
                else
                {
                    l[s[i][j] - 'A'].x2 = i;
                    l[s[i][j] - 'A'].y2 = j;
                }
            }
            if(s[i][j] == '=')
            {
                xx = i,yy = j;
            }
        }
    }
    
    queue<node> q;
    node a = {x,y,0};
    q.push(a);
    int min = 0;

    while(q.size())
    {
        node t = q.front();
        q.pop();

        if(t.x == xx && t.y == yy)
        {
            min = t.count;
            break;
        }

        for(int i = 0;i < 4;i ++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny <= m && s[nx][ny] != '#' && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                node x = {nx,ny,t.count + 1};
                if(s[nx][ny] >= 'A' && s[nx][ny] <= 'Z')
                {
                    int tt = s[nx][ny] - 'A';
                    if(l[tt].x1 == nx && l[tt].y1 == ny)
                    {
                        x.x = l[tt].x2;
                        x.y = l[tt].y2;
                        //visited[x.x][x.y] = 1; 这两处会导致一些情况走不到终点
                    }
                    else if(l[tt].x2 == nx && l[tt].y2 == ny)
                    {
                        x.x = l[tt].x1;
                        x.y = l[tt].y1;
                        //visited[x.x][x.y] = 1;
                    }
                }
                q.push(x);
            }
        }
    }
    
    printf("%d",min);

    return 0;
}