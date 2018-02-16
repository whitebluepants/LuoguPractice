#include <stdio.h>
int main()
{
    char s[240][240] = {};
    int count = 0,x,y,t,x1,y1,x2,y2;
    scanf("%d %d %d",&x,&y,&t);

    for(int i = 0;i < t;i ++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int j = y1 - 1;j <= y2 - 1;j ++)
        {
            for(int k = x1 - 1;k <= x2 - 1;k ++)
            {
                if(s[j][k] == 0)
                {
                    count ++;
                    s[j][k] = '0';
                }
            }
        }
    }
    printf("%d",count);

    return 0;
}