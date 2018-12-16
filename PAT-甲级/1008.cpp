#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();

    int sum = 0;
    int floor = 0;

    for(int i = 0;i < n;i ++)
    {
        int t = read();

        int temp = t - floor;
        floor = t;

        if(temp > 0)
        {
            sum += temp * 6;
        }
        else if(temp < 0)
        {
            sum += -1 * temp * 4;
        }
        sum += 5;
    }

    printf("%d",sum);

    return 0;
}