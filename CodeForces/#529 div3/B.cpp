#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
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
int ans[100010];
int main()
{
    // freopen("in.txt","r",stdin);
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    sort(ans,ans + n);

    int min = 999999999;

    if(n == 2)
    {
        min = 0;
    }
    else
    {
        int a = ans[n - 2] - ans[0];
        int b = ans[n - 1] - ans[1];
        min = a < b? a : b;
    }
    printf("%d",min);

    return 0;
}