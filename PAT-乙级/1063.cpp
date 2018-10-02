#include <stdio.h>
#include <math.h>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int main()
{
    int n = read();
    double max = -1;
    for(int i = 0;i < n;i ++)
    {
        double a,b;
        scanf("%lf %lf",&a,&b);
        double t = sqrt(a*a + b*b);
        if(t > max)
        {
            max = t;
        }
    }
    printf("%.2f",max);

    return 0;
}