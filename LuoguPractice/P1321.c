#include <stdio.h>
int main()
{
    char s[300];
    int a[7] = {};
    int boy = 0,girl = 0;
    scanf("%s",s);
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y')
        {
            boy ++;
        }
        if(s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l')
        {
            girl ++;
        }
    }
    
    printf("%d\n%d",boy,girl);
    return 0;
}