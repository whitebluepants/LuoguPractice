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
    char s[6];
    int year,month,day;
    bool operator < (const node &a) const
    {
        if(year == a.year)
        {
            if(month == a.month)
            {
                return day < a.day;
            }
            return month < a.month;
        }
        return year < a.year;
    }
};
node ans[100001];
int main()
{
    int n = read();

    int cnt = 0;
    for(int i = 0;i < n;i ++)
    {
        int a,b,c;
        scanf("%s %d/%d/%d",ans[cnt].s,&a,&b,&c);

        if(a > 2014 || (a == 2014 && b > 9) || (a == 2014 && b == 9 && c > 6))
        {
            continue;
        }
        if(2014 - a > 200 || (2014 - a == 200 && b < 9) || (2014 - a == 200 && b == 9 && c < 6))
        {
            continue;
        }

        ans[cnt].year = a,ans[cnt].month = b,ans[cnt ++].day = c;
    }

    sort(ans,ans + cnt);
    if(cnt == 0)
    {
        printf("0");
    }
    else
    {
        printf("%d %s %s",cnt,ans[0].s,ans[cnt - 1].s);
    }
    

    return 0;
}