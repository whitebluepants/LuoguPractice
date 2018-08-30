#include <stdio.h>
#include <math.h>
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
    int from,to;
    double dis;
    bool operator < (const edge &a) const
    {
        return dis < a.dis;
    }
};
edge G[1000001];
int father[1001];
int level[1001];
int n,m,k;
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
double kruskal()
{
    double sum = 0;
    for(int i = 0;i < k;i ++)
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
    n = read(),m = read();
    int farm[1001][2] = {};

    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }
    for(int i = 0;i < n;i ++)
    {
        farm[i][0] = read(),farm[i][1] = read();
    }
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(i == j)
            {
                continue ;
            }
            double dis;
            int x1 = farm[i][0],y1 = farm[i][1];
            int x2 = farm[j][0],y2 = farm[j][1];
            
            dis = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
            G[k].from = i + 1,G[k].to = j + 1,G[k ++].dis = dis;
        }
    }

    for(int i = 0;i < m;i ++)
    {
        int u = read(), v = read();
        unionSet(u,v);
    }
    
    sort(G,G + k);
    double d = kruskal();

    printf("%.2f",d);

    return 0;
}