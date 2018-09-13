// 注意递减 0 0 -1 -2 这样的数据
#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int ans[1005][2];
int main()
{
    int i = 0;
    int a,b;

    while(scanf("%d %d",&a,&b) != EOF)
    {
        ans[i][0] = a;
        ans[i ++][1] = b;
    }
    
    if(ans[0][1] == 0 && ans[1][1] == 0)
    {
        printf("0 0");
        return 0;
    }
    
    int flag = 0;
    for(int j = 0;j < i;j ++)
    {
        if(ans[j][1] != 0)
        {
            if(flag != 0)
            {
                printf(" ");
            }
            printf("%d %d",ans[j][0] * ans[j][1],ans[j][1] - 1);
            flag = 1;
        }
    }

    return 0;
}