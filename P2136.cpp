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
node ans[10001];
int head[1001];
int dis[1001];
bool visited[1001];
int visit[1001];
int n,m,num;
void addedge(int from,int to,int dis)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    ans[num].dis = dis;
    head[from] = num;
}
int spfa(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;

    queue<int> q;
    q.push(s);

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
                    if(++ visit[v] > n)
                    {
                        return -1;
                    }
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
        addedge(a,b,-1*c);
    }
    int t1 = spfa(1);
    int ans1 = dis[n];
    int t2 = spfa(n);
    int ans2 = dis[1];
    if(t1 == -1 || t2 == -1)
    {
        printf("Forever love");
    }
    else
    {
        printf("%d",ans1 > ans2?ans2:ans1);
    }
    return 0;
}