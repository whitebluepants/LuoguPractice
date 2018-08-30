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
vector<edge> G[101];
bool visited[101];
int n;
int prim(int s)
{
    int res = 0;
    visited[s] = true;
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
        res += t.dis;

        for(int i = 0;i < G[t.to].size();i ++)
        {
            pq.push(G[t.to][i]);
        }
    }
    return res;
}
int main()
{
    n = read();

    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            int dis = read();
            if(i == j)
            {
                continue;
            }
            G[i].push_back(edge(j,dis));
        }
    }
    
    int sum = prim(1);

    printf("%d",sum);

    return 0;
}