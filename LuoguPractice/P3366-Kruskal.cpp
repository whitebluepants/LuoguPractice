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
    bool operator < (const edge &a)const
    {
        return dis < a.dis;
    }
};
edge e[200001];
int father[5001];
int rank1[5001];
int n,m,s;
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
    int rootx = find(x), rooty = find(y);
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
        if(rank1[rootx] == rank1[rooty])
        {
            rank1[rootx] ++;
        }
    }
}
int kruskal()
{
    int sum = 0;

    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }
    
    for(int i = 0;i < m;i ++)
    {
        int u = e[i].from, v = e[i].to;

        if(find(u) != find(v))
        {
            unionSet(u,v);
            sum += e[i].dis;
        }
        else
        {
            continue;
        }
    }
    return sum;
}
int main()
{
    n = read(),m = read();
    s = 1;

    for(int i = 0;i < m;i ++)
    {
        e[i].from = read(),e[i].to = read(),e[i].dis = read();
    }
    
    sort(e,e + m);

    int sum = kruskal();

    for(int i = 2;i <= n;i ++)
    {
        if(find(i) != find(1))
        {
            sum = -1;
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