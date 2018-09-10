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
int dp[2001];
int a[200][2];
int b[200][3];
int c[200][2];
int main()
{
    int n = read(),m = read();
    int A = 0,B = 0,C = 0;
    for(int i = 0;i < n;i ++)
    {
        int x = read();
        if(x == 1)
        {
            a[A][0] = read(),a[A][1] = read();
            ++ A;
        }
        if(x == 2)
        {
            b[B][0] = read(),b[B][1] = read(),b[B][2] = read();
            ++ B;
        }
        if(x == 3)
        {
            c[C][0] = read(),c[C][1] = read();
            ++ C;
        }
    }
    for(int i = m;i >= 0;i --)
    {
        for(int j = 0;j < A;j ++)
        {
            for(int k = 0;k <= i;k ++)
            {
                int temp = a[j][0] * k * k - a[j][1] * k;
                dp[i] = max(dp[i],dp[i - k] + temp);
            }
        }
    }

    for(int i = 0;i < B;i ++)
    {
        // for(int j = b[i][1];j <= ( (b[i][2] * b[i][1]) > m?m:b[i][2] * b[i][1] );j ++)
        // {
        //     dp[j] = max(dp[j],dp[j - b[i][1]] + b[i][0]);
        // }
        for(int j = m;j >= b[i][1];j --)
        {
            for(int k = 1;k <= min(b[i][2],j / b[i][1]);k ++)
            {
                dp[j] = max(dp[j],dp[j - k * b[i][1]] + k * b[i][0]);   
            }
        }
    }

    for(int i = 0;i < C;i ++)
    {
        for(int j = c[i][1];j <= m;j ++)
        {
            dp[j] = max(dp[j],dp[j - c[i][1]] + c[i][0]);
        }
    }
    
    printf("%d",dp[m]);

    return 0;
}