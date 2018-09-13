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
    int n = read();

    int bai,shi,ge;

    if(n >= 100)
    {
        bai = n / 100;
        shi = n % 100 / 10;
        ge = n % 10;
    }
    else if(n >= 10)
    {
        bai = 0;
        shi = n / 10;
        ge = n % 10;
    }
    else
    {
        bai = 0;
        shi = 0;
        ge = n;
    }

    for(int i = 0;i < bai;i ++)
    {
        printf("B");
    }
    for(int i = 0;i < shi;i ++)
    {
        printf("S");
    }
    for(int i = 1;i <= ge;i ++)
    {
        printf("%d",i);
    }

    return 0;
}