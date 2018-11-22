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
    int sum = 0;
    for(int i = 0;i < 5;i ++)
    {
        int t = read();
        sum += t;
    }

    if(sum / 5 != 0 && sum % 5 == 0)
    {
        printf("%d",sum / 5);
    }
    else
    {
        printf("-1");
    }

    return 0;
}