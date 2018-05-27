#include <queue>
#include <stdio.h>
#define INF 9999999
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return f?x:x*-1;
}
struct node
{
    int next,to,dis;
};
int n,m,num;
int dis[2501] = {};
int head[2501] = {};
bool visited[2501] = {};
node ans[400005] = {};
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
                dis[v]= dis[u] + ans[i].dis;
                if(!visited[v])
                {
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
    spfa(1);
    
    printf("%d",dis[n]);

    return 0;
}