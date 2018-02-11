#include <stdio.h>
int main()
{
    char sn[7] , gn[7];
    gets(sn);
    gets(gn);
    int sum1 = sn[0] - 64,sum2 = gn[0] - 64,e;
    for(int i = 1;sn[i] != '\0';i ++)
    {
        sum1 *= sn[i] - '@';
    }
    e = sum1 % 47;
    for(int i = 1;gn[i] != '\0';i ++)
    {
        sum2 *= gn[i] - '@'; 
    }
    if(e == (sum2 % 47))
    {
        printf("GO");
    }
    else
    {
        printf("STAY");
    }
    return 0;
}
