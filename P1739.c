#include <stdio.h>
int main()
{
    int left = 0,right = 0,flag = 1;
    char c = 0;

    while((c = getchar()) != '@')
    {
        if(c == '(')
        {
            left ++;
        }
        if(c == ')')
        {
            right ++;
        }
        if(right > left)
        {
            flag = 0;
        }
    }
    if(flag == 1 && right == left)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}