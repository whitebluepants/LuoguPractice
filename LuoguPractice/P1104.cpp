#include <stdio.h>
#include <algorithm>
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
    char s[21];
    int year,month,day,t;
};
bool cmp(node a,node b)
{
    if(a.year == b.year && a.month == b.month && a.day == b.day)
    {
        return a.t > b.t;
    }
    if(a.year != b.year)
    {
        return a.year < b.year;
    }
    if(a.month != b.month)
    {
        return a.month < b.month;
    }
    return a.day < b.day;
}
node ans[101];
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        scanf("%s",ans[i].s);
        ans[i].year = read(),ans[i].month = read(),ans[i].day = read();
        ans[i].t = i;
    }
    sort(ans + 1,ans + n + 1,cmp);
    for(int i = 1;i <= n;i ++)
    {
        printf("%s\n",ans[i].s);
    }
    return 0;
}
