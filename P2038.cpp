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
int d,n,m;
int map[129][129] = {};
long long getit(int a,int b)
{
    long long count = 0;
    int i = a - d,j = b - d;
    if(i < 0)
    {
        i = 0;
    }
    if(j < 0)
    {
        j = 0;
    }
    for(int k = i;k <= a + d;k ++)
    {
        for(int l = j;l <= b + d;l ++)
        {
            if(k <= 128 && l <= 128)
            {
                count += map[k][l];
            }
        }
    }
    return count;
}
int main()
{
    d = read(),n = read();
    m = -1;
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read(),c = read();
        map[a][b] = c;
        if(a > m || b > m)
        {
            m = max(a,b);
        }
    }
    long long max = -1;
    int t = 0;
    for(int i = 0;i <= m;i ++)
    {
        long long count;
        for(int j = 0;j <= m;j ++)
        {
            count = getit(i,j);
            if(count > max)
            {
                max = count;
                t = 1;
            }
            else if(count == max)
            {
                t ++;
            }
        }
    }
    printf("%d %lld",t,max);

    return 0;
}