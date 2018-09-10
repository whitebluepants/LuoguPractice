#include <stdio.h>
#include <string.h>
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
int dp[100000];
int ans[100000];
int main()
{
    int count = 0;
    int i = 0,n;
    scanf("%d",&n);
    ans[i ++] = n;
    dp[count ++] = n;

    while(scanf("%d",&n) != EOF)
    {
        ans[i ++] = n;
        
        if(dp[count - 1] >= n)
        {
            dp[count] = n;
            count ++;
        }
        else
        {
            int begin = 0,end = count - 1;
            int mid = (begin + end) / 2;
            while(begin <= end)
            {
                mid = (begin + end) / 2;
                if(n <= dp[mid])
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            dp[begin] = n;
        }
    }
    
    int count2 = 1;
    memset(dp,0,sizeof(dp));
    dp[0] = ans[0];
    for(int j = 1;j < i;j ++)
    {
        if(dp[count2 - 1] < ans[j])
        {
            dp[count2] = ans[j];
            count2 ++;
        }
        else
        {
            int begin = 0,end = count2 - 1;
            while(begin <= end)
            {
                int mid = (begin + end) / 2;
                if(dp[mid] >= ans[j])
                {
                    end = mid - 1;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            dp[begin] = ans[j];
        }
    }

    printf("%d\n%d",count,count2);

    return 0;
}