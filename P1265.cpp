#include <stdio.h>
#include <math.h>
#define INF 9999999
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
int p[5010][2];
bool vis[5001];
double dist[5001];
int n;
double caldis(int x,int y)
{
    int x1 = p[x][0],y1 = p[x][1];
    int x2 = p[y][0],y2 = p[y][1];
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int findMin()
{
    int v = -1;
    double e = INF;
    for(int i = 1;i <= n;i ++)
    {
        if(vis[i] == false && e > dist[i])
        {
            e = dist[i];
            v = i;
        }
    }
    return v;
}
double prim(int s)
{
    double sum = 0;
    for(int i = 1;i <= n;i ++)
    {
        dist[i] = INF;
    }

    for(int i = 1;i <= n;i ++)
    {
        double dis = caldis(s,i);
        if(dis < dist[i])
        {
            dist[i] = dis;
        }
    }
    vis[s] = true;

    while(1)
    {
        int v = findMin();
        if(v == -1)
        {
            break;
        }

        vis[v] = true;
        sum += dist[v];

        for(int i = 1;i <= n;i ++)
        {
            if(vis[i] == false)
            {
                double dis = caldis(v,i);
                if(dist[i] > dis)
                {
                    dist[i] = dis;
                }
            }
        }
    }

    return sum;
}
int main()
{
    n = read();

    for(int i = 1;i <= n;i ++)
    {
        p[i][0] = read(),p[i][1] = read();
    }

    double sum = prim(1);

    printf("%.2f",sum);

    return 0;
}