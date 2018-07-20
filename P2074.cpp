#include <stdio.h>
#include <algorithm>
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
    int n = read(),m = read(),k = read(),t = read();
    int maxcount = -1;

    for(int i = 0;i < k;i ++)
    {
        int x = read(),y = read();
        int count = 0;
        int minx = max(1,x - t),maxx = min(n,x + t);
        int miny = max(1,y - t),maxy = min(m,y + t);

        for(int j = minx;j <= maxx;j ++)
        {
            for(int k = miny;k <= maxy;k ++)
            {
                if(sqrt((j - x) * (j - x) + (k - y) * (k - y)) <= t)
                {
                    count ++;
                }
            }
        }
        if(count > maxcount)
        {
            maxcount = count;
        }
    }
    printf("%d",maxcount);

    return 0;
}