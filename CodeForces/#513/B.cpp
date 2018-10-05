#include <stdio.h>
using namespace std;
long long read()
{
	char ch = getchar();
	int f = 1;
	long long x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int main()
{
    long long n = read();
    
    long long temp = n;
    long long t = 1;
    int count = 0;
    while(temp > 0)
    {
        temp /= 10;
        t *= 10;
        count ++;
    }
    long long a = 0;
    for(int i = 0;i < count - 1;i ++)
    {
        a = a * 10 + 9;
    }
    if(n / t > 1)
    {
        a += ((n / t) - 1) * t;
    }
    long long b = n - a;

    int sum1 = 0,sum2 = 0;
    while(a > 0)
    {
        int temp = a % 10;
        a /= 10;
        sum1 += temp;
    }
    while(b > 0)
    {
        int temp = b % 10;
        b /= 10;
        sum2 += temp;
    }
    
    printf("%d",sum1 + sum2);

    return 0;
}   