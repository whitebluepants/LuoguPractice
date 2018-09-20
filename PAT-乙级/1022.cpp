#include <stdio.h>
using namespace std;
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int aa[1000];
int main()
{
    long long a = read(),b = read(),k = read();

    if(k == 10 || a == 0 && b == 0)
    {
        printf("%lld",a + b);
    }
    else
    {
        long long c = a + b;
        int i = 0;

        while(c != 0)
        {
            aa[i ++] = c % k;
            c /= k;    
        }

        for(int j = i - 1;j >= 0;j --)
        {
            printf("%d",aa[j]);
        }
    }
    return 0;
}