#include <math.h>
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
bool flag[10000001]; // true - NotPrime  false - Prime
int prime[10000001];
int main()
{
    int n = read(),m = read();
    int pnum = 0;

    flag[0] = true, flag[1] = true;

    for(int i = 2;i <= n / 2;i ++)
    {
        if(flag[i] == false)
        {
            prime[pnum ++]  = i;
        }

        for(int j = 0;j < pnum && i * prime[j] <= n;j ++)
        {
            flag[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }

    for(int i = 0;i < m;i ++)
    {
        int t = read();
        if(flag[t] == true)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }

    return 0;
}