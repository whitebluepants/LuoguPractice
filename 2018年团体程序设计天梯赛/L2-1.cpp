#include <stdio.h>
#include <string.h>
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
int main()
{
    int n = read(),m = read();
    node ans[10005];

    for(int i = 0;i < m;i ++)
    {
        ans[i].a = read(),ans[i].b = read();
    }

    int k = read();
    int f[10005];

    for(int i = 0;i < k;i ++)
    {
        int t = read();
        memset(f,0,sizeof(f));
        for(int j = 0;j < t;j ++)
        {
            int temp = read();
            f[temp] = 1;
        }
        
        int flag = 0;
        for(int j = 0;j < m;j ++)
        {
            if(f[ans[j].a] || f[ans[j].b])
            {
                continue;
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}