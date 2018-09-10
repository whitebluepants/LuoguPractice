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
int x,y;
int count;
int dx[4] = {2,-2,1,-1};
int dy[4] = {1,1,2,2};
void dfs(int a,int b)
{
    if(a == x && b == y)
    {
        count ++;
        return ;
    }

    for(int i = 0;i < 4;i ++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if(nx >= 0 && nx <= x && ny >= 0 && ny <= y)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    x = read(),y = read();

    dfs(0,0);

    printf("%d",count);

    return 0;
}