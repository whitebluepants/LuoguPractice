#include <stdio.h>
#include <string.h>
#define INF 9999999
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
int gcd(int a,int b)
{
    return b == 0?a:gcd(b,a % b);
}
int main()
{
    int a = read(),b = read(),c = read(),flag2 = 0;
    // int temp = gcd(a,b);
    // a /= temp; b /= temp;
    // int temp2 = gcd(temp,c);
    // c /= temp2;
    
    int vis[10];
    for(int i = 1;i <= 327;i ++)
    {
        memset(vis,0,sizeof(vis));
        int aa = i  * a;
        int bb = i * b;
        int cc = i * c;
        if(bb >= 1000 || cc >= 1000)
        {
            continue;
        }
        vis[aa / 100] = 1;
        vis[aa % 10] = 1;
        vis[aa % 100 / 10] = 1;
        vis[bb / 100] = 1;
        vis[bb % 10] = 1;
        vis[bb % 100 / 10] = 1;
        vis[cc / 100] = 1;
        vis[cc % 10] = 1;
        vis[cc % 100 / 10] = 1;

        int flag = 1;
        for(int j = 1;j <= 9;j ++)
        {
            if(vis[j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            flag2 = 1;
            printf("%d %d %d\n",aa,bb,cc);
        }
    }
    if(flag2 == 0)
    {
        printf("No!!!");
    }
}