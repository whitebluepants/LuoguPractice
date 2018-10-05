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
    double count,price; // 有测试点是实数
    double aver;
    bool operator < (const node &a) const
    {
        return aver > a.aver;
    }
};
node ans[1001];
int main()
{
    int n = read(),m = read(),cnt = 0;

    for(int i = 0;i < n;i ++)
    {
        scanf("%lf",&ans[i].count);
    }
    for(int i = 0;i < n; i ++)
    {
        scanf("%lf",&ans[i].price);
        ans[i].aver = ans[i].price / ans[i].count;
    }
    sort(ans,ans + n);

    int i = 0;
    double money = 0;
    while(cnt != m && i != n)
    {
        if(m - cnt >= ans[i].count)
        {
            money += ans[i].price;
            cnt += ans[i].count;
            i ++;
        }
        else
        {
            money += (m - cnt) * ans[i].aver;
            cnt = m;
        }
    }
    printf("%.2f",money);

    return 0;
}