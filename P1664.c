#include <stdio.h>
#include <math.h>
int main()
{
    int day,sign,count = 0,expp = 0,not = 0;
    scanf("%d",&day);
    while(day > 0)
    {
        scanf("%d",&sign);
        if(sign == 1)
        {
            if(not)
            {
                count -= pow(2,not - 1);
                if(count < 0)
                {
                    count = 0;
                }
            }
            not = 0;
            ++ count;
            if(count >= 365)
            {
                expp += 6;
            }
            else if(count >= 120)
            {
                expp += 5;
            }
            else if(count >= 30)
            {
                expp += 4;
            }
            else if(count >= 7)
            {
                expp += 3;
            }
            else if(count >= 3)
            {
                expp += 2;
            }
            else
            {
                ++ expp;
            }
        }
        else
        {
            ++ not;
        }
        -- day;
    }
    printf("%d",expp);
    return 0;
}