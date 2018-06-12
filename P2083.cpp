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
    int x,y;
};
node ans[1001][101];
bool visited[1001][101];
int n,m,v,x,y,min = 99999999;
void dfs(int a,int b,int vv)
{
    if(a == x && b == y)
    {
        if(vv < min)
        {
            min = vv;
        }
        return ;
    }
    if(a == 0 && b == 0)
    {
        return ;
    }
    if(visited[a][b] == 0)
    {
        visited[a][b] = 1;
        dfs(ans[a][b].x,ans[a][b].y,vv + abs(ans[a][b].x - a) * v);
    }
}
int main()
{
    n = read(),m = read(),v = read(),x = read(),y = read();
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            ans[i][j].x = read(),ans[i][j].y = read();
        }
    }

    for(int i = 1;i <= m;i ++)
    {
        memset(visited,0,sizeof(visited));
        dfs(1,i,0);
    }

    if(min == 99999999)
    {
        printf("impossible");
    }
    else
    {
        printf("%d",min);
    }

    return 0;
}