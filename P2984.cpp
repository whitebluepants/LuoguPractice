#include <stdio.h>
#include <queue>
#define INF 2147483647
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
node ans[200010];
int head[50001];
int dis[50001];
bool visited[50001];
int n,m,count,num;
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
    visited[s] = true;

    while(q.size())
    {
        int u = q.front();
        q.pop();
        visited[u] = false;

        for(int i = head[u];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    n = read(),m = read(),count = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge(b,a,c);
    }
    spfa(1);
    for(int i = 1;i <= count;i ++)
    {
        int a = read(),b = read();
        printf("%d\n",dis[a] + dis[b]);
    }
    return 0;
}