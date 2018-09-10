#include <stdio.h>
#include <string.h>
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
int n,count = 0;
int ans[14] = {};
int check[3][28] = {};
void dfs(int r)
{
    if(r > n)
    {
        count ++;
        if(count <= 3)
        {
            for(int j = 1;j <= n;j ++)
            {
                printf("%d ",ans[j]);
            }
            printf("\n");
        }
        return;
    }

    for(int i = 1;i <= n;i ++)
    {
        if(check[0][i] == 0 && check[1][i + r] == 0 && check[2][r - i + n] == 0)
        {
            ans[r] = i;
            check[0][i] = 1;check[1][i + r] = 1;check[2][r - i + n] = 1;
            dfs(r + 1);
            check[0][i] = 0;check[1][i + r] = 0;check[2][r - i + n] = 0;
        }
    }
}
int main()
{
    n = read();
    
    dfs(1);

    printf("%d",count);
    return 0;
}