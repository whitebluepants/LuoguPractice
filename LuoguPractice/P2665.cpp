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
int main()
{
    int n = read();
    int ans[200][2] = {};
    
    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read(), ans[i][1] = read();
    }
    
    double a[20000] = {};
    int k = 0;
    
    for(int i = 0;i < n - 1;i ++)
    {
        for(int j = i + 1;j < n;j ++)
        {
            int dx = ans[i][0] - ans[j][0];
            int dy = ans[i][1] - ans[j][1];

            if(dx == 0 && dy == 0)
            {
                continue;
            }
            if(dx == 0)
            {
                a[k ++] = 99999;
            }
            else if(dy == 0)
            {
                a[k ++] = 0;
            }
            else
            {
                a[k ++] = 1.0 * dy / dx;
            }
        }
    }
    int num = 1;
    sort(a,a + k);

    for(int i = 1;i < k;i ++)
    {
        if(a[i] - a[i - 1] > 0)
        {
            num ++;
        }
    }
    printf("%d",num);

    return 0;
}