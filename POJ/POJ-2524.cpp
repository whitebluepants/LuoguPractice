#include <stdio.h>
#include <set>
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
int father[50001];
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
    father[rootx] = rooty;
}
int main()
{
    int n,m,t = 1;

    while(scanf("%d %d",&n,&m) && n && m)
    {
        for(int i = 1;i <= n;i ++)
        {
            father[i] = i;
        }
        
        for(int i = 1;i <= m;i ++)
        {
            int a = read(),b = read();
            unio(a,b);
        }
        
        set<int> s;
        for(int i = 1;i <= n;i ++)
        {
            s.insert(find(i));
        }
    
        printf("Case %d: %d\n",t ++,s.size());
    }

    return 0;
}