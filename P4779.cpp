#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>
#define Max 99999999
using namespace std;
typedef pair<int,int> pp;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*1;
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
node ans[500001];
int dis[100001];
int head[100001];
int n,m,s,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void dijkstra(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = Max;
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
int main()
{
    n = read(),m = read(),s = read();
    
    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
    }
    dijkstra(s);

    for(int i = 1;i <= n;i ++)
    {
        if(dis[i] == Max)
        {
            printf("2147483647 ");
        }
        else
        {
            printf("%d ",dis[i]);
        }
    }

    return 0;
}