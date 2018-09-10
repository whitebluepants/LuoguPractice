#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    int max = a,min = a;
    if(b > max && b > c)
    {
        max = b;
    }
    else if(c > max && c > b)
    {
        max = c;
    }
    if(b < min && b < c)
    {
        min = b;
    }
    else if(c < min && c < b)
    {
        min = c;
    }

    a = max, b = min;
    int temp = a % b;

    while(temp != 0)
    {
        a = b;
        b = temp;
        temp = a % b;
    }

    printf("%d/%d",min / b,max / b);
}
