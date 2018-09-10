#include <stdio.h>
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

int main()
{
    int n = read();
    char s[10000][9] = {};
    int a[10000] = {};
    int sum = 0;
    for(int i = 0;i < n;i ++)
    {
        scanf("%s %d",s[i],&a[i]);
        sum += a[i];
    }
    sum /= n;
    sum /= 2;
    int min = 999,t = 0;
    for(int i = 0;i < n;i ++)
    {
        int temp = abs(a[i] - sum);
        if(min > temp)
        {
            min = temp;
            t = i;
        }
    }
    printf("%d %s",sum,s[t]);

    return 0;
}