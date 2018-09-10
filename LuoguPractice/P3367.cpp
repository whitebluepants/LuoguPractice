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
int father[10001];
int rank[10001];
int find(int x)
{
    if(x == father[x])
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
        return;
    }

    if(rank[rootx] < rank[rooty])
    {
        father[rootx] = rooty;
    }
    else
    {
        father[rooty] = rootx;
        if(rank[rootx] == rank[rooty])
        {
            rank[rootx] ++;
        }
    }
}
int main()
{
    int n = read(),m = read();

    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        if(a == 1) // union
        {
            unio(b,c);
        }
        else       // find
        {
            if(find(b) == find(c))
            {
                printf("Y\n");
            }
            else
            {
                printf("N\n");
            }
        }
    }

    return 0;
}