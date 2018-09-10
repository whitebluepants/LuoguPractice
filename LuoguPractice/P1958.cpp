#include <stdio.h>
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
int n,m,count;
int ans[17][17];
void dfs(int x,int y)
{
    if(x == n && y == m)
    {
        count ++;
        return ;
    }
    if(x <= n && ans[x + 1][y] == 0)
    {
        dfs(x + 1,y);
    }
    if(y <= m && ans[x][y + 1] == 0)
    {
        dfs(x,y + 1);
    }
}
int main()
{
    n = read(),m = read();
    int t = read();
    for(int i = 1;i <= t;i ++)
    {
        int a = read(),b = read();
        ans[a][b] = 1;
    }
    dfs(1,1);

    printf("%d",count);

    return 0;
}