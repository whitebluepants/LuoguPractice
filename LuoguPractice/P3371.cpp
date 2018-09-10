/* 
    Bellman ford
                */
#include <stdio.h>
#define INF 2147483647
using namespace std;
struct node
{
    int from,to,dis;
};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
node ans[500001] = {};
int dp[10001] = {};
int main()
{
    int n = read(),m = read(),s = read();
    
    for(int i = 1;i <= m;i ++)
    {
        ans[i].from = read();
        ans[i].to = read();
        ans[i].dis = read();
    }

    for(int i = 1;i <= n;i ++)
    {
        dp[i] = INF;
    }
    dp[s] = 0;

    for(int i = 1;i <= n - 1;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            if(dp[ans[j].from] != INF && dp[ans[j].to] > dp[ans[j].from] + ans[j].dis)
            {
                dp[ans[j].to] = dp[ans[j].from] + ans[j].dis;
            }
        }
    }

    for(int i = 1;i <= n;i ++)
    {
        printf("%d ",dp[i]);
    }

    return 0;
}

/*-----------------------------*/

/*
    Spfa
            */
#include <stdio.h>
#include <queue>
#define INF 2147483647
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < ' 0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
struct node
{
    int next,to,dis;
};
node ans[500001];
int head[10001];
int dis[10001];
int n,m,s;
bool visited[10001];
void addedge(int i,int from,int to,int dis)
{
    ans[i].next = head[from];
    ans[i].to = to;
    ans[i].dis = dis;
    head[from] = i;
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
        int t = q.front();
        q.pop();
        visited[t] = false;
        
        for(int i = head[t];i;i = ans[i].next)
        {
            int v = ans[i].to;
            if(dis[v] > dis[t] + ans[i].dis)
            {
                dis[v] = dis[t] + ans[i].dis;
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
}
int main()
{
    n = read(),m = read(),s = read();
    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(i,a,b,c);
    }

    spfa(s);

    for(int i = 1;i <= n;i ++)
    {
        printf("%d ",dis[i]);
    }

    return 0;
}

/*-----------------------------*/

/*
    Dijkstra + Heap
                    */
#include <stdio.h>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
#define INF 2147483647
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
    int next,to,dis;
};
struct cmp
{
    bool operator () (pp &a, pp &b)
    {
        return a.first > b.first;
    }
};
int n,m,s;
node ans[500001];
int head[10001];
int dis[10001];
void addedge(int i,int from,int to,int dis)
{
    ans[i].next = head[from];
    ans[i].to = to;
    ans[i].dis = dis;
    head[from] = i;
}
void dijkstra(int s)
{
    for(int i = 1;i <= n;i ++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    
    priority_queue<pp,vector<pp>,cmp> pq;
    pq.push(pp(0,s));

    while(pq.size())
    {
        pp t = pq.top();
        pq.pop();
        
        int u = t.second;

        if(t.first > dis[u])
        {
            continue;
        }

        for(int i = head[u];i;i = ans[i].next)
        {
            if(dis[ans[i].to] > dis[u] + ans[i].dis)
            {
                dis[ans[i].to] = dis[u] + ans[i].dis;

                pq.push(pp(dis[ans[i].to],ans[i].to));
            }
        }
    }

    return ;
}
int main()
{
    n = read(),m = read(),s = read();

    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        addedge(i,a,b,c);
    }
    dijkstra(s);

    for(int i = 1;i <= n;i ++)
    {
        printf("%d ",dis[i]);
    }

    return 0;
}

/*-----------------------------*/
/*
    Floyd
            */
#include <stdio.h>
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
int dp[10001][10001];
int main()
{
    int n = read(),m = read(),s = read();
    
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INF;
            }
        }
    }

    for(int i = 1;i <= m;i ++)
    {
        int a = read(),b = read(),c = read();
        if(dp[a][b] > c)
        {
            dp[a][b] = c;
        }
    }

    for(int k = 1;k <= n;k ++)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(i != k && dp[i][k] != INF)
            {
                for(int j = 1;j <= n;j ++)
                {
                    if(dp[k][j] != INF && dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        printf("%d ",dp[s][i]);
    }

    return 0;
}