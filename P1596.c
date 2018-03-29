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

int count = 0,n,m;
char s[100][101];
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int dx[8] = {-1,-1,-1,0,0,1,1,1};

void dfs(int i,int j)
{
    s[i][j] = '.';
    int nx,ny;
    for(int k = 0;k < 8;k ++)
    {
        nx = i + dx[k];
        ny = j + dy[k];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if(s[nx][ny] == 'W')
            {
                dfs(nx,ny);
            }
        }
    }

}
int main()
{
    n = read(),m = read();
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;s[i][j] != '\0';j ++)
        {
            if(s[i][j] == 'W')
            {
                dfs(i,j);
                count ++;
            }
        }
    }
    printf("%d",count);
    return 0;
}