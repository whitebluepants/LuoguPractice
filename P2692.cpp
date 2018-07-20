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
    int n = read(),m = read(),b = read(),g = read();
    int row[5001] = {}, col[5001] = {};

    for(int i = 0;i < b;i ++)
    {
        int a = read(), b = read();
        for(int j = a;j <= b;j ++)
        {
            row[j] = 1;
        }
    }
    
    for(int i = 0;i < g;i ++)
    {
        int a = read(), b = read();
        for(int j = a;j <= b;j ++)
        {
            col[j] = 1;
        }
    }
    int rowcount = 0;
    int count = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(row[i] == 1)
        {
            rowcount ++;
            count += m;
        }
    }
    int rerow = n - rowcount;
    for(int i = 1;i <= m;i ++)
    {
        if(col[i] == 1)
        {
            count += rerow;
        }
    }
    printf("%d",count);

    return 0;
}