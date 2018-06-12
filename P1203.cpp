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
    int n = read();
    char s[351] = {};
    scanf("%s",s);

    int max = -1;

    int f = 1;
    for(int i = 1;i < n;i ++)
    {
        if(s[i] != s[i - 1])
        {
            f = 0;
            break;
        }
    }
    if(f == 1)
    {
        printf("%d",n);
        return 0;
    }

    for(int i = 0;i < n;i ++)
    {
        int left = i - 1, right = i;
        char l,r = s[right];
        if(left < 0)
        {
            l = s[n - 1];
        }
        else
        {
            l = s[left];
        }
        left --,right ++;
        if(left < 0)
        {
            left = n - 1;
        }
        if(right >= n)
        {
            right = 0;
        }

        int count1 = 1;
        if(l == 'w')
        {
            for(;l == 'w';left --)
            {
                count1 ++;
                l = s[left];
                if(left < 0)
                {
                    left = n - 1;
                }
            }
        }
        for(;s[left] == 'w' || s[left] == l;left --)
        {
            count1 ++;
            if(left < 0)
            {
                left = n - 1;
            }
        }
        int count2 = 1;
        if(r == 'w')
        {
            for(;r == 'w';right ++)
            {
                count2 ++;
                r = s[right];
                if(right >= n)
                {
                    right = 0;
                }
            }
        }
        for(;s[right] == 'w' || s[right] == r;right ++)
        {
            count2 ++;
            if(right >= n)
            {
                right = 0;
            }
        }
        if(count1 + count2 > max)
        {
            max = count1 + count2;
        }
    }
    printf("%d",max);

    return 0;
}