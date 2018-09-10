#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-1*x;
}
int main()
{   
    int s = read(), x = read();
    double sp = 7,sum = 0;

    while(sum < s - x)
    {
        sum += sp;
        sp *= 0.98;
    }
    sum += sp * 0.98;
    if(sum > s + x)
    {
        printf("n");
    }
    else
    {
        printf("y");
    }

    return 0;
}