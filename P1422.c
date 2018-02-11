#include <stdio.h>

int main()
{
    int degree;
    float sum;
    scanf("%d",&degree);
    sum = 150 * 0.4463;
    if(degree <= 150)
    {
        sum -= (150 - degree) * 0.4463;
    }
    else if(degree > 150 && degree <= 400)
    {
        sum += (degree - 150) * 0.4663;
    }
    else if(degree > 400)
    {
        sum += 250 * 0.4663;
        sum += (degree - 400) * 0.5663;
    }
    printf("%.1f",sum);
}
