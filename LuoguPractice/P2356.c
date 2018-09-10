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
    int ans[1001][1001] = {};
    int max = -1;

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            ans[i][j] = read();
        }
    }

    int sum = 0;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(ans[i][j] == 0)
            {
                sum = 0;
                for(int l = 0;l < n;l ++)
                {
                    sum += ans[i][l];
                    sum += ans[l][j];
                }
                if(sum > max)
                {
                    max = sum;
                }
            }
        }
    }
    if(max == -1)
    {
        printf("Bad Game!");
    }
    else
    {
        printf("%d",max);
    }

    return 0;
}