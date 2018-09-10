#include <stdio.h>
int main()
{
    int length,n,count = 0;
    scanf("%d %d",&length,&n);
    int tree[length + 1];
    for(int i = 0;i < length + 1;i ++)
    {
    	tree[i] = 0;
    }
    for(int i = 0;i < n;i ++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        for(int j = l;j <= r;j ++)
        {
            tree[j] = 1;
        }
    }
    for(int i = 0;i <= length;i ++)
    {
        if(tree[i] == 0)
        {
            count ++;
        }
    }
    printf("%d",count);
    return 0;
}
