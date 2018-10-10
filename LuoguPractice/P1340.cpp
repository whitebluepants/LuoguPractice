#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
struct node
{
    int from,to,dis;
    int flag;
    bool operator < (const node &a) const
    {
        return dis < a.dis;
    }
};
bool cmp(node a,node b)
{
    return a.dis < b.dis;
}
int father[30000];
node ans[650000];
int n,m;
int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x]);
    }
}
void unionSet(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx == rooty)
    {
        return ;
    }
    father[rootx] = rooty;
}
void kruskal(int index,node x)
{
    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }
    node temp = x;
    for(int i = index;i >= 1;i --)
    {
        if(ans[i - 1].dis >= temp.dis)
        {
            ans[i] = ans[i - 1];
        }
        else if(i == 1 || ans[i - 1].dis < temp.dis)
        {
            ans[i] = temp;
            break;
        }
    }

    int sum = 0;
    for(int i = 1;i <= index;i ++)
    {
        int from = ans[i].from;
        int to = ans[i].to;

        if(find(from) == find(to))
        {
            continue;
        }
        unionSet(from,to);
        sum += ans[i].dis;
    }
    
    int t = find(1);
    for(int i = 1;i <= n;i ++)
    {
        if(find(i) != t)
        {
            printf("-1\n");
            return ;
        }
    }
    printf("%d\n",sum);

    return ;
}
int main()
{
    n = read(),m = read();
    
    for(int i = 1;i <= m;i ++)
    {
        ans[i].from = read(),ans[i].to = read(),ans[i].dis = read();
        if(i + 1 < n)
        {
            printf("-1\n");
            sort(ans + 1,ans + 1 + i,cmp);
        }
        else
        {
            kruskal(i,ans[i]);
        }
    }

    return 0;
}