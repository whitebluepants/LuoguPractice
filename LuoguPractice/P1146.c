#include <stdio.h>
int main()
{
    int a[100] = {};
    int n;
    scanf("%d",&n);

    printf("%d\n",n);
    
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(j == i)
            {
                printf("%d",a[j]);
                continue;
            }
            else
            {
                a[j] ^= 1;
            }
            printf("%d",a[j]);
        }
        printf("\n");
    }
    return 0;
}