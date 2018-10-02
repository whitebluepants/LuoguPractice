#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int ans[1005][1005];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
map<int,int> mm;
/*
    注意题目有一个要求 要求这个像素点是独一无二的
    所以用map记录每个像素点出现的次数加判断
    然后还有一个坑点 边缘点也是要考虑的
    所以在判断周围8个相邻像素的时候,边缘点要考虑它们的外层
    这个只需要把数据从1开始读起即可容易解决
*/
int main()
{
    int n = read(),m = read(),kk = read();
    
    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            ans[i][j] = read();
            mm[ans[i][j]] ++;
        }
    }
    
    if(n == m && n== 1)
    {
        printf("(%d, %d): %d",1,1,ans[1][1]);
        return 0;
    }
    
    int flag1 = 0,flag2 = 0;
    int x,y;
    
    for(int i = 1;i <= m;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            int flag = 0;
            for(int k = 0;k < 8;k ++)
            {
                if(mm[ans[i][j]] > 1)
                {
                    flag = 1;
                    break;
                }
                
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx >= 0 && nx <= m + 1 && ny >= 0 && ny <= n + 1)
                {
                    if(abs(ans[i][j] - ans[nx][ny]) <= kk)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
            {
                if(flag1 == 0)
                {
                    flag1 = 1;
                    x = i,y = j;
                    
                }
                else
                {
                    flag2 = 1;
                    break;
                }
            }
        }
    }
    
    if(flag1 == 0)
    {
        printf("Not Exist");
    }
    else
    {
        if(flag2 == 1)
        {
            printf("Not Unique");
        }
        else
        {
            printf("(%d, %d): %d",y,x,ans[x][y]);
        }
    }

    return 0;
}  