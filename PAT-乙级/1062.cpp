#include <stdio.h>
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
int gcd(int a,int b)
{
    return b == 0?a:gcd(b,a%b);
}
int main()
{
    int a1 = read(),b1 = read(),a2 = read(),b2 = read();
    int k = read();

    double a = 1.0 * a1 / b1, b = 1.0 * a2 / b2;

    if(a > b)
    {
        double temp = a;
        a = b;
        b = temp;
    }

    int flag = 0;
    for(int i = 1;i < k;i ++)
    {
        int g = gcd(i,k);
        if(k / g != k)
        {
            continue;
        }
        
        double c = 1.0 * i / k;
        if(a < c && b > c)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%d/%d",i,k);
            flag = 1;
        }
    }
    
    return 0;
}