#include <queue>
#include <vector>
#include <math.h>
#include <stdio.h>
#define INF 99999999
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0 ;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
struct Edge
{
    int to,dis;
    Edge(int tt,int dd) : to(tt),dis(dd) {}
    bool operator < (const Edge &a) const
    {
        return dis > a.dis;
    }
};
struct edge
{
    int next,to,dis;
};
edge e[4000010];
int head[2001];
bool vis[2001];
int dis[2001];
int n,c,num;
int p[2001][2];
void addedge(int from,int to,int dis)
{
    e[++ num].next = head[from];
    e[num].to = to;
    e[num].dis = dis;
    head[from] = num;
}
int prim(int s)
{
    priority_queue<Edge> pq;
    int cnt = 0;
    int sum = 0;
    pq.push(Edge(s,0));
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    
    while(pq.size() && cnt < n)
    {
        Edge t = pq.top();
        pq.pop();
        if(vis[t.to])
        {
            continue;
        }
        vis[t.to] = true;
        cnt ++;
        sum += t.dis;
        
        int u = t.to;
        for(int i = head[u];i;i = e[i].next)
        {
            int v = e[i].to;
            int d = e[i].dis;
            if(!vis[v] && dis[v] > d)
            {
                dis[v] = d;
                pq.push(Edge(v,d));
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
    n = read(),c = read();
    for(int i = 1;i <= n;i ++)
    {
        p[i][0] = read(),p[i][1] = read();
    }

    for(int i = 1;i <= n;i ++)
    {
        for(int j = i + 1;j <= n;j ++)
        {
            int x1 = p[i][0], y1 = p[i][1];
            int x2 = p[j][0], y2 = p[j][1];
            int dis = pow(x1 - x2,2) + pow(y1 - y2,2);
            if(dis < c)
            {
                continue;
            }
            addedge(i,j,dis);
            addedge(j,i,dis);
        }
    }

    int sum = prim(1);

    printf("%d",sum);

    return 0;
}