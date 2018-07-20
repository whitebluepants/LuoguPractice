#include <stdio.h>
#include <math.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    double v,angle;
    scanf("%lf %lf",&v,&angle);

    double vx = sin(angle) * v;
    double vy = cos(angle) * v;
    
    double t = vy / 10;
    
    printf("%f %f",vx * t,0.5 * vy * t);
    
    return 0;
}