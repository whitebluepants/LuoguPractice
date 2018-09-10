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
bool flag[10000001];
int n,m;
int main()
{
    n = read(),m = read();
    flag[1] = true;
    flag[0] = true;
    
    for(int i = 2;i * i < n;i ++)
    {
        if(!flag[i])
        {
            for(int j = i * 2;j <= n;j += i)
            {
                flag[j] = true;
            }
        }
    }
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        if(flag[t])
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