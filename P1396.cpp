#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 9999999
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
struct node
{
    int next,to,dis;
};
node ans[40002];
int dis[10001];
int head[10001];
int visited[10001];
int n,m,s,t,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
void spfa(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(q.size())
    {
        int u = q.front();
        q.pop();
        visited[u] = 0;

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > max(dis[u],ans[i].dis))
            {
                dis[v] = max(dis[u],ans[i].dis);
                if(!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    n = read(),m = read(),s = read(),t = read();
    
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge(b,a,c);
    }
    spfa(s);

    printf("%d",dis[t]);

    return 0;
}