#include <stdio.h>
#include <vector>
#include <queue>
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
    int to,dis;
    edge(int tt,int dd) : to(tt), dis(dd) {};
    bool operator < (const edge &a) const
    {
        return dis > a.dis;
    }
};
vector<edge> G[1001];
bool vis[1001];
int n,m;
int prim(int s)
{
    int e = -1;
    vis[s] = true;

    priority_queue<edge> pq;
    for(int i = 0;i < G[s].size();i ++)
    {
        pq.push(G[s][i]);
    }
    
    while(pq.size())
    {
        edge t = pq.top();
        pq.pop();

        if(vis[t.to])
        {
            continue;
        }
        vis[t.to] = true;
        if(e < t.dis)
        {
            e = t.dis;
        }

        for(int i = 0;i < G[t.to].size();i ++)
        {
            pq.push(G[t.to][i]);
        }
    }
    return e;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int u = read(), v = read(), dis = read();
        G[u].push_back(edge(v,dis));
        G[v].push_back(edge(u,dis));
    }

    int maxEdge = prim(1);
    
    for(int i = 1;i <= n;i ++)
    {
        if(vis[i] == false)
        {
            maxEdge = -1;
            break;
        }
    }

    printf("%d",maxEdge);

    return 0;
}