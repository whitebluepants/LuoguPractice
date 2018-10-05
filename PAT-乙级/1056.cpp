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
int n,sum;
int ans[10];
void dfs(int m,int num,int k)
{
    if(k == 2)
    {
        sum += num;
        return ;
    }
    for(int i = 0;i < n;i ++)
    {
        if(i == m)
        {
            continue;
        }
        else
        {
            dfs(i,num * 10 + ans[i],k + 1);
        }
    }
}
int main()
{
    n = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    dfs(-1,0,0);

    printf("%d",sum);

    return 0;
}