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
    int n = read(),m = read();
    int a[2001][2] = {},b[2001][2] = {};
    for(int i = 0;i < n;i ++)
    {
        a[i][0] = read(),a[i][1] = read();
    }
    for(int i = 0;i < m;i ++)
    {
        b[i][0] = read(),b[i][1] = read();
    }
    int d1 = 0,d2 = 0;
    int i = 0,j = 0;
    int flag = 0,flag2 = 0;
    int count = 0;
    while(i < n || j < m)
    {
        d1 += a[i][0];
        a[i][1] --;
        if(a[i][1] == 0)
        {
            i ++;
        }
        d2 += b[j][0];
        b[j][1] --;
        if(b[j][1] == 0)
        {
            j ++;
        }
        if(flag2 == 1 && ( (d1 > d2 && flag == 2) || (d1 < d2 && flag == 1) ))
        {
            if(d1 > d2)
            {
                flag = 1;
            }            
            else
            {
                flag = 2;
            }
            count ++;
        }
        if(flag == 0 && d1 != d2)
        {
            if(d1 > d2)
            {
                flag = 1;
            }
            else if(d1 < d2)
            {
                flag = 2;
            }
            flag2 = 1;
        }
    }
    printf("%d",count);

    return 0;
}