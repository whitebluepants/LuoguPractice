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
bool flag[300001];
int prime[300001];
int main()
{
    int n = read(),m = read();
    int count = 0;
    flag[1] = true;

    for(int i = 2;count != m;i ++)
    {
        if(!flag[i])
        {
            prime[count ++] = i;
        }
        for(int j = 0;j < count && prime[j] * i <= 110000;j ++) // 最大素数 第1w个素数为10w+
        {
            flag[prime[j] * i] = true;
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
    
    int t = 0;
    for(int i = n - 1 < 0?0:n - 1;i < m;i ++)
    {
        printf("%d",prime[i]);
        t ++;
        if(t != 10 && i != m - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
            t = 0;
        } 
    }

    return 0;
}