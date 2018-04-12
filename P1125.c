#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int prime(int n)
{
    if(n == 0 || n == 1)
    {
        return 0;
    }
    
    for(int i = 2;i < sqrt(n);i ++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a[27] = {};
    char s1[101] = {};

    scanf("%s",s1);
    for(int i = 0;s1[i] != '\0';i ++)
    {
        a[s1[i] - 'a'] ++;
    }
    
    int max = -1,min = 102;

    for(int i = 0;i < 27;i ++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
        if(a[i] != 0 && a[i] < min)
        {
            min = a[i];
        }
    }
    int temp = max - min;

    if(prime(temp))
    {
        printf("Lucky Word\n%d",temp);
    }
    else
    {
        printf("No Answer\n0");
    }

    return 0;
}