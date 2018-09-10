#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#define INF 99999999
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
    int next,to,dis,cap;
};
struct cmp
{
    bool operator () (pp a,pp b)
    {
        return a.first > b.first;
    }
};
node ans[1010];
int head[501];
int dis[501][2];
int n,m,num,a;
void addedge(int from,int to,int dis,int cap)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    ans[num].cap = cap;
    head[from] = num;
}
void dijkstra(int s)
{
    // dis数组 0坐标用来记录距离 1坐标用来记录来到这个点所经过的管道的最小管道宽度
    for(int i = 1;i <= n;i ++)
    {
        dis[i][0] = INF;
        dis[i][1] = INF;
    }
    dis[s][0] = 0;

    priority_queue<pp,vector<pp>,cmp> pq;
    pq.push(pp(0,s));

    while(pq.size())
    {
        pp t = pq.top();
        pq.pop();
        int u = t.second;

        if(dis[u][0] < t.first)
        {
            continue;
        }

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            
            // 这部分有点长 但应该还是很容易看的懂..
            
            // 如果这条管道比最小的还要小 那么松弛操作中用该管道的宽度计算时间(因为要最小)
            if(dis[u][1] > ans[i].cap && dis[v][0] > dis[u][0] - (a / dis[u][1]) + ans[i].dis + (a / ans[i].cap)) 
            {
                dis[v][0] = dis[u][0] - (a / dis[u][1]) + ans[i].dis + (a / ans[i].cap);
                dis[v][1] = ans[i].cap;
                pq.push(pp(dis[v][0],v));
            }
            // 反之亦然 两种情况在松弛以后 要更新目的点的最小宽度 也就是dis[v][1]
            else if(dis[u][1] <= ans[i].cap && dis[v][0] > dis[u][0] - (a / dis[u][1]) + ans[i].dis + (a / dis[u][1]))
            {
                dis[v][0] = dis[u][0] - (a / dis[u][1]) + ans[i].dis + (a / dis[u][1]);
                dis[v][1] = dis[u][1];
                pq.push(pp(dis[v][0],v));
            }
        }
    }
}
int main()
{
    n = read(),m = read(),a = read();

    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read(),d = read();
        addedge(a,b,c,d);
        addedge(b,a,c,d);
    }
    
    dijkstra(1);

    printf("%d",dis[n][0]);

    return 0;
}