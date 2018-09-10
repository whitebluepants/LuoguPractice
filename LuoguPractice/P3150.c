#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%d",&m);
        if(m % 2 == 0)
        {
            printf("pb wins\n");
        }
        else
        {
            printf("zs wins\n");
        }
    }
    return 0;
}