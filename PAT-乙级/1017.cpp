#include <stdio.h>
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
int main()
{
    char s[1001] = {}; int d;
    char ss[1001] = {};
    scanf("%s",s);
    d = read();

    int len = strlen(s);
    int temp = 0,ans;
    for(int i = 0;i < len;i ++)
    {
        temp = temp * 10 + (s[i] - '0');
        if(temp < d)
        {
            ss[i] = '0';
        }
        else
        {
            ss[i] = temp / d + '0';
            temp %= d;
        }
        if(i == len - 1)
        {
            ans = temp;
        }
    }
    int flag = 0;
    len = strlen(ss);
    for(int i = 0;i < len;i ++)
    {
        if(flag == 0 && ss[i] != '0')
        {
            flag = 1;
        }
        if(flag)
        {
            printf("%c",ss[i]);
        }
    }
    if(len == 1 && ss[0] == '0')
    {
        printf("0");
    }
    printf(" %d",ans);

    return 0;
}