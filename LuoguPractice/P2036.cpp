#include <stdio.h>
#include <stdlib.h>
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
int min = 2147483647;
int ans[10][2];
int n;
void search(int i,int s,int t)
{
    if(t != 0)
    {
        int a = abs(s - t);
        if(a < min)
        {
            min = a;
        }
    }
    for(;i < n;i ++)
    {
        search(i + 1,s * ans[i][0],t + ans[i][1]);
    }
}
int main()
{
    n = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read(),ans[i][1] = read();
    }

    search(0,1,0);

    printf("%d",min);

    return 0;
}