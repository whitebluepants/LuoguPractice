#include <stdio.h>
#include <stdlib.h>
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
    int ans[10001] = {};
    for(int i = 0;i < n;i ++)
    {
        int a = read();
        ans[i] = read();
    }
    sort(ans,ans + n);
    int temp = ans[(0 + n - 1) / 2];
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        count += abs(ans[i] - temp);
    }
    printf("%d",count);

    return 0;
}