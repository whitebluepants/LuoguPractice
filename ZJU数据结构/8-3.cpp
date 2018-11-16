#include <queue>
#include <stdio.h>
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
struct edge
{
    int next,to,dis;
};
edge ans[100010];
edge ans2[100010];
int indegree[101];
int indegree2[101];
int head[101];
int head2[101];
int dis[101];
int dis2[101];
int vis[101];
int n,m,num,num2;
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
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge2(b,a,c);
        indegree[b] ++;
        indegree2[a] ++;
    }
    priority_queue<int> pq;
    for(int i = 1;i <= n;i ++)
    {
        if(!indegree[i])
        {
            pq.push(i);
        }
    }

    while(pq.size())
    {
        int u = pq.top();
        pq.pop();

        vis[u] = 1;

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] < dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
            }
            if(-- indegree[v] == 0)
            {
                pq.push(v);
            }
        }
    }

    int max = -1;
    for(int i = 1;i <= n;i ++)
    {
        if(vis[i] == 0)
        {
            printf("0");
            return 0;
        }
        if(max < dis[i])
        {
            max = dis[i];
        }
    }
    printf("%d\n",max);
    priority_queue<int> pq2;
    for(int i = 1;i <= n;i ++)
    {
        dis2[i] = INF;
        if(!indegree2[i])
        {
            // dis2[i] = dis[i];
            dis2[i] = max; // 需要把每个终点都初始化为最短完全完成时间 而非自身完成时间
            pq2.push(i);
        }
    }

    while(pq2.size())
    {
        int u = pq2.top();
        pq2.pop();
        
        for(int i = head2[u];i;i = ans2[i].next)
        {
            int v = ans2[i].to;
            if(dis2[v] > dis2[u] - ans2[i].dis)
            {
                dis2[v] = dis2[u] - ans2[i].dis;
            }
            if(-- indegree2[v] == 0)
            {
                pq2.push(v);
            }
        }
    }

    for(int i = 1;i <= n;i ++)
    {
        int u = i;
        for(int j = head[u];j;j = ans[j].next)
        {
            int v = ans[j].to;
            if(dis2[v] - dis[u] - ans[j].dis == 0)
            {
                printf("%d->%d\n",u,v);
            }
        }
    }

    return 0;
}