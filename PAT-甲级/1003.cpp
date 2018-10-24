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
    int next,to,dis,c;
};
struct cmp
{
    bool operator () (pp a,pp b)
    {
        return a.first > b.first;
    }
};
node ans[500010];
int count[501];
int head[501];
int dis[501];
int city[501];
int num,n,m,s,d;
int pathCount[501];
void addedge(int from,int to,int dis,int c)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    ans[num].c = c;
    head[from] = num;
}
void dijkstra(int s)
{
    for(int i = 0;i < n;i ++)
    {
        dis[i] = Max;
    }
    dis[s] = 0;
    count[s] = city[s];
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
            
            if(dis[v] >= dis[u] + ans[i].dis)
            {
                if(dis[v] > dis[u] + ans[i].dis)
                {
                    dis[v] = dis[u] + ans[i].dis;
                    pathCount[v] = 1;
                }
                else
                {
                    pathCount[v] ++;
                }
                /*
                    一开始理解错题目了 以为是求所有路径所能聚集的人数
                    直接写成count[v] = count[u] + ans[i].c;

                    原来是求相同最短路中所能聚集最多人的那一条路径的人数
                    需要重新开一个city数据保存每个城市的人数
                */
                if(count[v] < count[u] + ans[i].c + city[v])
                {
                    count[v] = count[u] + ans[i].c + city[v];
                }
                pq.push(pp(dis[v],v));
            }
        }
    }
    return ;
}
int main()
{
    n = read(),m = read(),s = read(),d = read();

    for(int i = 0;i < n;i ++)
    {
        pathCount[i] = 1;
        city[i] = read();
    }
    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c,count[b]);
        addedge(b,a,c,count[a]);
    }

    dijkstra(s);
    
    printf("%d %d",pathCount[d],count[d]);

    return 0;
}