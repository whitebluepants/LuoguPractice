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
int n,m,num;
int ans[1001];
int main()
{
    n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read();
        ans[a] ++;
        ans[b] ++;
    }

    for(int i = 1;i <= n;i ++)
    {
        if(ans[i] % 2 != 0)
        {
            num ++;
        }
    }

    if(num)
    {
        printf("%d",num / 2);
    }
    else
    {
        printf("1");
    }

    return 0;
}