#include <stdio.h>
#include <string.h>
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
int main()
{
    int n = read();
    int visited[101][101] = {};
    char ss[100][220] = {};
    char s[100][101] = {};
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    
    getchar();
    for(int i = 0;i < n;i ++)
    {
        gets(ss[i]);
    }
    
    int len = strlen(ss[0]);
    
    for(int i = 0;i < len;i ++)
    {
        for(int j = 0,k = 0;j < len;j ++)
        {
            if(ss[i][j] != ' ')
            {
                s[i][k ++] = ss[i][j];
            }
        }
    }
    
    int x1,y1,x2,y2;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(s[i][j] == 'A')
            {
                x1 = i,y1 = j;
            }
            if(s[i][j] == 'B')
            {
                x2 = i,y2 = j;
            }
        }
    }  
    queue<node> q;
    node a = {x1,y1,-1};
    q.push(a);
    visited[x1][y1] = 1;
    int min = 99999999;
    while(q.size())
    {
        node t = q.front();
        q.pop();
        
        if(t.x == x2 && t.y == y2)
        {
            if(min > t.count)
            {
                min = t.count;

            }
        }
        for(int i = 0;i < 4;i ++)
        {
            int nx = dx[i] + t.x;
            int ny = dy[i] + t.y;

            while(nx >= 0 && nx < n && ny >= 0 && ny < n && s[nx][ny] != 'x')
            {
                if(visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    node x = {nx,ny,t.count + 1};
                    q.push(x); 
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    if(min == 99999999)
    {
        printf("-1");
    }
    else
    {
        printf("%d",min);
    }
    return 0;
}