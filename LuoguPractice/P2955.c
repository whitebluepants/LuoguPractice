#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[10000];
    while(n > 0)
    {
        scanf("%s",s);
        int len = strlen(s);
        if( (s[len - 1] - '0') % 2 == 0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
        -- n;
    }
    return 0;
}