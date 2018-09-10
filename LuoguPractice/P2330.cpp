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
struct edge
{
    int from,to,dis;
    bool operator < (const edge &a) const
    {
        return dis < a.dis;
    }
};
edge G[10001];
int father[301];
int level[301];
int n,m,Count,maxEdge;
int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x]);
    }
}
void unionSet(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx == rooty)
    {
        return ;
    }

    if(level[rootx] < level[rooty])
    {
        father[rootx] = rooty;
    }
    else
    {
        father[rooty] = rootx;
        if(level[rootx] == level[rooty])
        {
            level[rootx] ++;
        }
    }
}
void kruskal()
{
    for(int i = 0;i < m;i ++)
    {
        int u = G[i].from, v = G[i].to;
        if(find(u) == find(v))
        {
            continue;
        }
        unionSet(u,v);
        Count ++;
        if(maxEdge < G[i].dis)
        {
            maxEdge = G[i].dis;
        }
    }
    return ;
}
int main()
{
    n = read(),m = read();
    
    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }
    
    for(int i = 0;i < m;i ++)
    {
        G[i].from = read(),G[i].to = read(),G[i].dis = read();
    }
    
    sort(G,G + m);

    kruskal();

    printf("%d %d",Count,maxEdge);

    return 0;
}