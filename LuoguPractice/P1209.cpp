#include <algorithm>
#include <stdio.h>
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
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int ans[201] = {};
    int d[201] = {};
    int n = read(),m = read(),s = read();

    if(n >= s)
    {
        printf("%d",s);
        return 0;
    }

    for(int i = 0;i < s;i ++)
    {
        ans[i] = read();
    }
    sort(ans,ans + s);
    for(int i = 0;i < s - 1;i ++)
    {
        d[i] = ans[i + 1] - ans[i];
    }
    sort(d,d + s - 1,cmp);
    int sum = ans[s  - 1] - ans[0] + 1;

    for(int i = 0;i < n - 1;i ++)
    {
        sum -= d[i];
        sum ++;
    }
    printf("%d",sum);

    return 0;
}