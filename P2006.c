#include <stdio.h>
int main()
{
    int k,m,n,count,flag = 0,i;
    int mp[30000],damage[30000];
    scanf("%d %d %d",&k,&m,&n);

    for(i = 0;i < m;i ++)
    {
        scanf("%d %d",&mp[i],&damage[i]);
        if(damage[i] <= 0)
        {
            continue;
        }
        if( (n / damage[i] > 0) && (n % damage[i] != 0) )
        {
            count = n / damage[i] + 1;
        }
        else if(n < damage[i])
        {
            count = 1;
        }
        else
        {
            count = n / damage[i];
        }

        if(count * mp[i] <= k)
        {
            flag = 1;
            printf("%d ",i + 1);
        }
    }
    if(flag == 0)
    {
        printf("-1");
    }

    return 0;
}