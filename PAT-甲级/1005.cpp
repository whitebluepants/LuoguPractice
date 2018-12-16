#include <stdio.h>
#include <string.h>
using namespace std;
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
    char s[10001] = {};

    scanf("%s",&s);

    int sum = 0;
    int len = strlen(s);
    for(int i = 0;i < len;i ++) // 使用s[i] != '\0'作为条件会错一个点
    {
        sum += s[i] - '0';
    }

    int t = 1;
    int temp = sum;

    while(temp > 9)
    {
        temp /= 10;
        t *= 10;
    }

    int flag = 0;
    while(t > 0)
    {
        temp = sum / t;
        sum %= t;
        t /= 10;

        if(flag)
        {
            printf(" ");
        }

        switch(temp)
        {
            case 0: printf("zero"); break;
            case 1: printf("one"); break;
            case 2: printf("two"); break;
            case 3: printf("three"); break;
            case 4: printf("four"); break;
            case 5: printf("five"); break;
            case 6: printf("six"); break;
            case 7: printf("seven"); break;
            case 8: printf("eight"); break;
            case 9: printf("nine");    
        }

        flag = 1;
    }

    return 0;
}