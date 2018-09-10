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
    int x,y,count;
};
int n,m;
char s[2001][2001];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int visited[2001][2001];
int main()
{
    n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }

    int x,y;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(s[i][j] == 'm')
            {
                x = i,y = j;  
            }
        }
    }
    queue<node> q;
    node a = {x,y,0};
    q.push(a);
    int min = 2147483647;

    while(q.size())
    {
        node t = q.front();
        q.pop();
        
        int x = t.x , y = t.y;
        if(s[x][y] == 'd')
        {
            min = t.count;
            break;        
        }
        
        for(int i = 0;i < 4;i ++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '#' && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                node x = {nx,ny,t.count + 1};
                q.push(x);
            }
        }
    }
    if(min == 2147483647)
    {
        printf("No Way!");
    }
    else
    {
        printf("%d",min);
    }
    return 0;
}