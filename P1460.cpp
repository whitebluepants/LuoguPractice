#include <stdio.h>
#include <queue>
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
int n,m,minn = 10000;
int ans[1001] = {};
int a[15][1001] = {};
int used[1001] = {};
int answer[1001] = {};
int aaa[1001] = {};
int isok(int ans[1001],int answer[1001])
{
    for(int i = 0;i < n;i ++)
    {
        if(answer[i] < ans[i])
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int i,int count)
{
    if(isok(ans,answer))
    {
        if(minn > count)
        {
            minn = count;
            for(int l = 0,k = 0;l < m;l ++)
            {
                if(used[l] != 0)
                {
                    aaa[k ++] = l + 1;
                }
            }
        }
    }
    for(;i < m;i ++)
    {
        if(used[i] != 1)
        {
            for(int j = 0;j < n;j ++)
            {
                answer[j] += a[i][j];
            }
            used[i] = 1;
            dfs(i + 1,count + 1);
            for(int j = 0;j < n;j ++)
            {
                answer[j] -= a[i][j];
            }
            used[i] = 0;
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

    m = read();
    for(int i = 0;i < m;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            a[i][j] = read();
        }
    }

    dfs(0,0);

    printf("%d ",minn);
    for(int i = 0;i < minn;i ++)
    {
        printf("%d ",aaa[i]);
    }
    return 0;
}