#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,m;
char s[100][100] = {};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(int x,int y)
{
    s[x][y] = '0';

    for(int i = 0;i < 4;i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '0')
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    int count = 0;
    n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(s[i][j] != '0')
            {
                count ++;
                dfs(i,j);
            }
        }
    }

    printf("%d",count);

    return 0;
}