#include <stdio.h>
#include <algorithm>
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
struct node
{
    int a,b;
};
bool cmp(node a,node b)
{
    return a.b < b.b;
}
int main()
{
    int g = read();

    for(int i = 0;i < g;i ++)
    {
        int n = read();
        node ans[51] = {};

        for(int i = 0;i < n;i ++)
        {
            ans[i].a = read(),ans[i].b = read();
        }

        sort(ans,ans + n,cmp);

        int p = 0,flag = 1;
        for(int i = 0;i < n;i ++)
        {
            if(ans[i].a == 0 && ans[i].b == 0)
            {
                continue;
            }
            if(abs(ans[i].a - p) > ans[i].b)
            {
                flag = 0;
                break;
            }
            p = ans[i].a;
            for(int j = i + 1;j < n;j ++)
            {
                ans[j].b --;
            }
        }

        if(flag == 1)
        {
            printf("Abletocatch\n");
        }     
        else
        {
            printf("Notabletocatch\n");
        }        
    }
    
    return 0;
}