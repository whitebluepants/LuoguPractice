#include <stdio.h>
#include <math.h>
#define Max 999999999
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
int p[101][2];
int dis[101];
int vis[101];
int path[101];
double getFirstJump(int t)
{
    if(path[t] == 0)
    {
        int x1 = 0,y1 = 0;
        int x2 = p[t][0],y2 = p[t][1];
        return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    }
    else
    {
        getFirstJump(path[t]);
    }
}
void printPath(int t)
{
    if(t == 0)
    {   
        return;
    }
    printPath(path[t]);
    printf("%d %d\n",p[t][0],p[t][1]);
}
int main()
{
    int n = read(),k = read();

    if(7.5 + k >= 50) // 特判 直接在原点一步上岸
    {
        printf("1");
        return 0;
    }

    for(int i = 1;i <= n;i ++)
    {
        p[i][0] = read(),p[i][1] = read();
    }

    for(int i = 0;i <= n;i ++)
    {
        path[i] = -1;
    }
    for(int i = 1;i <= n;i ++)
    {
        int x1 = 0,y1 = 0,x2 = p[i][0],y2 = p[i][1];
        double d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
        if(d - 7.5 > k)
        {
            dis[i] = Max;
        }
        else
        {
            dis[i] = 1;
            path[i] = 0;
        }
    }

    while(1)
    {
        double t = Max;
        int v = -1;
        for(int i = 1;i <= n;i ++)
        {
            if(vis[i] == 0 && dis[i] < t)
            {
                t = dis[i];
                v = i;
            }
        }

        if(v == -1)
        {
            break;
        }

        vis[v] = 1;

        for(int i = 1;i <= n;i ++)
        {
            if(vis[i] == 0)
            {    
                int x1 = p[v][0],y1 = p[v][1];
                int x2 = p[i][0],y2 = p[i][1];
                double d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));

                if(d <= k && dis[v] + 1 < dis[i])
                {
                    dis[i] = dis[v] + 1;
                    path[i] = v;
                }
            }
        }
    }

    int minp = -1,minpDis = Max;
    for(int i = 1;i <= n;i ++)
    {
        int x = p[i][0],y = p[i][1];
        if(abs(x) + k >= 50 || abs(y) + k >= 50)
        {
            if(dis[i] != Max && minpDis >= dis[i])
            {
                if(minpDis == dis[i])
                {
                    double d1 = getFirstJump(minp);
                    double d2 = getFirstJump(i);
                    if(d2 < d1)
                    {
                        minp = i;
                        minpDis = dis[i];
                    }
                }
                else
                {
                    minp = i;
                    minpDis = dis[i];
                }
            }
        }
    }   
    
    if(minp == -1)
    {
        printf("0");
    }
    else
    {
        printf("%d\n",minpDis + 1);
        printPath(minp);
    }

    return 0;
}