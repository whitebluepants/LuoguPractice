#include <stdio.h>
int main()
{
    int n,min = 100000000,j,k,sum = 0;
    scanf("%d",&n);
    
    for(int i = 0;i < 3;i ++)
    {
        scanf("%d %d",&j,&k);

        if(n % j != 0 && n / j != 0)
        {
            sum = ( (n / j) + 1 ) * k;
        }
        else if(n < j)
        {
            sum = k;
        }
        else
        {
            sum = (n / j) * k;
        }

        if(sum < min)
        {
            min = sum;
        }
    }
    printf("%d",min);

    return 0;
}