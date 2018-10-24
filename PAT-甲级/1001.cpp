#include <string.h>
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
    int flag = 0;
    int a = read(),b = read();
    int c = a + b;

    if(c == 0)
    {
        printf("0");
        return 0;
    }

    if(c < 0)
    {
        c *= -1;
        flag = 1;
    }

    char s[1001] = {};
    int i = 0,count = 0;
    while(c > 0)
    {
        int temp = c % 10;
        c /= 10;
        if(count != 0 && count % 3 == 0)
        {
            s[i ++] = ',';
        }
        s[i ++] = temp + '0';
		count ++;
    }
    
    int len = strlen(s);

    if(flag)
    {
        printf("-");
    }

    for(int i = len - 1;i >= 0;i --)
    {
        printf("%c",s[i]);
    }

    return 0;
}