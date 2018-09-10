#include <stdio.h>
int main()
{
    int n,sum = 0,sum2 = 0,flag = 1,i,j;
    scanf("%d",&n);

    for(i = n;;i ++)
    {
        sum = 0;
        for(j = 1;j <= i / 2;j ++)
        {
            if(i % j == 0)
            {
            	sum += j;
            }
        }

        sum2 = 0;
        for(int k = 1;k <= sum / 2;k ++)
        {
            if(sum % k == 0)
            {
                sum2 += k;
            }
        }
        if(i == sum)
        {
            continue;
        }
        if(sum2 == i)
        {
            printf("%d %d",i,sum);
            return 0;
        }
    }
    return 0;
}
