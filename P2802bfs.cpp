#include <stdio.h>
#include <queue>
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
struct node
{
    int x,y,hp,count;
}n1,n2;
int n,m;
int ans[9][9] = {};
int r[9][9] = {};
int h[9][9] = {};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int main()
{
    int a,b,c,d;
    n = read();
    m = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            ans[i][j] = read();
            r[i][j] = -1;
            if(ans[i][j] == 2)
            {
                r[i][j] = 0;
                h[i][j] = 6;
                a = i,b = j;
            }
            if(ans[i][j] == 3)
            {
                c = i,d = j;
            }
        }
    }
    queue<struct node> M;
    M.push((node){a,b,6,0});
    
    while(M.size())
    {
        n1 = M.front();
        M.pop();
        r[n1.x][n1.y] = n1.count;

        if(ans[n1.x][n1.y] == 3)
        {
            break;
        }
        if(n1.hp == 1)
        {
            continue;
        }

        for(int i = 0;i < 4;i ++)
        {
            int nx = n1.x + dx[i];
            int ny = n1.y + dy[i];
            if(ans[nx][ny] != 0 && nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            {
                if(h[nx][ny] < n1.hp - 1)
                {
                    n2.x = nx, n2.y = ny;
                    
                    if(ans[nx][ny] == 4)
                    {
                        n2.hp = 6;
                    }
                    else
                    {
                        n2.hp = n1.hp - 1;
                    }
                    h[nx][ny] = n2.hp;

                    n2.count = n1.count + 1;
                    M.push(n2);
                }
            }
        }
    }

    printf("%d",r[c][d]);

    return 0;
}