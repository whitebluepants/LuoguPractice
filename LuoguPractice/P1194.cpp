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
    edge(int tt,int dd) : to(tt),dis(dd) {};
    bool operator < (const edge &a) const
    {
        return dis > a.dis;
    }
};
vector<edge> G[501];
bool vis[501];
int n,m;
int prim(int s)
{
    int sum = n;
    vis[s] = 1;

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
        sum += t.dis;
        vis[t.to] = true;

        for(int i = 0;i < G[t.to].size();i ++)
        {
            pq.push(G[t.to][i]);
        }
    }

    return sum;
}
int main()
{
    n = read(),m = read();
    
    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            int dis = read();
            if(i == j)
            {
                continue;
            }
            if(dis == 0 || dis > n)
            {
                dis = n;
            }
            G[i].push_back(edge(j,dis));
        }
    }

    int minMoney = prim(1);

    printf("%d",minMoney);

    return 0;
}