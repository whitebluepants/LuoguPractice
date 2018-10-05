#include <stdio.h>
#include <stdlib.h>
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
/*
    丙可能会是浮点数 用double存 迷
*/
int main()
{
    int n = read(),x = read(),y = read();
    int flag = 0;
    int a,b;
    double c;

    for(int i = 99;i >= 10;i --)
    {
        a = i;
        b = (a % 10 * 10) + (a / 10 % 10);
        c = (double)(abs(a - b) * 1.0 / x);
        
        if(c * y == b)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
    {
        printf("No Solution");
    }
    else
    {
        printf("%d",a);
        for(int i = 0;i < 3;i ++)
        {
            double t;
            if(i == 0)
            {
                t = a;
            }
            if(i == 1)
            {
                t = b;
            }
            if(i == 2)
            {
                t = c;
            }
            if(t == n)
            {
                printf(" Ping");
            }
            else if(t > n)
            {
                printf(" Cong");
            }
            else
            {
                printf(" Gai");
            }
        }
    }

    return 0;
}