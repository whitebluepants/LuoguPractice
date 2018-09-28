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
    double a,b,c,d;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

    double A = a*cos(b)*c*cos(d) + -1 * a*sin(b) * c*sin(d);
    double B = a * cos(b) * c * sin(d) + a * sin(b) * c * cos(d);
    
    // 为了避免四舍五入导致误差 例如0.005的话 会输出成0.01
    // 但是应该为0
    if(abs(A) < 0.01) 
    {
        A = 0;
    }
    if(abs(B) < 0.01)
    {
        B = 0;
    }

    printf("%.2f",A);
    if(B < 0)
    {
        printf("%.2fi",B);
    }
    else
    {
        printf("+%.2fi",B);
    }

    return 0;
}