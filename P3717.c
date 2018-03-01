#include <stdio.h>

int main()
{
    int n,m,r,ans = 0,a,b;
    int t[100][100] = {};
    scanf("%d %d %d",&n,&m,&r);
    
    for(int i = 0;i < m;i ++)
    {
        scanf("%d %d",&a,&b);
        a--;b--;

        for(int j = 0;j < n;j ++)
        {
            for(int k = 0;k < n;k ++)
            {
                if( (j - a) * (j - a) + (k - b) * (k - b) <= r * r)
                {
                    t[j][k] = 1;
                }
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(t[i][j] == 1)
            {
                ans ++;
            }
        }
    }
    
    printf("%d",ans);

    return 0;
}