#include <stdio.h>
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
node ans[200010];
int head[2001];
double dis[2001];
bool visited[2001];
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
    dis[s] = 100;
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
            if(dis[v] > dis[u] / (1 - (1.0 * ans[i].dis / 100)))
            {
                dis[v] = dis[u] / (1 - (1.0 * ans[i].dis / 100));
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
    n = read(),m = read();
    
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(a,b,c);
        addedge(b,a,c);
    }
    int s = read(),t = read();
    spfa(s);

    printf("%.8f",dis[t]);

    return 0;
}