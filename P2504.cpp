#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
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
    int from,to;
    double dis;
    bool operator < (const edge &a) const
    {
        return dis < a.dis;
    }
};
edge G[1000001];
int jump[501];
int tree[1001][2];
int m,n,k;
int father[1001];
int level[1001];
int find(int x)
{
    if(x == father[x])
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
int kruskal()
{
    int m = -1;
    for(int i = 0;i < k;i ++)
    {
        int u = G[i].from, v = G[i].to;
        if(find(u) == find(v))
        {
            continue;
        }
        unionSet(u,v);
        if(G[i].dis > m)
        {
            m = G[i].dis;
        }
    }
    return m;
}
int main()
{
    m = read();
    
    for(int i = 0;i < m;i ++)
    {
        jump[i] = read();
    }

    n = read();
    for(int i = 0;i < n;i ++)
    {
        tree[i][0] = read(),tree[i][1] = read();
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = i + 1;j < n;j ++) // 把j = 0写成j = i + 1快一倍
        {
            int x1 = tree[i][0],y1 = tree[i][1];
            int x2 = tree[j][0],y2 = tree[j][1];
            double dis = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
            G[k].from = i + 1,G[k].to = j + 1,G[k ++].dis = dis;
        }
    }
    sort(G,G + k);

    int Count = m;
    for(int j = 1;j <= n;j ++)
    {
        father[j] = j;
        level[j] = 0;
    }
    
    int maxEdge = kruskal();
    
    for(int i = 0;i < m;i ++)
    {
        if(jump[i] < maxEdge)
        {
            Count --;
        }
    }

    printf("%d",Count);

    return 0;
}