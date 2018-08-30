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
int father[10001];
int level[10001];
edge G[100001];
int n,m,k;
int talk[10001];
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
    int rootx = find(x), rooty = find(y);
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
    int sum = 0;
    for(int i = 0;i < m;i ++)
    {
        int u = G[i].from, v = G[i].to;
        
        if(find(u) == find(v))
        {
            continue;
        }
        unionSet(u,v);
        sum += G[i].dis;
    }
    return sum;
}
int main()
{
    n = read(), m = read();
    int minn = 99999;
    for(int i = 0;i < n;i ++)
    {
        talk[i] = read();
        father[i] = i;
        if(talk[i] < minn)
        {
            minn = talk[i];
        }
    }

    for(int i = 0;i < m;i ++)
    {
        G[i].from = read(),G[i].to = read(); 
        int d = read();
        G[i].dis = d * 2 + talk[G[i].from - 1] + talk[G[i].to - 1];
    }

    sort(G,G + m);
    
    printf("%d",minn + kruskal());

    return 0;
}