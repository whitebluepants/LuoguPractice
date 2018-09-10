#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
struct node
{
    int x,y,count;
};
bool cmp(node a,node b)
{
    return a.count > b.count;
}
int map[21][21];
node ans[401];
int m,n,k,num,c;
void dfs(int x,int y,int kk,int step)
{
    if(step >= num)
    {
        return ;
    }
    int s = abs(x - ans[step].x) + abs(y - ans[step].y) + 1 + ans[step].x;
    if(kk < s)
    {
        return ;
    }
    c += ans[step].count;
    dfs(ans[step].x,ans[step].y,kk - abs(x - ans[step].x) - abs(y - ans[step].y) - 1,step + 1);
}
int main()
{
    m = read(),n = read(),k = read();
    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            map[i][j] = read();
            if(map[i][j] != 0)
            {
                ans[num].x = i,ans[num].y = j,ans[num ++].count = map[i][j];
            }
        }
    }
    sort(ans,ans + num,cmp);
    if(k < ans[0].x * 2 + 1)
    {
        printf("0");
    }
    else
    {
        c = ans[0].count;
        dfs(ans[0].x,ans[0].y,k - ans[0].x - 1,1);
        printf("%d",c);
    }
    return 0;
}