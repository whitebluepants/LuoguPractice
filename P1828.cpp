#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define INF 9999999
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
node ans[3000];
int head[801];
int dis[801];
int n,m,c,num;
int cow[501];
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void dijkstra(int s)
{
    for(int i = 1;i <= m;i ++)
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
int main()
{
    n = read(),m = read(),c = read();
    
    for(int i = 0;i < n;i ++)
    {
        cow[i] = read();
    }

    for(int i = 1;i <= c;i ++)
    {
        int a = read(),b = read(),d = read();
        addedge(a,b,d);
        addedge(b,a,d);
    }
    int min = INF;
    for(int i = 1;i <= m;i ++)
    {
        dijkstra(i);
        int count = 0;
        for(int j = 0;j < n;j ++)
        {
            count += dis[cow[j]];
        }
        if(count < min)
        {
            min = count;
        }
    }
    printf("%d",min);

    return 0;
}