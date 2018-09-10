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
    friend bool operator < (node a,node b)
    {
        return a.count > b.count;
    }
};
char s[205][205];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i ++)
        {
            scanf("%s",s[i]);
        }
        
        int x,y;

        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                if(s[i][j] == 'a')
                {
                    x = i,y = j;
                    break;
                }
            }
        }

        priority_queue<node> q;
        node a = {x,y,0};
        q.push(a);
        int min = 999999999;
        int visited[200][201] = {};

        while(q.size())
        {
            node t = q.top();
            q.pop();

            if(s[t.x][t.y] == 'r')
            {
                if(min > t.count)
                {
                    min = t.count;
                }
                break;
            }

            for(int i = 0;i < 4;i ++)
            {
                int nx = dx[i] + t.x;
                int ny = dy[i] + t.y;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '#' && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    node a = {nx,ny,t.count + 1};
                    if(s[nx][ny] == 'x')
                    {
                        a.count ++;
                    }
                    q.push(a);
                }
            }
        }

        if(min == 999999999)
        {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
        else
        {
            printf("%d\n",min);
        }
    }
    return 0;
}