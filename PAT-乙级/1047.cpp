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
    int flag;
    int count;
};
node ans[1005];
bool cmp(node a,node b)
{
    if(a.count == b.count)
    {
        return a.flag > b.flag;
    }
    return a.count > b.count;
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read(),c = read();
        ans[a].count += c;
        ans[a].flag = a;
    }

    sort(ans,ans + 1001,cmp);

    printf("%d %d",ans[0].flag,ans[0].count);

    return 0;
}