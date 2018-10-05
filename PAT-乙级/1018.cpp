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
    char t;
    int count;
    bool operator < (const node &a) const
    {
        if(count == a.count)
        {
            return t < a.t;
        }
        return count > a.count;
    }
};
node a[3];
node b[3];
int main()
{
    int n = read();

    a[0].t = 'C',a[1].t = 'J',a[2].t = 'B';
    b[0].t = 'C',b[1].t = 'J',b[2].t = 'B';
    int a1 = 0,a2 = 0,mid = 0;
    for(int i = 0;i < n;i ++)
    {
        char n,m;
        scanf(" %c %c",&n,&m);

        if(n == m)
        {
            mid ++;
            continue;
        }

        if(n == 'C')
        {
            if(m == 'J')
            {
                a[0].count ++;
                a1 ++;
            }
            else
            {
                b[2].count ++;
                a2 ++;
            }
        }
        if(n == 'J')
        {
            if(m == 'B')
            {
                a[1].count ++;
                a1 ++;
            }
            else
            {
                b[0].count ++;
                a2 ++;
            }
        }
        if(n == 'B')
        {
            if(m == 'C')
            {
                a[2].count ++;
                a1 ++;
            }
            else
            {
                b[1].count ++;
                a2 ++;
            }
        }
    }
    printf("%d %d %d\n%d %d %d\n",a1,mid,a2,a2,mid,a1);
    sort(a,a + 3);
    sort(b,b + 3);
    printf("%c %c",a[0].t,b[0].t);
    
    return 0;
}