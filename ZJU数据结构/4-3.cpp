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
    node* left;
    node* right;
};
typedef node* List;
int a[1005];
int b[1005];
int j;
void midtree(int root,int n)
{
    if(root <= n)
    {
        midtree(root * 2,n);
        b[root] = a[j ++];
        midtree(root * 2 + 1,n);
    }
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    sort(a,a + n);

    midtree(1,n);

    printf("%d",b[1]);
    for(int i = 2;i <= n;i ++)
    {
        printf(" %d",b[i]);
    }

    return 0;
}