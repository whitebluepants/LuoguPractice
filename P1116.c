#include <stdio.h>
int main()
{
    int n,count = 0;
    int a[10000];
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }

    for(int i = 0;i < n - 1;i ++)
    {
        for(int j = 0;j < n - i - 1;j ++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count ++;    
            }
        }
    }
    printf("%d",count);

    return 0;
}