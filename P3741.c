#include <stdio.h>
int main()
{
    char s[101] = {0};
    int n,count = 0,flag = 0;
    scanf("%d %s",&n,s);
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'V' && s[i + 1] == 'K')
        {
            count ++;
            s[i] = 'v';
            s[i + 1] = 'k';
        }
    }
    for(int i = 0;s[i] != '\0';i ++)
    {
        if( (s[i] == 'V' && s[i + 1] == 'V') || (s[i] == 'K' && s[i + 1] == 'K') )
        {
            count ++;
            break;
        }
    }
    printf("%d",count);
    
    return 0;
}