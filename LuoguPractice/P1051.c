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
    char s[101][21] = {};
    int a[101] = {};
    int sum = 0;
    int max = -1,p = 0;
    int n = read();
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
        int q = read(),w = read();
        char z = getchar();getchar();char x = getchar();
        int t = read();
        int count = 0;

        if(q > 80 && t > 0)
        {
            count += 8000;
        }
        if(q > 85 && w > 80)
        {
            count += 4000;
        }
        if(q > 90)
        {
            count += 2000;
        }
        if(q > 85 && x == 'Y')
        {
            count += 1000;
        }
        if(w > 80 && z == 'Y')
        {
            count += 850;
        }
        a[i] = count;
        sum += count;
        if(count > max)
        {
            max = count;
            p = i;
        }
    }
    printf("%s\n%d\n%d",s[p],a[p],sum);

    return 0;
}