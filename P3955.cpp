#include <stdio.h>
#include <iostream>
#include <string.h>
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
int trans(char s[])
{
    int x = 0;
    for(int i = 0;s[i] != '\0';i ++)
    {
         x = x * 10 + s[i] - '0';
    }
    return x;
}
int main()
{
    int n = read(),m = read();
    int book[1001] = {};
    char b[1001][10] = {};

    for(int i = 0;i < n;i ++)
    {
        cin >> b[i];
        book[i] = trans(b[i]);
    }

    char num[1001][10] = {};
    for(int i = 0;i < m;i ++)
    {
        int a;
        cin >> a >> num[i];
    }

    for(int i = 0;i < m;i ++)
    {
        int min = 9999999999,flag = 0,len2 = strlen(num[i]);
        int temp = 0;
        for(int j = 0;j < n;j ++)
        {
            int len = strlen(b[j]);
            int flag1 = 1;
            if(len2 > len)
            {
                continue;
            }
            for(int k = len - 1,l = len2 - 1;l >= 0;k --,l --)
            {
                if(num[i][l] != b[j][k])
                {
                    flag1 = 0;
                    break;
                }
            }
            if(flag1)
            {
                temp = book[j];
                flag = 1;
                if(temp < min)
                {
                    min = temp;
                }
            }
        }
        if(flag == 1)
        {
            printf("%d\n",min);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}