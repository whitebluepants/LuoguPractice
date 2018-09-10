#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int ans[102] = {};
void deletee(int t)
{
    for(int i = t;ans[i] != 0;i ++)
    {
        ans[i] = ans[i + 1];
    }
}
int main()
{
    int n = read(),m = read();
    
    for(int i = 1;i <= n;i ++)
    {
        ans[i] = i;
    }
    int count = 1,i = 1;

    while(ans[1] != 0)
    {
        i ++;
        count ++;
        if(ans[i] == 0)
        {
            i = 1;
        }
        if(count == m)
        {
            printf("%d ",ans[i]);
            count = 1;
            deletee(i);
            if(ans[i] == 0)
            {
                i = 1;
            }
        }
    }

    return 0;
}