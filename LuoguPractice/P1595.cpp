#include <stdio.h>
long long count;
long long dfs(int n)
{
    if(n == 0 || n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    return (n - 1) * (dfs(n - 2) + dfs(n - 1));
}
int main()
{
    int n;

    scanf("%d",&n);
    count = dfs(n);

    printf("%lld",count);

    return 0;
}