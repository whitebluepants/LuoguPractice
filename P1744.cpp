#include <stdio.h>
#include <queue>
#include <math.h>
#define INF 99999999
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
    int next,to;
    double dis;
};
node ans[2002];
int x[101],y[101];
int n,m,num;
double dis[101];
int visited[101];
int head[101];
void addedge(int from,int to,double dis)
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
            if(dis[v] > dis[u] + ans[i].dis)
            {
                dis[v] = dis[u] + ans[i].dis;
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }
}
int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
    {
        x[i] = read(),y[i] = read();
    }

    m = read();    
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read();
        double c = sqrt(pow((x[a] - x[b]),2) + pow((y[a] - y[b]),2));
        addedge(a,b,c);
        addedge(b,a,c);
    }

    int s = read(),t = read();
    spfa(s);

    printf("%.2f",dis[t]);

    return 0;
}