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
    int number;
    int w;
};
bool cmp(node a,node b)
{
    if(a.w == b.w)
    {
        return a.number < b.number;
    }
    return a.w > b.w;
}
int main()
{
    int n = read(),k = read();
    int ans[11] = {};
    for(int i = 1;i <= 10;i ++)
    {
        ans[i] = read();
    }

    node a[20001];

    for(int i = 1;i <= n;i ++)
    {
        a[i].number = i;
        a[i].w = read();
    }
    
    sort(a + 1,a + n + 1,cmp);
    
    for(int i = 1;i <= n;i ++)
    {
        a[i].w += ans[(i - 1) % 10 + 1];
    }
    
    sort(a + 1,a + n + 1,cmp);
    
    for(int i = 1;i <= k;i ++)
    {
        printf("%d ",a[i].number);
    }

    return 0;
}