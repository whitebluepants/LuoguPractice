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
int ans[100005];
int main()
{
    int n = read();
    int j = 0;
    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        
        ans[a] += b;

        if(ans[a] > ans[j])
        {
            j = a;
        }
    }
    
    printf("%d %d",j,ans[j]);

    return 0;
}