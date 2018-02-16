#include <stdio.h>
int main()
{
    int a[10] = {0,};
    int m,n,temp;
    scanf("%d %d",&m,&n);

    for(int i = m;i <= n;i ++)
    {
        m = i;
        while(m > 0)
        {
            temp = m % 10;
            m /= 10;
            a[temp] ++;
        }
    }
    for(int i = 0;i < 10;i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}