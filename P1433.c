#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n;
double min = 99999;
double dd[15][16] = {};
double a[15][2] = {};
int used[15] = {};
void dfs(int i,int t,double d)
{
    if(d > min)
    {
        return;
    }
    if(i == n)
    {
        if(d < min)
        {
            min = d;
        }
    }

    for(int j = 0;j < n;j ++)
    {
        if(used[j])
        {
            continue;
        }
        used[j] = 1;
        d += dd[j][t];

        dfs(i + 1,j,d);
        
        d -= dd[j][t];
        used[j] = 0;
    }
}
int main()
{
    n = read();    
    for(int i = 0;i < n;i ++)
    {
        scanf("%lf %lf",&a[i][0],&a[i][1]);
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n + 1;j ++)
        {
            if(j == n)
            {
                dd[i][j] = sqrt(pow(a[i][0] - 0,2) + pow(a[i][1] - 0,2));
            }
            else
            {
                dd[i][j] = sqrt(pow(a[i][0] - a[j][0],2) + pow(a[i][1] - a[j][1],2));
            }
        }
    }
    dfs(0,n,0);

    printf("%.2f",min);

    return 0;
}