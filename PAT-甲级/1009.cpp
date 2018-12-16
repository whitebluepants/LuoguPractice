// 注意指数为0 但系数不为0的时候也要输出
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
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
    int exp;
    double c;
    int flag;
};
node ans[3000] = {};
double a[11][2];
double b[11][2];
bool cmp(node a,node b)
{
    if(a.flag == b.flag)
    {
        return a.exp > b.exp;
    }
    return a.flag > b.flag;
}
int main()
{
    int n = read(),m;

    for(int i = 0;i < n;i ++)
    {
        scanf("%lf %lf",&a[i][0],&a[i][1]);
    }

    m = read();

    for(int i = 0;i < m;i ++)
    {
        scanf("%lf %lf",&b[i][0],&b[i][1]);
    }

    int max = -1;
    for(int i = 0;i < n;i ++)
    {
        double e = a[i][0];
        double c = a[i][1];

        for(int j = 0;j < m;j ++)
        {
            int newe = (int)(e + b[j][0]);
            double newc = c * b[j][1];
			
            ans[newe].flag = 1;
            ans[newe].exp = newe;
            ans[newe].c += newc;

            if(newe > max)
            {
                max = newe;
            }
        }
    }

    sort(ans,ans + max + 1,cmp);

    int count = 0;
    int flag = 0;
    for(int i = 0;ans[i].flag != 0;i ++)
    {
        if(ans[i].c != 0)
        {
            count ++;
        }   
    }

    printf("%d",count);

    for(int i = 0;ans[i].flag != 0;i ++)
    {
        if(ans[i].c != 0)
        {
            printf(" %d %.1f",ans[i].exp,ans[i].c);
        }
    }

    return 0;
}