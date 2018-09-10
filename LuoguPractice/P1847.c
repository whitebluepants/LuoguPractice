#include <stdio.h>
int main()
{
    int t[2000][4] = {}; // 记录每个点的轰炸情况
    int p[2000][4];             // 轰炸点坐标
    int m,n;
    scanf("%d %d",&m,&n);

    for(int i = 0;i < m;i ++)
    {
        scanf("%d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
    }
    for(int i = 0;i < n;i ++)
    {
        scanf("%d %d",&t[i][0],&t[i][1]);
    }
    for(int i = 0;i < m;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(t[j][0] >= p[i][0] && t[j][0] <= p[i][2] && t[j][1] >= p[i][1] && t[j][1] <= p[i][3])
            {
                t[j][2] ++;
                t[j][3] = i + 1;
            }
        }
    }
    for(int i = 0;i < n;i ++)
    {
        if(t[i][2] == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES %d %d\n",t[i][2],t[i][3]);
        }
    }
    return 0;
}