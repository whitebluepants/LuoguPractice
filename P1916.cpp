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
int ans[100001];
int main()
{
    int n = read(),m = read(),k = read(),w = read(),r = read();
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    int towerCount = m / k;
    int damage = towerCount * w;
    int t = 0,i = 0;
    sort(ans,ans + n);
    while(t < r)
    {
        ans[i] -= damage;
        t ++;
        if(ans[i] < 0)
        {
            i ++;
        }
    }
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        if(ans[i] >= 0)
        {
            count ++;
        }
    }

    printf("%d",count);
    
    return 0;
}