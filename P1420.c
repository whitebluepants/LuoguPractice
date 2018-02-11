#include <stdio.h>
int main()
{
    int n,len = 1,max = 1;
    scanf("%d",&n);
    int a[n];

    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
        if(i != 0)
        {
            if(a[i] - a[i - 1] == 1)
            {
                len ++;
                if(len > max)
                {
                    max = len;
                }
            }
            else
            {
                len = 1;
            }
        }
    }
    printf("%d",max);

    return 0;
}