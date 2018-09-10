#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
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
node ans[200001];
int head[100001];
int dis[100001];
int n,m,num;
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
        dis[i] = -1;
    }
    dis[s] = 1;
    priority_queue<pp> pq;
    pq.push(pp(1,s));

    while(pq.size())
    {
        pp t = pq.top();
        pq.pop();
        int u = t.second;

        if(dis[u] > t.first)
        {
            continue;
        }

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] < dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                pq.push(pp(dis[v],v));
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
        addedge(b,a,1);
    }

    for(int i = 1;i <= n;i ++)
    {
        dijkstra(i);
        int max = -1;
        for(int j = 1;j <= n;j ++)
        {
            if(dis[j] > max)
            {
                max = dis[j];
            }
        }
        printf("%d\n",max);
    }

    return 0;
}