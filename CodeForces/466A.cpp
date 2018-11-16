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
    int n = read(),m = read(),a = read(),b = read();

    double mprime = 1.0 * b / m;

    if(a < mprime)
    {
        printf("%d",a * n);
    }
    else
    {
        int mcount = n / m;
        int money = mcount * b;
        int mnum = n % m;
        if(mnum * a < b * 1)
        {
            money += a * mnum;
        }
        else
        {
            money += b;
        }
        printf("%d",money);
    }

    return 0;
}