#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#define INF 2147483647
using namespace std;
typedef pair<int,int> pp;
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
struct cmp
{
    bool operator () (pp a,pp b)
    {
        return a.first > b.first;
    }
};
node ans2[100001];
node ans[100001];
int dis[1001];
int dis2[1001];
int head2[1001];
int head[1001];
int n,m,t,num,num2;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void addedge2(int from,int to,int dis)
{
    ans2[++ num2].next = head2[from];
    ans2[num2].to = to;
    ans2[num2].dis = dis;
    head2[from] = num2;
}
void dijkstra(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    priority_queue<pp,vector<pp>,cmp> pq;
    pq.push(pp(0,s));

    while(pq.size())
    {
        pp t = pq.top();
        pq.pop();
        int u = t.second;

        if(dis[u] < t.first)
        {
            continue;
        }

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                pq.push(pp(dis[v],v));
            }
        }
    }
}
void dijkstra2(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis2[i] = INF;
    }
    dis2[s] = 0;
    priority_queue<pp,vector<pp>,cmp> pq;
    pq.push(pp(0,s));

    while(pq.size())
    {
        pp t = pq.top();
        pq.pop();
        int u = t.second;

        if(dis2[u] < t.first)
        {
            continue;
        }

        for(int i = head2[u];i;i = ans2[i].next)
        {
            int v = ans2[i].to;
            if(dis2[v] > dis2[u] + ans2[i].dis)
            {
                dis2[v] = dis2[u] + ans2[i].dis;
                pq.push(pp(dis2[v],v));
            }
        }
    }
}
int main()
{
    n = read(),m = read(),t = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge2(b,a,c);
    }
    dijkstra(t);
    dijkstra2(t);
    int max = -1;

    for(int i = 1;i <= n;i ++)
    {
        int count = dis[i] + dis2[i];
        if(count > max)
        {
            max = count;
        }
    }
    printf("%d",max);

    return 0;
}