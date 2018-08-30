#include <stdio.h>
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
    edge(int tt,int dd) : to(tt), dis(dd) {}
};
struct cmp
{
    bool operator () (edge a,edge b)
    {
        return a.dis > b.dis;
    }
};
vector<edge> e[5001];
bool visited[5001];
int n,m;
int prim(int s)
{
    int sum = 0;
    visited[s] = true;
    priority_queue<edge,vector<edge>,cmp> pq;

    for(int i = 0;i < e[s].size();i ++)
    {
        pq.push(e[s][i]);
    }

    while(pq.size())
    {
        edge t = pq.top();
        pq.pop();
        
        if(visited[t.to] == true)
        {
            continue;
        }
        sum += t.dis;
        visited[t.to] = true;
        
        for(int i = 0;i < e[t.to].size();i ++)
        {
            pq.push(e[t.to][i]);
        }
    }
    return sum;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int u = read(),v = read(),dis = read();

        e[u].push_back(edge(v,dis));  
        e[v].push_back(edge(u,dis));
    }

    int sum = prim(1);

    for(int i = 1;i <= n;i ++)
    {
        if(visited[i] == false)
        {
            sum = -1;
            break;
        }
    }
    if(sum == -1)
    {
        printf("orz\n");
    }
    else
    {
        printf("%d\n",sum);
    }

    return 0;
}