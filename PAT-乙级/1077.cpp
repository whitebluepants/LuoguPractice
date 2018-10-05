#include <stdio.h>
#include <string.h>
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
    int n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        int g2 = read();
        int g1 = 0;
        int count = 0;
        int max = -1;
        int min = 101;
        for(int j = 0;j < n - 1;j ++)
        {
            int t = read();
            if(t >= 0 && t <= m)
            {
                count ++;
                g1 += t;
                if(t > max)
                {
                    max = t;
                }
                if(t < min)
                {
                    min = t;
                }
            }
        }
        g1 -= max;
        g1 -= min;
        count -= 2;
        double g = (1.0 * g1 / count + g2) / 2;
        printf("%d\n",(int)(g + 0.5));
    }

    return 0;
}