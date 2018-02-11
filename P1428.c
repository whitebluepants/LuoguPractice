#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < n;i ++)
    {
        int count = 0;
        for(int j = i - 1;j >= 0;j --)
        {
            if(a[j] < a[i])
            {
                count ++;
            }
        }
        if(i + 1 == n)
        {
            printf("%d",count);
        }
        else
        {
            printf("%d ",count);
        }
    }
}
