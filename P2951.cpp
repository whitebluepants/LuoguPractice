#include <stdio.h>
#include <queue>
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
    int next,to,dis;
};
node ans[100010];
int head[20001];
int dis[20001];
bool visited[20001];
int n,m,num;
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
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read();
        addedge(a,b,1);
        addedge(b,a,1);
    }
    spfa(1);

    int max = -1,count = 0,t;
    
    for(int i = 1;i <= n;i ++)
    {
        if(dis[i] > max)
        {
            max = dis[i];
            count = 1;
            t = i;
        }
        else if(dis[i] == max)
        {
            count ++;
        }
    }
    printf("%d %d %d",t,dis[t],count);

    return 0;
}