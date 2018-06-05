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
int main()
{
    int n = read();
    int count = 0,m = 9999999,temp;
    for(int i = 0;i < n;i ++)
    {
        int t = read();
        if(i == 0)
        {
            count = t;
        }
        else
        {
            if(t > temp)
            {
                count += t - temp;
            }
        }
        temp = t;
    }
    printf("%d",count);

    return 0;
}