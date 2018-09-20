#include <stdio.h>
#define INF 99999999
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
int num[10001];
int main()
{
    int n = read();
    int ans = 0,Max = 0,flag = 0,f = 0;
    int ml = 0,mr = 0;
    int l,r;

    for(int i = 0;i < n;i ++)
    {
        num[i] = read();
        if(num[i] >= 0)
        {
            flag = 1;
        }
    }

    for(int i = 0;i < n;i ++)
    {
        int t = num[i];
        
        if(f == 0 && t > 0)
        {
            l = t;
            f = 1; 
        }

        ans += t;

        if(ans > Max)
        {
            ml = l;
            mr = t;
            Max = ans;
        }
        
        if(ans < 0)
        {
            ans = 0;
            f = 0;
        }
    }

    if(flag == 0)
    {
        Max = 0;
        ml = num[0],mr = num[n - 1];
    }
    printf("%d %d %d",Max,ml,mr);

    return 0;
}