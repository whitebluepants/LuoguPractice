#include <queue>
#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int,int> pp;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
struct edge
{
    int next,to;
};
edge ans[700005];
int head[10005];
int vis[10005];
int num,n,m,count;
void addedge(int from,int to)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    head[from] = num;
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read();
        addedge(a,b);
        addedge(b,a);
    }

    for(int i = 1;i <= n;i ++)
    {
        memset(vis,0,sizeof(vis));
        count = 0;
        
        queue<pp> q;
        q.push(pp(i,0));

        while(q.size())
        {
            pp temp = q.front();
            q.pop();
            
            int t = temp.first;

            for(int i = head[t];i;i = ans[i].next)
            {
                int v = ans[i].to;
                if(!vis[v] && temp.second + 1 <= 6)
                {
                    count ++;
                    vis[v] = 1;
                    q.push(pp(v,temp.second + 1));
                }
            }
        }

        printf("%d: %.2f%c\n",i,1.0*count/n*100,'%');
    }

    return 0;
}