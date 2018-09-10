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
int aa[200],bb[200];
int main()
{
    int n = read(),a = read(),b = read();

    for(int i = 0;i < a;i ++)
    {
        aa[i] = read();
    }
    for(int i = 0;i < b;i ++)
    {
        bb[i] = read();
    }
    int score1 = 0,score2 = 0;
    int a1 = 0,b1 = 0;
    for(int i = 0;i < n;i ++)
    {
        int q = aa[a1 ++],p = bb[b1 ++];
        if(a1 >= a)
        {
            a1 = 0;
        }
        if(b1 >= b)
        {
            b1 = 0;
        }
        
        if((q == 0 && p == 2) || (q == 0 && p == 3) || (q == 1 && p == 3) || (q == 2 && p == 4) || (q == 3 && p == 4) || (q == 1 && p == 0) || (q == 2 && p == 1) || (q == 3 && p == 2) || (q == 4 && p == 0) || (q == 4 && p == 1))
        {
            score1 ++;
        }
        else if(q != p)
        {
            score2 ++;
        }
    }

    printf("%d %d",score1,score2);

    return 0;
}