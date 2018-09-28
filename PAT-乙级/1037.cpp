#include <stdio.h>
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
int main()
{
    int a1,b1,c1,a2,b2,c2;
    scanf("%d.%d.%d",&a1,&b1,&c1);
    scanf("%d.%d.%d",&a2,&b2,&c2);
    int a3,b3,c3;
    int flag = 0;
    
    if(a2 > a1 || a2 == a1 && b2 > b1 || a2 == a1 && b2 == b1 && c2 >= c1)
    {
        if(c2 < c1)
        {
            c2 += 29;
            b2 --;
        }
        c3 = c2 - c1;
        if(b2 < b1)
        {
            b2 += 17;
            a2 --;
        }
        b3 = b2 - b1;
        a3 = a2 - a1;
    }
    else
    {
        if(c1 < c2)
        {
            c1 += 29;
            b1 --;
        }
        c3 = c1 - c2;
        if(b1 < b2)
        {
            b1 += 17;
            a1 --;
        }
        b3 = b1 - b2;
        a3 = a1 - a2;
        flag = 1;
    }
    if(flag)
    {
        printf("-");
    }
    printf("%d.%d.%d",a3,b3,c3);

    return 0;
}