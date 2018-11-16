#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define Max 999999999
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
    int next,to,dis,mon;
};
node ans[500010];
int head[501];
int dis[501];
int money[501];
int n,m,s,d,num;
void addedge(int from,int to,int dis,int mon)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    ans[num].mon = mon;
    head[from] = num;
}
struct cmp
{
    bool operator() (pp a,pp b)
    {
        return a.first > b.first;
    }
};
void dijkstra(int s)
{
    for(int i = 0;i < n;i ++)
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
            if(dis[u] + ans[i].dis <= dis[v])
            {
                if(dis[u] + ans[i].dis < dis[v])
                {
                    dis[v] = dis[u] + ans[i].dis;
                    money[v] = money[u] + ans[i].mon;
                    pq.push(pp(dis[v],v));
                }
                else if(money[v] > money[u] + ans[i].mon)
                {
                    money[v] = money[u] + ans[i].mon;
                    pq.push(pp(dis[v],v));
                }
            }
        }
    }
    return ;
}
int main()
{
    n = read(),m = read(),s = read(),d = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read(),d = read();
        addedge(a,b,c,d);
        addedge(b,a,c,d);
    }

    dijkstra(s);

    printf("%d %d",dis[d],money[d]);

    return 0;
}