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
int father[1001];
int rank1[1001];
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
    int rootx = find(x), rooty = find(y);
    if(rootx == rooty)
    {
        return ;
    }

    if(rank1[rootx] > rank1[rooty])
    {
        father[rooty] = rootx;
    }
    else
    {
        father[rootx] = rooty;
        if(rank1[rootx] == rank1[rooty])
        {
            rank1[rooty] ++;
        }
    }
}
int main()
{
    int n,m;
    
    while(scanf("%d",&n) && n != 0)
    {
        m = read();

        for(int i = 1;i <= n;i ++)
        {
            father[i] = i;
            rank1[i] = 0;
        }

        for(int i = 1;i <= m;i ++)
        {
            int a = read(),b = read();
            unio(a,b);
        }

        int count = 0;
        map<int,int> m;

        for(int i = 1;i <= n;i ++)
        {
            if(i == 1)
            {
                m[find(i)] ++;
            }
            else
            {
                if(m[find(i)] == 0)
                {
                    count ++;
                    m[find(i)] ++;
                }
            }
        }

        printf("%d\n",count);
    }

    return 0;
}