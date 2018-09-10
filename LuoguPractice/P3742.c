#include <stdio.h>
#include <string.h>
int main()
{
    char x[101],y[101],z[101];
    int flag = 1;
    int n;
    
    scanf("%d",&n);
    scanf("%s",x);
    scanf("%s",y);
    for(int i = 0;x[i] != '\0';i ++)
    {
        if(x[i] >= y[i])
        {
            z[i] = y[i];
        }
        else if(x[i] < y[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%s",z);
    }
}