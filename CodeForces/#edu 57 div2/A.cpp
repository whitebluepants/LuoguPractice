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
    freopen("in.txt","r",stdin);
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int l = read(),r = read();
        printf("%d %d\n",l,l * 2);
    }

    return 0;
}