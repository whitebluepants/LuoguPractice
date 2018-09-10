#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 999999999
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
struct node
{
    int next,to,dis;
};
struct edge
{
    int a,b;
};
struct edge2
{
    int a,b;
};
bool cmp(edge2 a,edge2 b)
{
    if(a.a == b.a)
    {
        return a.b < b.b;
    }
    return a.a < b.a;
}
edge2 ee[5001];
edge e[5001];
node ans[10010];
int head[151];
int dis[151];
bool visited[151];
int n,m,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void spfa(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(q.size())
    {
        int u = q.front();
        q.pop();
        visited[u] = false;

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read();
        e[i].a = a,e[i].b = b;
        addedge(a,b,0);
        addedge(b,a,0);
    }
    int j,k,l = 0;
    for(int i = 1;i <= m;i ++)
    {
        int a = e[i].a, b = e[i].b;
        for(j = head[a];j;j = ans[j].next)
        {
            if(ans[j].to == b)
            {
                break;
            }
        }
        for(k = head[b];k;k = ans[k].next)
        {
            if(ans[k].to == a)
            {
                break;
            }
        }
        ans[j].dis = INF, ans[k].dis = INF;
        spfa(a);
        ans[j].dis = 0, ans[k].dis = 0;

        if(dis[b] == INF)
        {
            if(a > b)
            {
                ee[l].a = b;
                ee[l].b = a;
            }
            else
            {
                ee[l].a = a;
                ee[l].b = b;
            }
            l ++;
        }
    }
    sort(ee,ee + l,cmp);

    for(int i = 0;i < l;i ++)
    {
        printf("%d %d\n",ee[i].a,ee[i].b);
    }

    return 0;
}