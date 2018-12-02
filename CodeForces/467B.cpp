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
int a[1001];
int main()
{
    int n = read(),m = read(),k = read();

    for(int i = 0;i < m;i ++)
    {
        a[i] = read();
    }
    int t = read();

    int count = 0;
    for(int i = 0;i < m;i ++)
    {
        int temp = t ^ a[i];
        int num = 0;
        while(temp > 0)
        {
            if(temp % 2 == 1)
            {
                num ++;
            }
            temp /= 2;
        }
        if(num <= k)
        {
            count ++;
        }
    }

    printf("%d",count);

    return 0;
}
