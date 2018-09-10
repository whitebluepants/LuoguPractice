#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
    bool operator () (int a,int b)
    {
        return a > b;
    }
};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();
    priority_queue<int,vector<int>,cmp> pq;
    int count = 0;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        pq.push(t);
    }
    if(n == 1)
    {
        printf("%d",pq.top());
        return 0;
    }
    while(pq.size() != 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b);
        count += (a + b);
    }
    printf("%d",count);

    return 0;
}