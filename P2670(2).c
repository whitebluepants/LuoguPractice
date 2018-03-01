#include <stdio.h>
char a[100][100];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int n,m;

void mine(char t[100][100],int x,int y)
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
    char c;
    scanf("%d %d",&n,&m);
    c = getchar();
    if(c == '\r')
    {
        getchar();
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            scanf("%c",&a[i][j]);
        }
        c = getchar();
        if(c == '\r')
        {
            getchar();
        }
    }
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(a[i][j] != '*')
            {
                mine(a,i,j);
            }
            printf("%c",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}