#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int ans[100010];
int main()
{
    int n = read();

    int sum = 0,l,r,left;
    int flag = 0,f = 0;
    int max = -9999999; // 防止一种情况 不全为负数, 但其中只有0
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
        if(ans[i] >= 0)
        {
            flag = 1;
        }
    }
    for(int i = 0;i < n;i ++)
    {   
        sum += ans[i];
        if(f == 0 && ans[i] >= 0)
        {
            left = i;
            f = 1;
        }

        if(sum > max)
        {
            max = sum;
            l = left;
            r = i;
        }

        if(sum < 0)
        {
            sum = 0;
            f = 0;
        }
    }

    if(flag == 0)
    {
        max = 0;
        l = 0;
        r = n - 1;
    }

    printf("%d %d %d",max,ans[l],ans[r]);

    return 0;
}