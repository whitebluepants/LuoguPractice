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
    int a[2010];
};
node ans[1010];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n = read(),m = read(),k = read();
    int typenum[1010] = {};

    for(int i = 1;i <= k;i ++)
    {
        typenum[i] = read();
    }

    for(int i = 1;i <= n;i ++)
    {
        int a = read(),b = read();
        ans[b].a[0] ++;
        ans[b].a[ans[b].a[0]] = a;
    }

    for(int i = 1;i <= n;i ++)
    {
        sort(ans[i].a + 1,ans[i].a + 1 + ans[i].a[0],cmp);
    }
    
    int index[1010] = {};
    int count = 0;
    for(int i = 1;i <= m;i ++)
    {
        int max = 0,t;
        for(int j = 1;j <= k;j ++)
        {
            if(index[j] >= ans[j].a[0] || index[j] >= typenum[j])
            {
                continue;
            }
            if(ans[j].a[index[j] + 1] > max)
            {
                t = j;
                max = ans[j].a[index[j] + 1];   
            }
        }
        count += max;
        index[t] ++;
    }
    
    printf("%d",count);
    
    return 0;
}