#include <stdio.h>
#include <algorithm>
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
struct node
{
    int data;
    int next;
};
node ans[100000];
int main()
{
    int n = read(),m = read(),k = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        ans[a].data = b;
        ans[a].next = c;       
    }

    int List[100000] = {};
    int nodeCount = 0;

    while(n != -1)
    {
        List[nodeCount ++] = n;
        n = ans[n].next;
    }
    
    int i = 0;
    while(i  + k <= nodeCount)
    {
        reverse(List + i,List + i + k);
        i  = i + k;
    }

    for(int i = 0;i < nodeCount - 1;i ++)
    {
        printf("%05d %d %05d\n",List[i],ans[List[i]].data,List[i + 1]);
    }
    printf("%05d %d %d\n",List[nodeCount - 1],ans[List[nodeCount - 1]].data,-1);

    return 0;
}