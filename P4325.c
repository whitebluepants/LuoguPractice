#include <stdio.h>
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
    int t = 10,a[42] = {},count = 0;
    while(t > 0)
    {
        int n = read();
        if(a[n % 42] == 0)
        {
            count ++;
        }
        a[n % 42] ++;
        t --;
    }
    
    printf("%d",count);

    return 0;
}