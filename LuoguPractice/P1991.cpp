#include <stdio.h>
#include <algorithm>
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
edge G[250000];
int father[501];
int level[501];
int s,p,k;
int position[501][2];
double e[501];
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
void kruskal()
{
    int j = 0;
    for(int i = 1;i <= p;i ++)
    {
        father[i] = i;
    }

    for(int i = 0;i < k;i ++)
    {
        int u = G[i].from, v = G[i].to;

        if(find(u) == find(v))
        {
            continue;
        }
        unionSet(u,v);
        e[j ++] = G[i].dis;
    }
}
int main()
{
    s = read(),p = read();
    for(int i = 0;i < p;i ++)
    {
        position[i][0] = read(),position[i][1] = read();
    }

    for(int i = 0;i < p;i ++)
    {
        for(int j = i + 1;j < p;j ++)
        {
            int x1 = position[i][0],y1 = position[i][1];
            int x2 = position[j][0],y2 = position[j][1];
            double dis = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
            G[k].from = i,G[k].to = j,G[k ++].dis = dis;
        }
    }

    sort(G,G + k);
    kruskal();

    printf("%.2f",e[p - 2 - (s - 1)]);

    return 0;
}