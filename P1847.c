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
        
    }
}