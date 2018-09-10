#include <stdio.h>
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
    int n = read(),m = read();
    
    int sq = 0, re = 0;

    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= m;j ++)
        {
            if(i == j)
            {
                sq += (n - i + 1) * (m - j + 1);
            }
            else
            {
                re += (n - i + 1) * (m - j + 1);
            }
        }
    }
    printf("%d %d",sq,re);

    return 0;
}