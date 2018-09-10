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
edge G[200000];
int father[101];
int rank1[101];
int n,m,maxF;
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

    if(rank1[rootx] < rank1[rooty])
    {
        father[rootx] = rooty;
    }
    else
    {
        father[rooty] = rootx;
        if(rank1[rooty] == rank1[rootx])
        {
            rank1[rooty] ++;
        }
    }
}
void kruskal()
{
    for(int i = 0;i < m;i ++)
    {
        int u = G[i].from , v = G[i].to;
        if(find(u) == find(v))
        {
            maxF += G[i].dis;
            continue;
        }
        unionSet(u,v);
    }
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
    
    printf("%d",maxF);

    return 0;
}