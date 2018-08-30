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
    int to;
    int dis;
    edge(int tt,int dd) : to(tt), dis(dd) {}; 
    bool operator < (const edge &a) const
    {
        return dis > a.dis;
    }
};
vector<edge> G[2001];
bool visited[2001];
int n,m;
int maxEdge;
void prim(int s)
{
    maxEdge = -1;
    visited[s] = 1;
    priority_queue<edge> pq;

    for(int i = 0;i < G[s].size();i ++)
    {
        pq.push(G[s][i]);
    }

    while(pq.size())
    {
        edge t = pq.top();
        pq.pop();
        
        if(visited[t.to])
        {
            continue;
        }
        visited[t.to] = true;
        if(t.dis > maxEdge)
        {
            maxEdge = t.dis;
        }

        for(int i = 0;i < G[t.to].size();i ++)
        {
            pq.push(G[t.to][i]);
        }
    }

    return ;
}
int main()
{
    n = read(),m = read();
    
    for(int i = 0;i < m;i ++)
    {
        int u = read(),v = read(),d = read();
        
        G[u].push_back(edge(v,d));
        G[v].push_back(edge(u,d));
    }

    prim(1);

    printf("%d",maxEdge);

    return 0;
}