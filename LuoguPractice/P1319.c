#include <stdio.h>
int main()
{
    char n[201] = {0};
    int flag = 0,t,N,m,i = 0;
    scanf("%d",&N);
    t = N;
    while(t > 0)
    {
        scanf("%d",&m);
        for(int j = 0;j < m;j ++)
        {
            n[i] = (flag & 1) + 48;
            i ++;
            if(i == N)
            {
                printf("%s\n",n);
                t --;
                i = 0;
            }
        }
        flag ^= 1;
    }
    return 0;
}