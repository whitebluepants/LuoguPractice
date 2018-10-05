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
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        long a = read(),b = read(),c = read();
        if(a + b > c)
        {
            printf("Case #%d: true\n",i);
        }
        else
        {
            printf("Case #%d: false\n",i);
        }
    }
    return 0;
}