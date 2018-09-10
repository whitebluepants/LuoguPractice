#include <stdio.h>
int main()
{
    int s1,s2,s3,a[81] = {0,},max,sum,t;
    scanf("%d %d %d",&s1,&s2,&s3);

    for(int i = 1;i <= s1;i ++)
    {
        for(int j = 1;j <= s2;j ++)
        {
            for(int k = 1;k <= s3;k ++)
            {
                sum = i + j + k;
                a[sum] ++;
            }
        }
    }
    max = a[3];
    for(int i = 3;a[i] != 0 && i <= 80;i ++)
    {
        if(max < a[i])
        {
            max = a[i];
            t = i;
        }
    }
    printf("%d",t);
    return 0;
}