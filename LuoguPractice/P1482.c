#include <stdio.h>
int main()
{
    int temp,a,b,a2,b2;
    scanf("%d/%d",&a,&b);
    scanf("%d/%d",&a2,&b2);

    a = a * a2;
    b = b * b2;
    a2 = a, b2 = b;
    temp = a % b;
    while(temp != 0)
    {
        a = b;
        b = temp;
        temp = a % b;
    }
    a2 /= b; b2 /= b;
    printf("%d %d",b2,a2);

    return 0;
}