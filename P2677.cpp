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
int n,m;
int ans[20];
int min = 9999999;
void dfs(int i,int count)
{
    if(count >= m)
    {
        if(count - m < min)
        {
            min = count - m;
        }
        return ;
    }
    for(;i < n;i ++)
    {
        dfs(i + 1,count + ans[i]);
    }
}
int main()
{
    n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    dfs(0,0);

    printf("%d",min);

    return 0;
}