#include <stdio.h>
#include <math.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int n,count = 0;
int used[4] = {};
int m[101] = {};
int trim(int a[],int k)
{
    int sum = 0;
    for(int i = 0;i < k;i ++)
    {
        if(m[used[i]])
        {
            sum += m[used[i]];
        }
        else
        {
            m[used[i]] = used[i] * used[i];
            sum += m[used[i]];
        }
    }
    return sum;
}
void dfs(int k)
{
    if(trim(used,k) > n)
    {
        return;
    }
    if(k == 4)
    {
        int sum = 0;
        for(int i = 0;i < 4;i ++)
        {
            if(m[used[i]])
            {
                sum += m[used[i]];
            }
            else
            {
                m[used[i]] = used[i] * used[i];
                sum += m[used[i]];
            }
        }
        if(sum == n)
        {
            count ++;
        }
        return;
    }
    for(int i = 0;i <= sqrt(n);i ++)
    {
        used[k] = i;
        dfs(k + 1);
    }
}
int main()
{
    n = read();

    dfs(0);

    printf("%d",count);

    return 0;
}