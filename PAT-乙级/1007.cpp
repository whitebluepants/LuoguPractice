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
bool flag[100001];
int prime[100001];
int main()
{
    int n = read();

    flag[1] = true; // true Not prime
    int count = 0;

    for(int i = 2;i <= n;i ++)
    {
        if(!flag[i])
        {
            prime[count ++] = i;
        }

        for(int j = 0;j < count && prime[j] * i <= n;j ++)
        {
            flag[prime[j] * i] = true;
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }

    int cnt = 0;
    for(int i = 0;i < count - 1;i ++)
    {
        if(prime[i + 1] - prime[i] == 2)
        {
            cnt ++;
        }
    }

    printf("%d",cnt);

    return 0;
}