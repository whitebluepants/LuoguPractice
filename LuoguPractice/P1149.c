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
int n;
int count = 0;
int used[2] = {-1,-1};
int cns[2] = {0,0};
int ans[10] = {6,2,5,5,4,5,6,3,7,6};
int u[1000][1000] = {};
void dfs(int sum,int k)
{
    if(sum > n)
    {
        return;
    }
    if(k == 2)
    {
        int a = used[0], b = used[1];
        if(u[a][b])
        {
            return;
        }
        else
        {
            u[a][b] = 1;
        }
        int c = a + b,cneed = 0;
        int tt = c;
        while(tt > 0)
        {
            int temp2 = tt % 10;
            tt /= 10;
            cneed += ans[temp2];
        }
        if(cneed != (n - cns[0] - cns[1]))
        {
            return ;
        }
        else
        {
            count ++;
        }
        return;
    }

    for(int i = 0;i <= 999;i ++)
    {
        used[k] = i;
        if(i == 0)
        {
            cns[k] += ans[i];
        }
        else
        {
            int t = i;
            while(t > 0)
            {
                int temp = t % 10;
                t /= 10;
                cns[k] += ans[temp];
            }
        }
        dfs(sum + cns[k],k + 1);
        cns[k] = 0;
        used[k] = -1;
    }

}
int main()
{
    n = read();
    n -= 4;
    dfs(0,0);

    printf("%d",count);

    return 0;
}