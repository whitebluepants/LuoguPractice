#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double f;

    scanf("%d",&n);
    f = ( pow(( ( 1+sqrt(5) )/2 ),n) - pow(( ( 1-sqrt(5) )/2 ),n) ) / sqrt(5);

    printf("%.2f",f);

    return 0;
}