#include <stdio.h>
#include <math.h>

int main()
{
    int count = 0;
    int r,b,c,d,e;
    scanf("%d %d %d %d %d",&r,&b,&c,&d,&e);
    
    if(c + d > 2*e)
    {
        count = r*c + b*d;
    }
    else
    {
        if(r > b)
        {
            count = b * e * 2 + (r - b) * c;
        }
        else if(r < b)
        {
            count = r * e * 2 + (b - r) * d;
        }
        else if(r == b)
        {
            count = r * e * 2;
        }
    }
    printf("%d",count);

    return 0;
}