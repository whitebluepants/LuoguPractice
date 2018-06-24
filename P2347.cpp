#include <stdio.h>
#include <algorithm>
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
int main()
{
    int dp[1001] = {};
    int a[6] = {};
    int b[6] = {1,2,3,5,10,20};
    int count = 0;
    for(int i = 0;i < 6;i ++)
    {
        a[i] = read();
        count += a[i] * b[i];
    }
    
    for(int i = 0;i < 6;i ++)
    {
        for(int j = count;j >= b[i];j --)
        {
            for(int k = 0;k <= min(a[i],j / b[i]);k ++)
            {
                dp[j] = max(dp[j],dp[j - k*b[i]] + k * b[i]);   
            }          
        }
    }
    int sum = 0;
    for(int i = 1;i <= count;i ++)
    {
        if(dp[i] == i)
        {
            sum ++;
        }
    }
    printf("Total=%d",sum);
    
    return 0;
}