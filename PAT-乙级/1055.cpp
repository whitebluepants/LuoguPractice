#include <algorithm>
#include <string.h>
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
struct node
{
    char s[20];
    int height;
};
node ans[10010];
node p[11][10010];
bool cmp(node a,node b)
{
    if(a.height == b.height)
    {
        // return a.s < b.s;
        // char数组的字符串不能直接比较排序字典顺序
        // 直接比较的是比较两者的地址 前3个点侥幸地址顺序和字典顺序相同 后3个点不会
        // 应该使用strcmp函数 或者使用string类型
        return strcmp(a.s,b.s) < 0;
    }
    return a.height > b.height;
}
int main()
{
    int n = read(),k = read();
    int c = n / k;
    int temp = n % k;

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",ans[i].s);
        ans[i].height = read();
    }

    sort(ans,ans + n,cmp);

    int count = 0;
    for(int i = 0;i < k;i ++)
    {
        int left,right,mid;
        if(i == 0)
        {
            mid = (c + temp) / 2 + 1;
            left = mid - 1;
            right = mid + 1;
            
            p[i][mid] = ans[count ++];
            int flag = 1;
            for(int j = 0;j < c + temp - 1;j ++)
            {
                if(flag && left >= 1)
                {
                    p[i][left --] = ans[count ++];
                }
                else if(right <= c + temp)
                {
                    p[i][right ++] = ans[count ++];
                }
                flag ^= 1;
            }
        }
        else
        {
            mid = c / 2 + 1;
            left = mid - 1;
            right = mid + 1;

            p[i][mid] = ans[count ++];
            int flag = 1;
            for(int j = 0;j < c - 1;j ++)
            {
                if(flag && left >= 1)
                {
                    p[i][left --] = ans[count ++];
                }
                else if(right <= c)
                {
                    p[i][right ++] = ans[count ++];
                }
                flag ^= 1;
            }
        }
    }

    for(int i = 0;i < k;i ++)
    {
        int flag = 0;
        for(int j = 1;j <= (i == 0?c + temp:c);j ++)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%s",p[i][j].s);
            flag = 1;
        }
        printf("\n");
    }

    return 0;
}