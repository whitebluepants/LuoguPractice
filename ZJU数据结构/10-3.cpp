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
int a[100010];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }

    int count = 0,p = 0;
    if(a[0] == 0)
    {
        p ++;
    }
    for(int i = 0;i < n;i ++)
    {
        int num = 0;
        while(a[i] != i)
        {
            num ++;
            int temp = i;
            i = a[i];
            a[temp] = temp;
        }
        if(num != 0)
        {
            num --;
            p ++;
        }
        count += num;
    }
    if(p > 0)
    {
        count += (p - 1) * 2;
    }
    
    printf("%d",count);

    return 0;
}