#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read(),m = read();
    int a[101] = {};
    int count = 0;
    int k = 0;
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        int flag = 0;
        for(int j = 0;j < k;j ++)
        {
            if(a[j] == t)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            if(k == n)
            {
                for(int l = 1;l < k;l ++)
                {
                    a[l - 1] = a[l];
                }
                a[k - 1] = t;
            }
            else
            {
                a[k ++] = t;
            }
            count ++;
        }
    }
    printf("%d",count);

    return 0;
}