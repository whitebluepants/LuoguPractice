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
int main()
{
    int a[101][101] = {},ans[101][101] = {},max = -1;

    int n = read();
    for(int i = 0;i < n;i ++)
    {
        int t = read();
        if(t * 10 > max)
        {
            max = t * 10;
        }
        for(int j = 0;j < t * 10;j ++)
        {
            a[i][j] = 1;
        }
    }
    int num = 1,flag = -1;
    for(int i = 0;i < max;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(a[j][i])
            {
                if(flag != j)
                {
                    ans[j][i] = num ++;
                    flag = j;
                }
                else
                {
                    ans[j][i] = ++num;
                    num ++;
                }
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        printf("#%d\n",i + 1);
        for(int j = 0;ans[i][j] != 0;j ++)
        {
            printf("%d%c",ans[i][j],(j + 1) % 10 == 0?'\n':' ');
        }
    }
    
    return 0;
}