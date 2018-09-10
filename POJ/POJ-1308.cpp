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
int main()
{
    int x,y,i = 1;

    while(scanf("%d %d",&x,&y) && x != -1 && y != -1)
    {
        if(x == 0 && y == 0)
        {
            printf("Case %d is a tree.\n",i ++);
            continue;
        }

        int ans[1001] = {};
        int edge = 0,node = 0;
        while(x != 0 && y != 0)
        {
            ans[x] = 1,ans[y] = 1;
            edge ++;
            scanf("%d %d",&x,&y);
        }

        for(int i = 0;i <= 1000;i ++)
        {
            if(ans[i] != 0)
            {
                node ++;
            }
        }

        if(node == edge + 1)
        {
            printf("Case %d is a tree.\n",i ++);
        }
        else
        {
            printf("Case %d is not a tree.\n",i ++);
        }
    }

    return 0;
}