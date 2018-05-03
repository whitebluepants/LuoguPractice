#include <stdio.h>
#include <queue>
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
int main()
{
    int n = read(),m = read();
    priority_queue<int> q;

    for(int i = 1;i <= n;i ++)
    {
        int t = read();
        if(i > m)
        {
            int temp = q.top();
            if(temp > t)
            {
                q.pop();
                q.push(t);
            }
        }
        else
        {
            q.push(t);
        }
    }

    int ans[100000] = {};    
    for(int i = m - 1;i >= 0;i --)
    {
        ans[i] = q.top();
        q.pop();
    }

    for(int i = 0;i < m;i ++)
    {
        printf("%d\n",ans[i]);
    }
    
    return 0;
}