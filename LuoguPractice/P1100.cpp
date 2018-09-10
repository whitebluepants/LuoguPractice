#include <stdio.h>
#include <math.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){x = x * 10 + ch - '0';ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int ans[33] = {};
    int n = read();

    int i = 1;
    while(n > 0)
    {
        ans[i ++] = n % 2;
        n /= 2;
    }
    unsigned long long a = 0;
    int j = 0;
    for(int i = 17;i <= 32;i ++)
    {
        a += ans[i] * pow(2,j);
        j ++;    
    }
    for(int i = 1;i <= 16;i ++)
    {
        a += ans[i] * pow(2,j);
        j ++;
    }
    printf("%llu",a);

    return 0;
}