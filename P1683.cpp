#include <stdio.h>
#include <queue>
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
int visited[20][21];
char s[20][21];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int main()
{
    int n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        scanf("%s",s[i]);
    }
    int x,y;
    for(int i = 0;i < m;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(s[i][j] == '@')
            {
                x = i,y = j;
                break;
            }
        }
    }
    queue<node> q;
    node a = {x,y};
    q.push(a);
    int count = 1;
    visited[x][y] = 1;

    while(q.size())
    {
        node t = q.front();
        q.pop();
        
        for(int i = 0;i < 4;i ++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0 && s[nx][ny] != '#')
            {
                visited[nx][ny] = 1;
                count ++;
                node x = {nx,ny};
                q.push(x);
            }
        }
    }
    printf("%d",count);

    return 0;
}