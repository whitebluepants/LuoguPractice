#include <stdio.h>
#include <math.h>

int main()
{
    int n,level = 0,e = 0,expp,need;
    double d,hp = 10;
    scanf("%d",&n);
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%lf %d",&d,&expp);

        if(hp - d <= 0)
        {
            break;
        }
        else
        {
            hp -= d;
            if(hp > 10)
            {
                hp = 10;
            }

            e += expp;

            while((int)pow(2,level) <= e)
            {
                e -= (int)pow(2,level);
                level ++;
            }
        }
    }
    printf("%d %d",level,e);

    return 0;
}