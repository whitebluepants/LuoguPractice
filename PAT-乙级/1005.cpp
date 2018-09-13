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
int ans[10005][2];
int main()
{
    int n = read(),max = 0;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        if(t > max)
        {
            max = t;
        }
        ans[t][1] = 1;
        ans[t][0] ++;
        while(t != 1)
        {
            if(t % 2 == 0)
            {
                t /= 2;
            }
            else
            {
                t = t * 3 + 1;
                t /= 2;
            }
            ans[t][0] ++;
        }
    }
    
    int flag = 0;
    for(int i = max;i >= 1;i --)
    {
        if(flag == 0 && ans[i][1] == 1 && ans[i][0] == 1)
        {
            printf("%d",i);
            flag = 1;
        }
        else if(ans[i][0] == 1 && ans[i][1] == 1)
        {
            printf(" %d",i);
        }
    }

    return 0;
}