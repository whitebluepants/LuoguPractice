#include <stdio.h>
#include <queue>
#define INF 99999999
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
    int next,to,dis;
};
node ans[10010];
int dis[101];
int head[101];
int visited[101];
int count[101];
int n,a,b,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void spfa(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    count[s] = 1;
    queue<int> q;
    q.push(s);
    
    while(q.size())
    {
        int u = q.front();
        q.pop();
        visited[u] = 0;

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                if(!visited[v])
                {
                    count[v] ++;
                    visited[v] = 1;
                    if(count[v] > n)
                    {
                        return;
                    }
                    q.push(v);
                }
            }
        }
    }
    return;
}
int main()
{
    n = read(),a = read(),b = read();
    for(int i = 1;i <= n;i ++)
    {
        int t = read();
        for(int j = 1;j <= t;j ++)
        {
            int temp = read();
            if(j == 1)
            {
                addedge(i,temp,0);    
            }
            else
            {
                addedge(i,temp,1);
            }
        }
    }
    spfa(a);

    if(dis[b] == INF)
    {
        printf("-1");
    }
    else
    {
        printf("%d",dis[b]);
    }

    return 0;
}