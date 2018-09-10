#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n;
int main()
{
    n = read();
    int ans[21] = {};
    int map[21][21] = {};
    int sum[21] = {};
    int num[21] = {};

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }
    
    for(int i = 1;i <= n - 1;i ++)
    {
        for(int j = i + 1;j <= n;j ++)
        {
            map[i][j] = read();
        }
    }

    for(int i = n;i >= 1;i --)
    {
        sum[i] = ans[i];
        for(int j = i + 1;j <= n;j ++)
        {
            if(map[i][j] == 1 && sum[i] < sum[j] + ans[i])
            {
                sum[i] = sum[j] + ans[i];
                num[i] = j;
            }
        }
    }

    int max = -1,f = 1;
    for(int i = 1;i <= n;i ++)
    {
        if(sum[i] > max)
        {
            max = sum[i];
            f = i;
        }
    }

    int summ = 0;
    while(summ != max)
    {
        printf("%d ",f);
        summ += ans[f];
        f = num[f];
    }
    printf("\n%d",max);

    return 0;
}