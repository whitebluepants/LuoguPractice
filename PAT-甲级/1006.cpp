#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
struct node
{
    int h1,m1,s1;
    int h2,m2,s2;
    char name[16];
};
node ans[1000000];
bool cmp1(node a,node b)
{
    if(a.h1 == b.h1)
    {
        if(a.m1 == b.m1)
        {
            return a.s1 < b.s1;
        }
        return a.m1 < b.m1;
    }
    return a.h1 < b.h1;
}
bool cmp2(node a,node b)
{
    if(a.h2 == b.h2)
    {
        if(a.m2 == b.m2)
        {
            return a.s2 > b.s2;
        }
        return a.m2 > b.m2;
    }
    return a.h2 > b.h2;
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        scanf("%s %d:%d:%d %d:%d:%d ",ans[i].name,&ans[i].h1,&ans[i].m1,&ans[i].s1,&ans[i].h2,&ans[i].m2,&ans[i].s2);
    }
    sort(ans,ans + n,cmp1);
    printf("%s ",ans[0].name);
    sort(ans,ans + n,cmp2);
    printf("%s",ans[0].name);

    return 0;
}