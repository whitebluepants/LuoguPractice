#include <stdio.h>
#include <queue>
#include <vector>
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
};
struct cmp
{
    bool operator () (int &a,int &b)
    {
        return a > b;
    }
};
node ans[1000010];
int Hash[1010];
int head[50001];
int indegree[50001];
int flag[50001];
int num,count;
void addedge(int from,int to)
{
    ans[++ num].next = head[from];
    ans[num].to = to;
    head[from] = num;
    indegree[to] ++;
}
int main()
{
    // freopen("in.txt","r",stdin);
    int TableSize = read();
	
	for(int i = 0;i < TableSize;i ++)
	{
		Hash[i] = read();
	}

    for(int i = 0;i < TableSize;i ++)
    {
        if(Hash[i] >= 0)
        {
            flag[Hash[i]] = 1;
            int index = Hash[i] % TableSize;

            while(Hash[index] != Hash[i])
            {
                addedge(Hash[index],Hash[i]);
                index ++;
                if(index >= TableSize)
                {
                    index = 0;
                }
            }
        }
    }

    priority_queue<int,vector<int>,cmp> pq;
    for(int i = 0;i < TableSize;i ++)
    {
        if(Hash[i] >= 0 && indegree[Hash[i]] == 0)
        {
            pq.push(Hash[i]);
        }
    }

    int f = 0;
    while(pq.size())
    {
        if(f)
        {
            printf(" ");
        }
        int t = pq.top();
        pq.pop();

        printf("%d",t);
        f = 1;

        for(int i = head[t];i;i = ans[i].next)
        {
            int v = ans[i].to;
            indegree[v] --;
            if(indegree[v] == 0)
            {
                pq.push(v);
            }
        }
    }
    
    return 0;
}