#include <queue>
#include <stdio.h>
#define INF 999999999
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
struct edge
{
    int next,to,dis;

    bool operator < (const edge &a) const
    {
        return dis > a.dis;
    }
};
int head[1001];
edge ans[6020];
int vis[1001];
int dis[1001];
int n,m,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
int prim()
{
    int s = 1,count = 0;
    vis[s] = 1;
    
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    priority_queue<edge> pq;
    
    for(int i = head[s];i;i = ans[i].next)
    {
        dis[ans[i].to] = ans[i].dis;
        pq.push(ans[i]);
    }

    while(pq.size())
    {
        edge t = pq.top();
        pq.pop();
        
        int v = t.to;
        if(vis[v])
        {
            continue;
        }
        vis[v] = 1;
        count += t.dis;

        for(int i = head[v];i;i = ans[i].next)
        {
            int vv = ans[i].to;
            int d = ans[i].dis;
            if(!vis[vv] && dis[vv] > d)
            {
                dis[vv] = d;
                pq.push(ans[i]);
            }
        }
    }

    for(int i = 1;i <= n;i ++)
    {
        if(vis[i] == 0)
        {
            count = -1;
            break;
        }
    }
    return count;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge(b,a,c);
    }

    int count = prim();

    printf("%d",count);

    return 0;
}