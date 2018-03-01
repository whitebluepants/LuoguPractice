#include <stdio.h>
#include <string.h>

int main()
{
    char m[201][201] = {};
    char t;
    int i,count = 0;
    
    for(i = 0;i < 201;i ++)
    {
        gets(m[i]);
        if(strcmp(m[i],"\0") == 0)
        {
            break;
        }
    }
    t = m[0][0];
    printf("%d ",i);

    for(int j = 0;j <= i;j ++)
    {
        for(int k = 0;k < i;k ++)
        {
            if(m[j][k] == t)
            {
                count ++;
                t = m[j][k];
            }
            else
            {
                t = m[j][k];
                printf("%d ",count);
                count = 0;
                count ++;
            }
        }
    }
    return 0;
}