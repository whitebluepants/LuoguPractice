#include <stdio.h>
#include <string.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n;
int used[100][100];
char s[100][101];
char t[7] = {'y','i','z','h','o','n','g'};
int ans[7][2] = {};
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y,int k,int forward)
{
    if(k == 7)
    {
        for(int t = 0;t < 7;t ++)
        {
            used[ans[t][0]][ans[t][1]] = 1;
        }
        return ;
    }
    
    if(forward == -1)
    {
        for(int i = 0;i < 8;i ++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && s[nx][ny] == t[k])
            {
                ans[k][0] = nx,ans[k][1] = ny;
                dfs(nx,ny,k + 1,i);
                ans[k][0] = 0,ans[k][1] = 0;
            }     
        }
    }
    else
    {
        int nx = dx[forward] + x;
        int ny = dy[forward] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && s[nx][ny] == t[k])
        {
            ans[k][0] = nx,ans[k][1] = ny;
            dfs(nx,ny,k + 1,forward);
            ans[k][0] = 0,ans[k][1] = 0;
        }  
    }
}
int main()
{
    n = read();
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            memset(ans,0,sizeof(ans));
            ans[0][0] = i;
            ans[0][1] = j;
            if(s[i][j] == 'y')
            {
                dfs(i,j,1,-1);
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(used[i][j] == 0)
            {
                s[i][j] = '*';
            }
        }
    }
    for(int i = 0;i < n;i ++)
    {
        printf("%s\n",s[i]);
    }

    return 0;
}