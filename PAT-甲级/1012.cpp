#include <stdio.h>
#include <set>
#include <iterator>
#include <iostream>
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
    int flag;
    int c,m,e;
    double a;
};
node ans[1000001];
multiset<int,greater<int> > c,m,e;
multiset<double,greater<double> > a;
int main()
{
    int n = read(),mm = read();
    for(int i = 0;i < n;i ++)
    {
        int index = read();
        ans[index].flag = 1;
        ans[index].c = read();
        ans[index].m = read();
        ans[index].e = read();
        ans[index].a = (ans[index].c + ans[index].m + ans[index].e) * 1.0 / 3;
        c.insert(ans[index].c);
        m.insert(ans[index].m);
        e.insert(ans[index].e);
        a.insert(ans[index].a);
    }

    for(int i = 0;i < mm;i ++)
    {
        int index = read();
        
        if(ans[index].flag == 0)
        {
            printf("N/A\n");
        }
        else
        {
            int min = 99999,flag = 0;
            int rank;
            for(int i = 0;i < 4;i ++)
            {
                if(i == 0)
                {
                    rank = distance(a.begin(),a.find(ans[index].a));       
                }
                else if(i == 1)
                {
                    rank = distance(c.begin(),c.find(ans[index].c));
                }
                else if(i == 2)
                {
                    rank = distance(m.begin(),m.find(ans[index].m));
                }
                else
                {
                    rank = distance(e.begin(),e.find(ans[index].e));
                }

                if(rank < min)
                {
                    min = rank;
                    flag = i;
                }
            }
            printf("%d",min + 1);
            switch(flag)
            {
                case 0: printf(" A\n"); break;
                case 1: printf(" C\n"); break;
                case 2: printf(" M\n"); break;
                case 3: printf(" E\n");
            }
        }
    }

    return 0;
}