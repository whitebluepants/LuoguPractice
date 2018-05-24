#include <stdio.h>
#include <algorithm>
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
    int a[10000] = {};
    int m = read();
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    
    for(int i = 0;i < m;i ++)
    {
        next_permutation(a,a + n);
    }

    for(int i = 0;i < n;i ++)
    {
        printf("%d%c",a[i],i == n - 1?'\n':' ');
    }
    return 0;
}