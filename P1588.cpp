#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
struct node
{
    int x,count;
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
int map[100001] = {};
int main()
{
    int t = read();
    for(int i = 0;i < t;i ++)
    {
        int x = read(),y = read(),minn = 999999999;
        memset(map,0,sizeof(map));
        queue<node> q;
        node a = {x,0};

        q.push(a);
        while(q.size())
        {
            node n = q.front();
            q.pop();
            
            if(n.x == y)
            {
                minn = n.count;
                break;
            }
            
            for(int i = 0;i < 3;i ++)
            {
                int nx;
                if(i == 0)
                {
                    nx = n.x - 1;
                }
                else if(i == 1)
                {
                    nx = n.x + 1;
                }
                else if(i == 2)
                {
                    nx = n.x * 2;
                }
                if(nx > 0 && nx <= 100000 && map[nx] == 0)
                {
                    map[nx] = 1;
                    node x = {nx,n.count + 1};
                    q.push(x);
                }
            }
        }
        printf("%d\n",minn);
    }

    return 0;
}