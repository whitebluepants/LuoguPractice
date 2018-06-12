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
    char s[1001] = {};
    char stack[1001] = {};
    scanf("%s",s);

    int count = 0;
    int j = -1;
    for(int i = 0;s[i] != '@';i ++)
    {
        if((s[i] >= '0' && s[i] <= '9' || s[i] == '.'))
        {
            stack[++ j] = s[i];
        }
        else
        {
            char oper = s[i];
            int a = 0,b = 0;
            int flag = 0;
            j --;
            int t = 1;
            for(;j >= 0 && stack[j] != '.';j --)
            {
                a += (t * (stack[j] - '0'));
                t *= 10;
            }
            j --;
            t = 1;
            for(;j >= 0 && stack[j] != '.';j --)
            {
                b += (t * (stack[j] - '0'));
                t *= 10;
            }
            int sum;
            switch(oper)
            {
                case '*': sum = (b * a); break;
                case '+': sum = (b + a); break;
                case '-': sum = (b - a); break;
                case '/': sum = (b / a); break;
            }
            count = sum;
            int temp = sum;
            int tt = 1;
            while(temp >= 10)
            {
                temp /= 10;
                tt *= 10;
            }
            while(tt > 0)
            {
                stack[++ j] = (sum / tt) + '0';
                sum %= tt;
                tt /= 10;
            }
            stack[++ j] = '.';
        }
    }
    printf("%d",count);

    return 0;
}