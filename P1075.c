#include <stdio.h>
#include <math.h>
int main()
{
    int n,max = -1,temp;
    scanf("%d",&n);
    
    for(int i = 2;i <= sqrt(n);i ++)
    {
        if(n % i == 0)
        {
            temp = n / i;
        }

        if(temp > max)
        {
            max = temp;
        }
    }
    printf("%d",temp);

    return 0;
}