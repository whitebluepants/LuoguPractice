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
int used[10] = {};
int p[10] = {};
void dfs(int k)
{
    if(k == n)
    {
        for(int l = 0;l < n;l ++)
        {
            printf("%5d",used[l]);
        }
        printf("\n");
        return;
    }
    for(int i = 1;i <= n;i ++)
    {
        if(!p[i])
        {
            used[k] = i;
            p[i] = 1;
            dfs(k + 1);
            p[i] = 0;
        }
        
    }
}
int main()
{
    n = read();
    dfs(0);

    return 0;
}