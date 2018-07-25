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
    int n = read(),m = read();
    int ans[1001] = {};

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }

    for(int i = 0;i < m;i ++)
    {
        int max = -1,t;
        for(int j = 1;j <= n;j ++)
        {
            if(ans[j] > max)
            {
                max = ans[j];
                t = j;
            }
        }
        printf("%d\n",t);
        int d1 = ans[t] / (n - 1);
        int d2 = ans[t] % (n - 1);
        ans[t] = 0;
        for(int j = 1,k = d2;j <= n;j ++)
        {

            if(j != t)
            {
                ans[j] += d1;
                if(k > 0)
                {
                    ans[j] ++;
                    k --;
                }
            }
        }
    }
    return 0;
}