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
int n,j = 0;
int count = 0;
int aa[100] = {};
int isSum(int ans[],int a,int b)
{
    for(int k = 0;k < j;k ++)
    {
        if(aa[k] == (a + b))
        {
            return 0;
        }
    }
    int sum = a + b;
    int flag = 0;
    for(int i = 0;i < n;i ++)
    {
        if(ans[i] == sum)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        return 0;
    }
    aa[j ++] = sum;
    return 1;
}
void dfs(int ans[],int a,int b,int i,int k)
{
    if(k == 0)
    {
        if(isSum(ans,a,b))
        {
            count ++;
        }
        return ;
    }
    for(;i < n;i ++)
    {
        if(k == 2)
        {
            a = ans[i];
        }
        if(k == 1)
        {
            b = ans[i];
        }
        dfs(ans,a,b,i + 1,k - 1);
    }
}
int main()
{
    n = read();
    int ans[100];
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    dfs(ans,0,0,0,2);
    printf("%d",count);

    return 0;
}