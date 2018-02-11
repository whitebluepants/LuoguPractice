#include <stdio.h>
int main()
{
    int n,k;
    int s = 0,sum = 0;
    scanf("%d %d",&n,&k);

    while(n != 0)
    {
        n --;
        s ++;
        sum ++;
        if(s == k)
        {
            s = 0;
            n ++;
        }    
    }
    printf("%d",sum);
    
    return 0;
}