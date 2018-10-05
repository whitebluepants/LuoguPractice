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
    int data,next;
};
node ans[100001];
int list[100001];
int main()
{
    int n = read(),m = read(),k = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        ans[a].data = b;
        ans[a].next = c;
    }

    int i = 0;
    while(n != -1)
    {
        list[i ++] = n;
        n = ans[n].next;
    }
    
    int j = 0;
    while(j + k <= i)
    {
        reverse(list + j,list + j + k);
        j += k;
    }
    
    for(int j = 0;j < i - 1;j ++)
    {
        printf("%05d %d %05d\n",list[j],ans[list[j]].data,list[j + 1]);
    }
    printf("%05d %d %d",list[i - 1],ans[list[i - 1]].data,-1);

    return 0;
}