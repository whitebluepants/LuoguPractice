#include <stdio.h>
int main()
{
    int t,s[100];
    scanf("%d",&t);

    for(int i = 0;i < t;i ++)
    {
        int count,n,temp,a;
        scanf("%d",&n);
        count = n;
        for(int j = 1;j <= n;j ++)
        {
            temp = j;
            while(temp > 0)
            {
                a = temp % 10;
                temp /= 10;
                if(a == 7)
                {
                    count --;
                    break;
                }
            }
        }
        s[i] = count;
    }
    for(int i = 0;i < t;i ++)
    {
        printf("%d\n",s[i]);
    }
    return 0;
}