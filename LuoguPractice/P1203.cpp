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
    int f = 0;
    for(int i = 0;i < n - 1;i ++)
    {
        if(s[i] != s[i + 1])
        {
            f = 1;
        }
    }
    if(f == 0)
    {
        printf("%d",n);
        return 0;
    }
    
    for(int i = 0;i < n;i ++)
    {
        int left = i - 1,right = i;
        if(left < 0)
        {
            left = n - 1;
        }
        char l,r;
        int flag1 = 0,flag2 = 0;
        int count1 = 0,count2 = 0;

        for(;flag2 != 3;right ++)
        {
            if(right >= n)
            {
                right = 0;
            }
            
            if(s[right] == 'w')
            {
                count2 ++;
            }
            else if(flag2 == 0 && s[right] != 'w')
            {
                r = s[right];
                flag2 = 1;
                count2 ++;
            }
            else if(flag2 == 1 && s[right] == r)
            {
                count2 ++;
            }
            else
            {
                flag2 = 3;
            }
        }

        for(;flag1 != 3 && left != right - 2;left --)
        {
            if(left < 0)
            {
                left = n - 1;
            }
            
            if(s[left] == 'w')
            {
                count1 ++;
            }
            else if(flag1 == 0 && s[left] != 'w')
            {
                l = s[left];
                flag1 = 1;
                count1 ++;
            }
            else if(flag1 == 1 && s[left] == l)
            {
                count1 ++;
            }
            else
            {
                flag1 = 3;
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