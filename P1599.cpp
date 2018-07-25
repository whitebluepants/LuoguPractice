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
int main()
{
    int n = read();
    int ans[100001] = {};
    
    int count = 0,fmoney = 0,money = 0,j = 0,t = 0,flag = 0;
    for(int i = 0;i < n;i ++)
    {
        int m = read();
        if(m > 0)
        {
            money += m;
            if(money >= -1 * fmoney && fmoney != 0)
            {
                count += (i - t) * 2;
                money += fmoney;
                fmoney = 0;
                flag = 0;
            }
        }
        else
        {
            if(money >= m * -1)
            {
                money += m;
            }
            else
            {
                fmoney += m;
                if(flag == 0)
                {
                    t = i;
                    flag = 1;
                }
            }
        }
        count ++;
    }

    printf("%d",count);

    return 0;
}