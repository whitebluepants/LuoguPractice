#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-1*x;
}
int main()
{
    int n = read();
    int count = 0;
    int ans[100][10];
    if(n < 10 || n > 30)
    {
        printf("0");
        return 0;
    }

    for(int i = 1;i <= 3;i ++)
    {
        for(int j = 1;j <= 3;j ++)
        {
            for(int k = 1;k <= 3;k ++)
            {
                for(int l = 1;l <= 3;l ++)
                {
                    for(int q = 1;q <= 3;q ++)
                    {
                        for(int w = 1;w <= 3;w ++)
                        {
                            for(int e = 1;e <= 3;e ++)
                            {
                                for(int r = 1;r <= 3;r ++)
                                {
                                    for(int t = 1;t <= 3;t ++)
                                    {
                                        for(int y = 1;y <= 3;y ++)
                                        {
                                            if(i + j + k + l + q + w + e + r + t + y == n)
                                            {
                                                ans[count][0] = i;
                                                ans[count][1] = j;
                                                ans[count][2] = k;
                                                ans[count][3] = l;
                                                ans[count][4] = q;
                                                ans[count][5] = w;
                                                ans[count][6] = e;
                                                ans[count][7] = r;
                                                ans[count][8] = t;
                                                ans[count ++][9] = y;
                                                //printf("%d %d %d %d %d %d %d %d %d %d\n",i,j,k,l,q,w,e,r,t,y);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",count);
    for(int i = 0;i < count;i ++)
    {
        printf("%d %d %d %d %d %d %d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3],ans[i][4],ans[i][5],ans[i][6],ans[i][7],ans[i][8],ans[i][9]);
    }
    return 0;
}