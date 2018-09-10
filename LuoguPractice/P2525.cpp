#include <stdio.h>
#include <algorithm>
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
int main()
{
    int n = read(),flag = 0;
    int a[9] = {};
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
        if(i != 0 && a[i] < a[i - 1])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("ERROR");
    }
    else
    {
        prev_permutation(a,a + n);
        for(int i = 0;i < n;i ++)
        {
            printf("%d ",a[i]);
        }
    }
    
    return 0;
}