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
struct cmp
{
    bool operator () (int a,int b)
    {
        return a < b;
    }
};
int a,b,c;
int visited[21][21][21];
set<int,cmp> s;
void dfs(int x,int y,int z)
{
    if(x < 0 || x > a || y < 0 || y > b || z < 0 || z > c)
    {
        return;
    }
    if(visited[x][y][z] == 1)
    {
        return;
    }
    else
    {
        visited[x][y][z] = 1;
    }
    if(x == 0)
    {
        s.insert(z);
    }
    dfs(0,y + x,z);
    dfs(0,y,z + x);
    dfs(x + y,0,z);
    dfs(x,0,z + y);
    dfs(x,y + z,0);
    dfs(x + z,y,0);
    dfs(x - b + y,b,z);
    dfs(x - c + z,y,c);
    dfs(a,y - a + x,z);
    dfs(x,y - c + z,c);
    dfs(a,y,z - a + x);
    dfs(x,b,z - b + y);
}
int main()
{
    a = read(),b = read(),c = read();
    dfs(0,0,c);

    set<int,cmp>::iterator itr;

    for(itr = s.begin();itr != s.end();itr ++)
    {
        printf("%d ",*itr);
    }
    
    return 0;
}