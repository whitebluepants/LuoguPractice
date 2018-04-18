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
    char s[60001] = {};
    int sum = 0,t = 0,f = 1;
    scanf("%s",s);
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(i == 0 && s[i] == '-')
        {
            f = -1;
        }
        if(i != 0 && s[i] == '-')
        {
            sum += t * f;
            f = -1;
            t = 0;
        }
        if(s[i] == '+')
        {
            sum += t * f;
            f = 1;
            t = 0;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            t = t * 10 + s[i] - '0';
        }
    }
    sum += t*f;
    
    printf("%d",sum);

    return 0;
}