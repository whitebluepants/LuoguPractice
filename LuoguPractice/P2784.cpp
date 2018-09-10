#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef pair<double,int> pp;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch= getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
double readd()
{
    char ch = getchar();
    double x = 0,f = 1;
    int ff = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')ff = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    while(ch < '0' || ch > '9'){ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';f = f * 0.1;ch = getchar();}
    return ff?f*x:-1*f*x;
}
struct node
{
    int next,to;
    double dis;
};
node ans[2000001];
double dis[5001];
int head[5001];
int n,m,s,t,num;
double INF = -9999999.9999;
void addedge(int from,int to,double dis)
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
        dis[i] = INF;
    }
    dis[s] = 1;
    
    priority_queue<pp> pq; // 要用大根堆 因为要求最长路而不是最短
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
            if(dis[v] < dis[u] * ans[i].dis)
            {
                dis[v] = dis[u] * ans[i].dis;
                pq.push(pp(dis[v],v));
            }
        }
    }
}
int main()
{
    n = read(),m = read(),s = read(),t = read();
    
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(); double c = readd();
        addedge(a,b,c);
    }
    dijkstra(s);
    
    if(dis[t] == INF)
    {
        printf("orz");
    }
    else
    {
        printf("%.4f",dis[t]);
    }
    return 0;
}