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
    int max,min;
    int n = read();
    double mmax = -1,mmin = 99999999999;
    for(int i = 0;i < n;i ++)
    {
        int name = read();
        int x = read(),y = read();

        double dis = sqrt(x * x + y * y);

        if(dis > mmax)
        {
            mmax = dis;
            max = name;
        }
        if(dis < mmin)
        {
            mmin = dis;
            min = name;
        }
    }
    printf("%04d %04d",min,max);

    return 0;
}