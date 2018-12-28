#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
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
long long cnt[1000000];
int main()
{
    freopen("in.txt","r",stdin);
    int n = read(),k = read();
    string s = "";
    
    int count = 0,i = 0;
    while(n > 0)
    {
        int temp = n % 2;
        cnt[i ++] = temp;
        s = char((temp + '0')) + s;
        n /= 2;
        if(temp == 1)
        {
            count ++;
        }    
    }

    if(count > k)
    {
        printf("NO");
    }
    else if(count == k)
    {
        printf("YES\n");
        for(int j = 0;j < i;j ++)
        {
            if(cnt[j] == 1)
            {
                printf("%d ",(int)pow(2,j));
            }
        }
    }
    else
    {
        for(int j = i - 1;count != k && j > 0;j --)
        {
            if(cnt[j] > 0)
            {
                if(count + cnt[j] < k)
                {
                    cnt[j - 1] += cnt[j] * 2;
                    count += cnt[j];
					cnt[j] = 0;
                }
                else if(( k - (count - cnt[j]) ) / 2 <= cnt[j])
                {
                    int temp = ( k - (count - cnt[j]) ) / 2;
                    cnt[j] -= temp;
                    cnt[j - 1] += temp * 2;
                    count += temp;
                }
            }
        }

        if(count != k)
        {
            printf("NO");
        }
        else
        {
            printf("YES\n");
            for(int j = 0;j < i;j ++)
            {
                if(cnt[j] > 0)
                {
                    for(int k = 0;k < cnt[j];k ++)
                    {
                        printf("%d ",(int)pow(2,j));
                    }
                }
            }
        }
    }

    return 0;
}