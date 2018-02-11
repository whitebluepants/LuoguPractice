#include <math.h>
#include <stdio.h>
int ans = 0,m,n,a[21];
int isPrimeN(int n);
void dfs(int k,int i,int sum);
int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= m;i ++)
    {
        scanf("%d",&a[i]);
    }
    dfs(n,1,0);
    printf("%d",ans);
    
    return 0;
}

int isPrimeN(int n)
{
    for(int i = 2;i <= sqrt(n);i ++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int k,int i,int sum)
{
    if(k == 0)
    {
        ans += isPrimeN(sum);
        return;
    }
    for(i;i <= m;i ++)
    {
        dfs(k - 1,i + 1,sum + a[i]);
    }
}
