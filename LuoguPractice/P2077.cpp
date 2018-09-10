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
    int n = read(),m = read();
    int time = m;
    int ans[100001] = {};
    int red[100001] = {};
    int green[100001] = {};

    for(int i = 1;i < n;i ++)
    {
        ans[i] = read();
    }
    for(int i = 0;i < n;i ++)
    {
        red[i] = read();
    }
    for(int i = 0;i < n;i ++)
    {
        green[i] = read();
    }
    for(int i = 0;i < n;i ++)
    {
        if(i != 0)
        {
            time += ans[i];
        }

        if(time <= green[i])
        {
            ;
        }
        else
        {
            int t = time - green[i];
            int tt = t % (red[i] + green[i]);
            if(tt == 0 || tt > red[i])
            {
                ;
            }
            else
            {
                time += red[i] - tt;
            }
        }
        printf("%d\n",time);
    }
    return 0;
}