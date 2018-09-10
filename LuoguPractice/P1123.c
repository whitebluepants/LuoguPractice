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
int n;
int a,b;
int ans[6][6] = {};
int used[6][6] = {};
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int max;

void dfs(int i,int j,int count)
{
    if(j >= b)
    {
        j = 0;
        i ++;
    }

    if(i >= a)
    {
        if(count > max)
        {
            max = count;
        }
        return ;
    }

    if(used[i][j] == 0)
    {
        for(int l = 0;l < 8;l ++)
        {
            int nx = i + dx[l];
            int ny = j + dy[l];
            if(nx >= 0 && nx < a && ny >= 0 && ny < b)
            {
                used[nx][ny] ++;
            }
        }
        dfs(i,j + 2,count + ans[i][j]);
        for(int l = 0;l < 8;l ++)
        {
            int nx = i + dx[l];
            int ny = j + dy[l];
            if(nx >= 0 && nx < a && ny >= 0 && ny < b)
            {
                used[nx][ny] --;
            }
        }
    }
    dfs(i,j + 1,count);
    
}
int main()
{
    n = read();
    
    for(int i = 0;i < n;i ++)
    {
        max = -1;
        a = read(),b = read();
        for(int j = 0;j < a;j ++)
        {
            for(int k = 0;k < b;k ++)
            {
                ans[j][k] = read();
            }
        }

        dfs(0,0,0);

        printf("%d\n",max);
    }

    return 0;
}