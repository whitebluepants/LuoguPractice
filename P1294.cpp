#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,m,max = -1,count = 0;
int ans[50][3] = {};
int used[21] = {};
int isRoad(int p,int used[])
{
    for(int i = 0;i < m;i ++)
    {
        if(ans[i][0] == p && used[ans[i][1]] == 0)
        {
            return 1;
        }
        if(ans[i][1] == p && used[ans[i][0]] == 0)
        {
            return 1;
        }
    }
    return 0;
}
void dfs(int p)
{
    if(isRoad(p,used) == 0)
    {
        if(count > max)
        {
            max = count;
        }
        return ;
    }

    for(int i = 0;i < m;i ++)
    {
        if(ans[i][0] == p && used[ans[i][1]] == 0)
        {
            count += ans[i][2];
            used[ans[i][1]] = 1;
            dfs(ans[i][1]);
            count -= ans[i][2];
            used[ans[i][1]] = 0;
        }
        if(ans[i][1] == p && used[ans[i][0]] == 0)
        {
            count += ans[i][2];
            used[ans[i][0]] = 1;
            dfs(ans[i][0]);
            count -= ans[i][2];
            used[ans[i][0]] = 0;
        }
    }
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        ans[i][0] = read(),ans[i][1] = read(),ans[i][2] = read();
    }
    
    for(int i = 0;i < n;i ++)
    {
        memset(used,0,sizeof(used));
        used[i + 1] = 1;
        dfs(i + 1);
        used[i + 1] = 0;
    }

    printf("%d",max);

    return 0;
}