#include <stdio.h>
long long read()
{
    char ch = getchar();
    long long f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    long long a[15] = {};
    for(long long i = 1;i <= 14;i ++)
    {
        a[i] = read();
    }
    long long max = 0;
    long long temp[15] = {};
    for(long long i = 1;i <= 14;i ++)
    {
        for(long long j = 1;j <= 14;j ++)
        {
            temp[j] = a[j];
        }

        if(temp[i] != 0)
        {
            long long t = temp[i];
            temp[i] = 0;
            long long q = t / 14;
            long long w = t % 14;

            for(long long l = 1;l <= 14;l ++)
            {
                temp[l] += q;
            }
            long long x = i + 1;
            for(long long l = 0;l < w;l ++)
            {
                if(x > 14)
                {
                    x = 1;
                }
                temp[x ++] ++;
            }
        }
        long long sum = 0;
        for(long long j = 1;j <= 14;j ++)
        {
            if(temp[j] % 2 == 0)
            {
                sum += temp[j];
            }
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    printf("%lld",max);

    return 0;
}