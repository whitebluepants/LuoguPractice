#include <stdio.h>
int main()
{
    int t[1000][1000] = {0};
    int n,m,k,a,b,count = 0;
    
    scanf("%d %d %d",&n,&m,&k);

    for(int i = 0;i < m;i ++)
    {
        scanf("%d %d",&a,&b);
        a --;
        b --;
        t[a][b] = 1; t[a - 1][b] = 1; t[a - 2][b] = 1; t[a + 1][b] = 1; t[a + 2][b] = 1;
        t[a][b - 1] = 1; t[a][b - 2] = 1; t[a][b + 1] = 1; t[a][b + 2] = 1;
        t[a - 1][b - 1] = 1; t[a + 1][b - 1] = 1;
        t[a + 1][b + 1] = 1; t[a - 1][b + 1] = 1;
    }

    for(int i = 0;i < k;i ++)
    {
        scanf("%d %d",&a,&b);
        a --;
        b --;

        for(int j = a - 2;j <= a + 2;j ++)
        {
            for(int z = b - 2;z <= b + 2;z ++)
            {
                t[j][z] = 1;
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(t[i][j] == 0)
            {
                count ++;
            }
        }
    }
    printf("%d",count);

    return 0;
}