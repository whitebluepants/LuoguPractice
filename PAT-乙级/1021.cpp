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
    int a[10] = {};

    int t;
    while(scanf("%1d",&t) != EOF)
    {
        a[t] ++;
    }

    for(int i = 0;i < 10;i ++)
    {
        if(a[i] != 0)
        {
            printf("%d:%d\n",i,a[i]);
        }
    }
    return 0;
}