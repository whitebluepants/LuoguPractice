#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int t = n % m; //15 % 4 = 3
    int a = n / m; //15 / 4 = 3

    for(int i = t;i < m;i ++)
    {
        printf("%d ",a);
    }
    for(int i = 0;i < t;i ++)
    {
        printf("%d ",a + 1);
    }
    
    return 0;
}