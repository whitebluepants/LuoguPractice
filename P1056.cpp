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
struct row
{
    int i,count;
};
struct column
{
    int i,count;
};
bool cmp1(row a,row b)
{
    if(a.count == b.count)
    {
        return a.i < b.i;
    }
    return a.count > b.count;
}
bool cmp2(column a,column b)
{
    if(a.count == b.count)
    {
        return a.i < b.i;
    }
    return a.count > b.count;
}
bool cmpp1(row a,row b)
{
    return a.i < b.i;
}
bool cmpp2(column a,column b)
{
    return a.i < b.i;
}
row r[1001];
column c[1001];
int main()
{
    int m = read(),n = read(),k = read(),l = read(),d = read();
    for(int i = 0;i < d;i ++)
    {
        int a1 = read(),b1 = read(),a2 = read(),b2 = read();

        if(a1 == a2)
        {
            if(b1 < b2)
            {
                c[b1].i = b1; 
                c[b1].count ++;
            }
            else
            {
                c[b2].count ++;
                c[b2].i = b2;
            }
        }
        else
        {
            if(a1 < a2)
            {
                r[a1].count ++;
                r[a1].i = a1;
            }
            else
            {
                r[a2].count ++;
                r[a2].i = a2;
            }
        }
    }
    sort(r + 1,r + m + 1,cmp1);
    sort(c + 1,c + n + 1,cmp2);
    sort(r + 1,r + k + 1,cmpp1);
    sort(c + 1,c + l + 1,cmpp2);

    for(int i = 1;i <= k;i ++)
    {
        printf("%d ",r[i].i);
    }
    printf("\n");
    for(int i = 1;i <= l;i ++)
    {
        printf("%d ",c[i].i);
    }

    return 0;
}