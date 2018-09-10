#include <stdio.h>
#include <map>
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
int a[100001];
int main()
{
    map<int,int> mm;
    int n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
        mm[a[i]] ++;
    }
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        mm[t] ++;
    }
    
    for(int i = 0;i < n;i ++)
    {
        if(mm[a[i]] == 2)
        {
            printf("%d ",a[i]);
        }
    }

    return 0;
}