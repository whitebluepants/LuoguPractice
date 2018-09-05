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
struct edge
{
    int to,dis;
    edge(int tt,int dd){to = tt,dis = dd;}
    bool operator < (const edge &a) const
    {
        return dis > a.dis;
    }
};
node e[400002];
int head[5001];
int dis[5001];
bool vis[5001];
int n,m,num;
void addedge(int from,int to,int dis)
{
    e[++ num].next = head[from];
    e[num].to = to;
    e[num].dis = dis;
    head[from] = num;
}
int prim(int s)
{
    dis[s] = 0;
    int cnt = 0,sum = 0;
    priority_queue<edge> pq;
    pq.push(edge(s,0));

    while(pq.size())
    {
        edge t = pq.top();
        pq.pop();

        int u = t.to,ud = t.dis;

        if(vis[u])
        {
            continue;
        }
        vis[u] = true;
        cnt ++;
        sum += ud;
        if(cnt == n)
        {
            break;
        }

        for(int i = head[u];i;i = e[i].next)
        {
            int v = e[i].to,d = e[i].dis;
            if(!vis[v] && dis[v] > d)
            {
                dis[v] = d;
                pq.push(edge(v,d));
            }
        }
    }

    if(cnt != n)
    {
        sum = -1;
    }

    return sum;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int u = read(),v = read(),dis = read();
        addedge(u,v,dis);
        addedge(v,u,dis);
    }

    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }

    int sum = prim(1);

    if(sum == -1)
    {
        printf("orz");
    }
    else
    {
        printf("%d",sum);
    }
    
    return 0;
}