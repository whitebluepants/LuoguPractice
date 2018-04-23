#include <stdio.h>
#include <queue>
using namespace std;
struct point
{
    int floor,count;
};
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read(),a = read(),b = read(),min = 9999999;
    int ans[200] = {};
    int record[201] = {};

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    queue<point> q;
    point p = {a,0};
    record[a] = 1;
    q.push(p);

    while(q.size())
    {
        point p = q.front();
        q.pop();
        
        if(p.floor == b)
        {
            if(p.count < min)
            {
                min = p.count;
            }
            break;
        }
        int up = p.floor + ans[p.floor - 1];
        int down = p.floor - ans[p.floor - 1];
        if(up > 0  && up <= b && !record[up])
        {
            point np = {up,p.count + 1};
            record[up] = 1;
            q.push(np);
        }
        if(down > 0 && down <= b && !record[down])
        {
            point np = {down,p.count + 1};
            record[down] = 1;
            q.push(np);
        }
    } 

    if(min == 9999999)
    {
        printf("-1");
    }
    else
    {
        printf("%d",min);
    }

    return 0;
}