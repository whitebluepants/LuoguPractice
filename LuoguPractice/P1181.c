#include <stdio.h>
int main()
{
    int n,m,sum = 0,ans = 0;
    int a[100001];
    scanf("%d %d",&n,&m);

    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
        
        if(sum + a[i] == m)
        {
            sum = 0;
            ans ++;
        }
        else if(sum + a[i] > m)
        {
            sum = a[i];
            ans ++;
        }
        else
        {
            sum += a[i];
            if(i == n - 1)
            {
                ans ++;
            }
        }
    }
    printf("%d",ans);

    return 0;
}