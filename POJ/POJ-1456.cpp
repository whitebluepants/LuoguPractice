#include <algorithm>
#include <stdio.h>
#include <string.h>
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
    int price,time;
};
bool cmp(node a,node b)
{
    return a.price > b.price;
}
node ans[10000];
int vis[10001];
int main()
{
    int n;

    while(scanf("%d",&n) != EOF)
    {
        int max = -1;
        for(int i = 0;i < n;i ++)
        {
            ans[i].price = read(),ans[i].time = read();
            if(ans[i].time > max)
            {
                max = ans[i].time;
            }
        }
        
        sort(ans,ans + n,cmp);
        
        memset(vis,0,sizeof(vis));
        int count = 0;
        for(int i = 0;i < n;i ++)
        {
            if(vis[ans[i].time] == 0)
            {
                count += ans[i].price;
                vis[ans[i].time] = 1;
            }
            else
            {
                for(int j = ans[i].time - 1;j >= 1;j --)
                {
                    if(vis[j] == 0)
                    {
                        vis[j] = 1;
                        count += ans[i].price;
                        break;
                    }
                }
            }
        }

        printf("%d\n",count);
    }

    return 0;
}