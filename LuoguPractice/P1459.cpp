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
    int num[4] = {},ans[1001] = {};
    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
        num[ans[i]] ++;
    }
    int count = 0;
    for(int i = 0;i < num[1];i ++)
    {
        if(ans[i] != 1)
        {
            count ++;
        }
    }
    sort(ans,ans + num[1]);
    int t = count;
    for(int i = num[1];i < n;i ++)
    {
        if(ans[i] == 1)
        {
            int temp = ans[num[1] - t];
            ans[num[1] - t] = ans[i];
            ans[i] = temp;
            t --;
        }
    }
    for(int i = num[1];i < num[1] + num[2];i ++)
    {
        if(ans[i] != 2)
        {
            count ++;
        }
    }

    printf("%d",count);

    return 0;
}