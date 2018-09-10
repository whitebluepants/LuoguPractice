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
    int n = read();
    int ans[10001] = {};

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }
    int count = 0,flag = 0;
    for(int i = 1;i < n - 1;i ++)
    {
        if(flag == 0 && ans[i] < ans[i - 1])
        {
            flag = 1;
        }
        if(flag == 1 && ans[i] < ans[i + 1])
        {
            count ++;
            flag = 0;
        }
    }
    printf("%d",count);

    return 0;
}