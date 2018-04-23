#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
struct point
{
    int x;
    int y;
    int d;
};
int dx[12]={2,-2,2,-2,1,1,-1,-1,2,2,-2,-2};
int dy[12]={2,2,-2,-2,2,-2,2,-2,1,-1,1,-1};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int used[50][50] = {};
int main()
{
    int x1 = read(),y1 = read(),x2 = read(),y2 = read();
    int min1 = 99999,min2 = 99999;
    int d1 = 0,d2 = 0;

    queue<struct point> q1;
    queue<struct point> q2;

    struct point a = {x1,y1,0};
    struct point b = {x2,y2,0};
    q1.push(a);
    q2.push(b);

    used[x1][y1] = 1;
    while(q1.size())
    {
        struct point p = q1.front();
        q1.pop();

        if(p.x == 1 && p.y == 1)
        {
            if(p.d < min1)
            {
                min1 = p.d;
            }
        }
        for(int i = 0;i < 12;i ++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= 1 && nx <= 50 && ny >= 1 && ny <= 50 && used[nx][ny] == 0)
            {
                struct point np = {nx,ny,p.d + 1};
                used[nx][ny] = 1;
                q1.push(np);
            }
        }
    }

    memset(used,0,sizeof(used));
    used[x2][y2] = 1;

    while(q2.size())
    {
        struct point p = q2.front();
        q2.pop();

        if(p.x == 1 && p.y == 1)
        {
            if(p.d < min2)
            {
                min2 = p.d;
            }
        }
        for(int i = 0;i < 12;i ++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= 1 && nx <= 50 && ny >= 1 && ny <= 50 && used[nx][ny] == 0)
            {
                struct point np = {nx,ny,p.d + 1};
                used[nx][ny] = 1;
                q2.push(np);
            }
        }
    }

    printf("%d\n%d",min1,min2);
    return 0;
}