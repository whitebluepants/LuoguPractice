#include <stdio.h>
int main()
{
    int n,max = 0,count = 0,tem = -1,t;

    scanf("%d",&n);
    while(n > 0)
    {  
        t = tem;

        scanf("%d",&tem);
        if(tem >= t)
        {
            count ++;
        }
        else
        {
            count = 1;
        }

        if(count > max)
        {
            max = count;
        }
        n --;
    }
    printf("%d",max);
    return 0;
}