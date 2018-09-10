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
    int max = -9999,count = 0;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        count += t;
        if(count > max)
        {
            max = count;
        }
        if(count < 0)
        {
            count = 0;
        }
    }

    printf("%d",max);

    return 0;
}