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
int a[101];
int main()
{
    int n = read(),m = read();
    
    for(int i = 0;i < n;i ++)
    {
        int t = read();
        int p = (i + m) % n;
        a[p] = t;
    }

    for(int i = 0;i < n;i ++)
    {
        printf("%d",a[i]);
        if(i != n - 1)
        {
            printf(" ");
        }
    }
    return 0;
}