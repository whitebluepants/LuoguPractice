#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();
    int ans[100] = {};
    int sum = 0;    
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
        sum += ans[i];
    }

    int t = sum / n;
    int count = 0;
    for(int i = n - 1;i >= 0;i --)
    {
        if(ans[i] == t)
        {
            continue;
        }
        else if(ans[i] < t)
        {
            ans[i - 1] -= (t - ans[i]);
            ans[i] = t;
        }
        else if(ans[i] > t)
        {
            ans[i - 1] += (ans[i] - t);
        }
        count ++;
    }
    printf("%d",count);

    return 0;
}