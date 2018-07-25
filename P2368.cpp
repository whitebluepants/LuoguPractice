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

    if(n < 9)
    {
        printf("0");
        return 0;
    }   
    if(n == 9)
    {
        printf("8");
        return 0;
    }
    printf("%d",8 * 9);

    for(int i = 0;i < n - 10;i ++)
    {
        printf("0");
    }
    return 0;
}