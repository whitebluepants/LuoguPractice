#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int flag;
    int access[4];
};
node map[50][50];
int dx[4] = {-1,0,0,1}; // 上左右下
int dy[4] = {0,-1,1,0};
int count,n,m;
void dfs(int x,int y)
{
    map[x][y].flag = 1;
    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[x][y].access[i] == 1 && map[nx][ny].access[abs(i - 3)] == 1 && map[nx][ny].flag == 0)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    n,m;
    while(scanf("%d %d",&n,&m) && n != -1 && m != -1)
    {
        char s[50][51] = {};
        for(int i = 0;i < n;i ++)
        {
            scanf("%s",s[i]);
        }
        memset(map,0,sizeof(map));
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;s[i][j] != '\0';j ++)
            {
                switch(s[i][j])
                {
                    case 'A': map[i][j].access[0] = 1,map[i][j].access[1] = 1; break;
                    case 'B': map[i][j].access[0] = 1,map[i][j].access[2] = 1; break;
                    case 'C': map[i][j].access[1] = 1,map[i][j].access[3] = 1; break;
                    case 'D': map[i][j].access[2] = 1,map[i][j].access[3] = 1; break;
                    case 'E': map[i][j].access[0] = 1,map[i][j].access[3] = 1; break;
                    case 'F': map[i][j].access[1] = 1,map[i][j].access[2] = 1; break;
                    case 'G': map[i][j].access[0] = 1,map[i][j].access[1] = 1,map[i][j].access[2] = 1; break;
                    case 'H': map[i][j].access[0] = 1,map[i][j].access[1] = 1,map[i][j].access[3] = 1; break;
                    case 'I': map[i][j].access[1] = 1,map[i][j].access[2] = 1,map[i][j].access[3] = 1; break;
                    case 'J': map[i][j].access[0] = 1,map[i][j].access[2] = 1,map[i][j].access[3] = 1; break;
                    case 'K': map[i][j].access[0] = 1,map[i][j].access[1] = 1,map[i][j].access[2] = 1,map[i][j].access[3] = 1; break;
                }
            }
        }

        count = 0;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                if(map[i][j].flag == 0)
                {
                    count ++;
                    dfs(i,j);
                }
            }
        }

        printf("%d\n",count);
    }

    return 0;
}