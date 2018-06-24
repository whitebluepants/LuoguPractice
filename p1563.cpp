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
char s[100000][11];
int f[100000];
int main()
{
    int n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        f[i] = read();
        scanf("%s",s[i]);
    }
    int j = 0;
    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read();
        if(a == 0)
        {
            b *= -1;
        }
        if(f[j] == 1)
        {
            b *= -1;
        }
        j += b;
        if(j < 0)
        {
            j += n;
        }
        else if(j >= n)
        {
            j -= n;
        }
    }
    printf("%s",s[j]);

    return 0;
}