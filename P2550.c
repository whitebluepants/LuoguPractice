#include <stdio.h>
int main()
{
    int n,count = 0;
    int a[7],b[7],c[8] = {};
    scanf("%d",&n);
    for(int i = 0;i < 7;i ++)
    {
        scanf("%d",&a[i]);
    }

    for(int i = 0;i < n;i ++)
    {
        count = 0;
        for(int j = 0;j < 7;j ++)
        {
            scanf("%d",&b[j]);
            for(int k = 0;k < 7;k ++)
            {
                if(b[j] == a[k])
                {
                    count ++;
                    break;
                }
            }
        }
        c[count] ++;
    }
    for(int i = 7;i >= 1;i --)
    {
        printf("%d ",c[i]);
    }
    return 0;
}