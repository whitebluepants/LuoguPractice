#include <stdio.h>
char a[101][101];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int n,m;

void mine(char t[101][101],int x,int y)
{
    int ans = 0,nx,ny;

    for(int i = 0;i < 8;i ++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && t[nx][ny] == '*')
        {
            ans ++;
        }          
    }
    t[x][y] = ans + '0';
}
int main()
{
    scanf("%d %d",&n,&m);

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",a[i]);
    }
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(a[i][j] != '*')
            {
                mine(a,i,j);
            }
        }
        printf("%s\n",a[i]);
    }

    return 0;
}