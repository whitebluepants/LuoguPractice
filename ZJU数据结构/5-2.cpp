#include <stdio.h>
#include <map>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
map<int,int> m;
int father[10005];
int level[10005];
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
void unionSet(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx == rooty)
    {
        return ;
    }
    if(level[rootx] < level[rooty])
    {
        father[rootx] = rooty;
    }
    else
    {
        father[rooty] = rootx;
        if(level[rootx] == level[rooty])
        {
            level[rootx] ++;
        }
    }
}
int main()
{
    int n = read();

    for(int i = 1;i <= n;i ++)
    {
        father[i] = i;
    }

    char ch;
    scanf(" %c",&ch);
    while(ch != 'S')
    {
        int a = read(),b = read();
        if(ch == 'I')
        {
            unionSet(a,b);
        }
        else if(ch == 'C')
        {
            if(find(a) == find(b))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        scanf(" %c",&ch);
    }

    int count = 0;

    for(int i = 1;i <= n;i ++)
    {
        int t = find(i);
        if(m[t] == 0)
        {
            m[t] ++;
            count ++;
        }
    }
    if(count == 1)
    {
        printf("The network is connected.");
    }
    else
    {
        printf("There are %d components.",count);
    }

    return 0;
}