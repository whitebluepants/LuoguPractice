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
int indegree[101];
int head[101];
int dis[101];
int vis[101];
int n,m,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        indegree[b] ++;
    }

    priority_queue<int> pq;
    for(int i = 0;i < n;i ++)
    {
        if(!indegree[i])
        {
            pq.push(i);
        }
    }

    while(pq.size())
    {
        int temp = pq.top();
        pq.pop();

        vis[temp] = 1;

        for(int i = head[temp];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] < dis[temp] + ans[i].dis)
            {
                dis[v] = dis[temp] + ans[i].dis;
            }
            if(-- indegree[v] == 0)
            {
                pq.push(v);
            }
        }
    }

    int max = -1;
    for(int i = 0;i < n;i ++)
    {
        if(vis[i] == 0)
        {
            printf("Impossible");
            return 0;
        }
        if(dis[i] > max)
        {
            max = dis[i];
        }
    }

    printf("%d",max);

    return 0;
}