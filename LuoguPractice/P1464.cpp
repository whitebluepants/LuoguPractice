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
long long vis[200][200][200];
long long w(long long a,long long b,long long c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if(vis[a][b][c] != 0)
    {
        return vis[a][b][c];
    }
    if(a > 20 || b > 20 || c > 20)
    {
        if(vis[20][20][20])
        {
            return vis[20][20][20];
        }
        else
        {
            return w(20,20,20);
        }
    }
    if(a < b && b < c)
    {
        return vis[a][b][c] = w(a,b,c - 1) + w(a,b - 1,c - 1) - w(a,b - 1,c);
    }
    else
    {
        return vis[a][b][c] = w(a - 1,b,c) + w(a - 1,b - 1,c) + w(a - 1,b,c - 1) - w(a - 1,b - 1,c - 1);
    }
}
int main()
{
    int a = read(),b = read(),c = read();
    while(!(a == b && b == c && a == -1))
    {
        printf("w(%d, %d, %d) = %lld\n",a,b,c,w(a,b,c));
        a = read(),b = read(),c = read();
    }

    return 0;
}