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
int n,m,count = 0,hp = 6,min = 999;
int ans[9][9];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(int a,int b)
{
    int nx,ny;
    for(int i = 0;i < 4;i ++)
    {
        if(hp == 1)
        {
            return;
        }
        nx = a + dx[i];
        ny = b + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if(ans[nx][ny] == 1)
            {
                hp --;
                count ++;
                dfs(nx,ny);
                hp ++;
                count --;
            }
            if(ans[nx][ny] == 4)
            {
                int temp = hp;
                // hp --;
                // if(hp == 0)
                // {
                //     hp ++;
                //     return;
                // }
                hp = 6;
                count ++;
                dfs(nx,ny);
                hp = temp;
            }
            if(ans[nx][ny] == 3)
            {
                // hp --;
                // if(hp == 0)
                // {
                //     return;
                // }
                count ++;
                if(count < min)
                {
                    min = count;
                }
                return;
            }
        }
    }
}
int main()
{
    int a,b;
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            ans[i][j] = read();
            if(ans[i][j] == 2)
            {
                a = i,b = j;
            }
        }
    }
    dfs(a,b);

    if(min == 999)
    {
        printf("-1");
    }
    else
    {
        printf("%d",min);
    }
}