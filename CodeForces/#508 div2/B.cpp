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
int flag[45001];
int main()
{
    int n = read();
    
    if(n <= 2)
    {
        printf("No\n");
    }
    else
    {
        int sum1 = 0,sum2 = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(i % 2 != 0)
            {
                sum1 ++;
                flag[i] = 1;
            }
            else
            {
                sum2 ++;
            } 
        }
        printf("Yes\n");
        printf("%d",sum1);
        for(int i = 1;i <= n;i ++)
        {
            if(flag[i] == 1)
            {
                printf(" %d",i);
            }
        }
        printf("\n%d",sum2);
        for(int i = 1;i <= n;i ++)
        {
            if(!flag[i])
            {
                printf(" %d",i);
            }
        }
    }
    return 0;
}