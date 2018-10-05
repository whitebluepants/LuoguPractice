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
    int number;
    int de;
    int cai;
};
int i,j,k,l;
node ans1[100001];
node ans2[100001];
node ans3[100001];
node ans4[100001];
bool cmp(node a,node b)
{
    if(a.de + a.cai == b.de + b.cai)
    {
        if(a.de == b.de)
        {
            return a.number < b.number;
        }
        return a.de > b.de;
    }
    return a.de + a.cai > b.de + b.cai;
}
int main()
{
    int n = read(),m = read(),h = read();

    for(int t = 0;t < n;t ++)
    {
        int a = read(),b = read(),c = read();
        if(b >= m && c >= m)
        {
            if(b >= h && c >= h)
            {
                ans1[i].number = a;
                ans1[i].de = b;
                ans1[i ++].cai = c;
            }
            else if(b >= h)
            {
                ans2[j].number = a;
                ans2[j].de = b;
                ans2[j ++].cai = c;
            }
            else if(b < h && c < h && b >= c)
            {
                ans3[k].number = a;
                ans3[k].de = b;
                ans3[k ++].cai = c;
            }
            else
            {
                ans4[l].number = a;
                ans4[l].de = b;
                ans4[l ++].cai = c;
            }
        }
    }
    sort(ans1,ans1 + i,cmp);
    sort(ans2,ans2 + j,cmp);
    sort(ans3,ans3 + k,cmp);
    sort(ans4,ans4 + l,cmp);

    printf("%d\n",i + j + k + l);
    for(int t = 0;t < i;t ++)
    {
        printf("%08d %d %d\n",ans1[t].number,ans1[t].de,ans1[t].cai);
    }
    for(int t = 0;t < j;t ++)
    {
        printf("%08d %d %d\n",ans2[t].number,ans2[t].de,ans2[t].cai);
    }
    for(int t = 0;t < k;t ++)
    {
        printf("%08d %d %d\n",ans3[t].number,ans3[t].de,ans3[t].cai);
    }
    for(int t = 0;t < l;t ++)
    {
        printf("%08d %d %d\n",ans4[t].number,ans4[t].de,ans4[t].cai);
    }

    return 0;
}