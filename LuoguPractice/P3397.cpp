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
int ans[1001][1001];
int main()
{
    int n = read(),m = read();
    
    for(int i = 0;i < m;i ++)
    {
        int x1 = read(),y1 = read(),x2 = read(),y2 = read();

        for(int j = x1;j <= x2;j ++)
        {
            for(int k = y1;k <= y2;k ++)
            {
                ans[j][k] ++;
            }
        }
    }

    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}