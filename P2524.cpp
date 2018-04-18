#include <algorithm>
#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int all(int a[],int b[],int n)
{
    for(int i = 0;i < n;i ++)
    {
        if(a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = read();
    int a[9] = {};
    for(int i = 0;i < n;i ++)
    {
        scanf("%1d",&a[i]);
    }
    int b[9] = {1,2,3,4,5,6,7,8,9};

    int count = 0;

    do
    {
        count ++;
        if(all(a,b,n))
        {
            break;
        }
    }while(next_permutation(b,b + n));

    printf("%d",count);

    return 0;
}