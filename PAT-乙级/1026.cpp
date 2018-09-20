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
    int a = read(),b = read();

    double t = 1.0 * (b - a) / 100;

    int time = (int)(t + 0.5);

    int h = 0,m = 0,s = 0;

    h = time / 3600;
    time -= h * 3600;
    m = time / 60;
    time -= m * 60;
    s = time;

    printf("%02d:%02d:%02d",h,m,s);

    return 0;
}