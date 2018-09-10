#include <stdio.h>
#include <queue>
using namespace std;
struct node
{
    int x,y,count;
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
int used[401][401] = {};
int count[401][401] = {};
int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int main()
{
    int n = read(),m = read(),x = read(),y = read();

    queue<node> q;
    node a = {x,y,0};
    count[x][y] = 0;
    used[x][y] = 1;
    q.push(a);
    
    while(q.size())
    {
        node p = q.front();
        q.pop();

        for(int i = 0;i < 8;i ++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if(used[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                used[nx][ny] = 1;
                count[nx][ny] = p.count + 1;
                node b = {nx,ny,p.count + 1};
                q.push(b);
            }
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            if(i == x && j == y)
            {
                printf("%-5d",0);
            }
            else if(count[i][j] == 0)
            {
                printf("%-5d",-1);
            }
            else
            {
                printf("%-5d",count[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}