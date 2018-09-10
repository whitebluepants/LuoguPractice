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
int father[30000];
int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x]);
    }
}
void unio(int x,int y)
{
    int rootx = find(x),rooty = find(y);

    if(rootx == rooty)
    {
        return ;
    }

    if(rootx == 0)
    {
        father[rooty] = rootx;
    }
    else if(rooty == 0)
    {
        father[rootx] = rooty; 
    }
    else
    {
        father[rooty] = rootx;
    }
}
int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m) && !(m == 0 && n == 0))
    {
        for(int i = 0;i < n;i ++)
        {
            father[i] = i;
        }

        for(int i = 0;i < m;i ++)
        {
            int f1,f2;
            int j = read();
            if(j != 0)
            {
                f1 = read();
            }
            for(int k = 0;k < j - 1;k ++)
            {
                f2 = read();
                unio(f1,f2);
            }
        }
        int count = 0;
        for(int i = 0;i < n;i ++)
        {
            if(find(i) == 0)
            {
                count ++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}