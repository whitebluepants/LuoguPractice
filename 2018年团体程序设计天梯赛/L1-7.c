#include <stdio.h>
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
    int n = read(),m = read(),count = 0,flag = 0;
    int a[3] = {};
    for(int i = 0;i < 3;i ++)
    {
        a[i] = read();
        if(a[i] == 0)
        {
            count ++;
        }
    }

    printf("The winner is ");
    if(n > m && count >= 1 || count == 3)
    {   
        printf("a: %d + %d",n,count);
    }
    else
    {
        printf("b: %d + %d",m,3 - count);
    }

    return 0;
}