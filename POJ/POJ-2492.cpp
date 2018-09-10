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
int father[2010];
int ans[2010];
int oper[1000002][2];
int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        int temp = father[x];
        father[x] = find(father[x]);
        ans[x] = (ans[temp] + ans[x]) % 2;
        return father[x];
    }
}
void unio(int x,int y)
{
    int rootx = find(x), rooty = find(y);

    if(rootx == rooty)
    {
        return ;
    }

    father[rooty] = rootx;
    ans[rooty] = (ans[x] + 2 - 1 + 2 - ans[y]) % 2;
}
int main()
{
    int n = read();

    for(int j = 0;j < n;j ++)
    {
        int x = read(),y = read();
        for(int i = 1;i <= x;i ++)
        {
            father[i] = i;
            ans[i] = 0;
        }
        
        for(int i = 1;i <= y;i ++)
        {
            int a = read(),b = read();
            oper[i][0] = a,oper[i][1] = b;
            unio(a,b);
        }

        int flag = 0;
        for(int i = 1;i <= y;i ++)
        {
            if(find(oper[i][0]) == find(oper[i][1]) && ans[oper[i][0]] == ans[oper[i][1]])
            {
                flag = 1;
                break;
            }
        }
        
        printf("Scenario #%d:\n",j + 1);
        if(flag == 1)
        {
            printf("Suspicious bugs found!\n\n");
        }
        else
        {
            printf("No suspicious bugs found!\n\n");
        }
    }

    return 0;
}