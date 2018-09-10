#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1001];
    int m;
    scanf("%d %s",&m,s1);
    int len = strlen(s1),flag = 0,n = len;
    for(int i = 0;i < len;i ++)
    {
        -- n;
        if(s1[i] == '0')
        {
            continue;
        }
        if(flag == 0)
        {
            flag = 1;
            printf("%c*%d^%d",s1[i],m,n);
        }
        else
        {
            printf("+%c*%d^%d",s1[i],m,n);
        }
    }

    return 0;
}