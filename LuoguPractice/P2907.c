#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int k;
int count = 1;
void search(int n)
{
    if(n - k <= 0)
    {
        return ;
    }
    
    if( (n - k) / 2 == (n - k) / 2.0)
    {
        count ++;
        search((n - k) / 2);
        search((n - k) / 2 + k);
    }
}
int main()
{
    int n = read();
    k = read();
    
    search(n);

    printf("%d",count);

    return 0;
}