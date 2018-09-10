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
    int x1 = read(),y1 = read(),x2 = read(),y2 = read();
    char s[2] = {};
    int n = read(),count = 0;
    int dx = x2 - x1,dy = y2 - y1;
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        if(dx > 0 && s[0] == 'N')
        {
            count ++;
            dx --;
        }
        if(dx < 0 && s[0] == 'S')
        {
            count ++;
            dx ++;
        }
        if(dy > 0 && s[0] == 'E')
        {
            dy --;
            count ++;
        }
        if(dy < 0 && s[0] == 'W')
        {
            dy ++;
            count ++;
        }
    }
    if(dx == 0 && dy == 0)
    {
        printf("%d",count);
    }
    else
    {
        printf("-1");
    }

    return 0;
}