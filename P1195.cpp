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
int father[1001];
int level[1001];
int n,m,k;
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
    int res = 0,num = n;
    
    for(int i = 0;i < m && num > k;i ++)
    {
        int u = G[i].from, v = G[i].to;
        if(find(u) == find(v))
        {
            continue;
        }
        unionSet(u,v);
        num --;
        res += G[i].dis;
    }

    return num == k?res:-1;
}
int main()
{
    n = read(),m = read(),k = read();
    
    for(int i = 0;i < m;i ++)
    {
        G[i].from = read(),G[i].to = read(),G[i].dis = read();
    }

    sort(G,G + m);
    
    if(n < k)
    {
        printf("No Answer\n");
    }
    else
    {
        for(int i = 1;i <= n;i ++)
        {
            father[i] = i;
        }
        
        int sum = kruskal();

        if(sum == -1)
        {
            printf("No Answer\n");
        }
        else
        {
            printf("%d",sum);
        }
    }

    return 0;
}