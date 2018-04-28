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
int ans[20] = {};
int map[20][20] = {};
int used[20] = {};
int n;
int max = -1,m[20] = {};
void dfs(int count,int t,int floo)
{
    if(count > max)
    {
        max = count;
        memset(m,0,sizeof(m));
        for(int j = 0;used[j] != -1;j ++)
        {
            m[j] = used[j] + 1;
        }
    }

    for(int i = 0;i < n - (t + 1);i ++)
    {
        if(map[t][i] == 1)
        {
            used[floo] = t + 1 + i;
            dfs(count + ans[t + i + 1],t + 1 + i,floo + 1);
            used[floo] = -1;
        }
    }
}
int main()
{
    n = read();
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    for(int i = 0;i < n - 1;i ++)
    {
        for(int j = 0;j < n - (i + 1);j ++)
        {
            map[i][j] = read();
        }
    }
    
    memset(used,-1,sizeof(used));
    for(int i = 0;i < n;i ++)
    {
        used[0] = i;
        dfs(ans[i],i,0 + 1);
    }

    for(int i = 0;m[i] != 0;i ++)
    {
        printf("%d ",m[i]);
    }
    printf("\n%d",max);

    return 0;
}