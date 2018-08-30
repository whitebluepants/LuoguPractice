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
int father[5001];
int rank[5001];
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

    if(rank[rootx] > rank[rooty])
    {
        father[rooty] = rootx;
    }
    else
    {
        father[rootx] = rooty;
        if(rank[rootx] == rank[rooty])
        {
            rank[rooty] ++;
        }
    }
}
int main()
{
    int n = read(),m = read(),p = read();
    
    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }
    
    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read();
        unio(a,b);
    }

    for(int i = 0;i < p;i ++)
    {
        int a = read(),b = read();
        if(find(a) == find(b))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}