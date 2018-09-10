#include <stdio.h>
#include <string.h>

int main()
{
    char m[40000],b[201];
    char t;
    int count = 0;
    
    scanf("%s",m);
    int n = strlen(m);

    for(int i = 0;i < n - 1;i ++)
    {
        scanf("%s",b);
        strcat(m,b);
    }
    printf("%d ",n);
    t = '0';
    for(int i = 0;i <= strlen(m);i ++)
    {
        if(m[i] == t)
        {
            count ++;
            t = m[i];
        }
        else
        {
            t = m[i];
            printf("%d ",count);
            count = 0;
            count ++;
        }
    }
    return 0;
}