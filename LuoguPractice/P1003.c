#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-1*x;
}

int main()
{
    int n = read();
    int ans[100000][4] = {};
    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read(),ans[i][1] = read(),ans[i][2] = read(),ans[i][3] = read();
    }
    int x = read(),y = read();
    int flag = -1;

    for(int i = n - 1;i >= 0;i --)
    {
        if(x >= ans[i][0] && x <= ans[i][0] + ans[i][2] && y >= ans[i][1] && y <= ans[i][1] + ans[i][3])
        {
            flag = i + 1;
            break;
        }
    }
    printf("%d",flag);

    return 0;
}