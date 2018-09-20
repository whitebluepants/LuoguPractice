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
int a[10];
int main()
{
    int t,min = 10,flag = 0;

    for(int i = 0;i < 10;i ++)
    {
        a[i] = read();
        if(i == 0 && a[i] != 0)
        {
            flag = 1;
        }
        if(i != 0 && a[i] != 0 && i < min)
        {
            min = i;
        }
    }

    if(flag == 1)
    {
        printf("%d",min);
        a[min] --;
    }
    for(int i = 0;i < 10;i ++)
    {
        for(int j = 0;j < a[i];j ++)
        {
            printf("%d",i);
        }
    }

    return 0;
}