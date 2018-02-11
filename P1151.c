#include <stdio.h>
int main()
{
    int k,a,b,c,flag = 0;
    scanf("%d",&k);
    // 12345 10101
    for(int i = 10000;i <= 30000;i ++)
    {
        a = i / 100;
        b = i / 10 % 1000;
        c = i % 1000;

        //printf("%d %d %d\n",a,b,c);

        if(a % k == 0 && b % k == 0 && c % k == 0)
        {
            flag = 1;
            printf("%d\n",i);
        }
    }
    if(flag == 0)
    {
        printf("No");
    }
    return 0;
}
