#include <stdio.h>
int main()
{
    int count = 0;
    char s[201];
    gets(s);

    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == ' ')
        {
            count += 1;
        }
        else if(s[i] >= 97 && s[i] <= 99)
        {
            count += s[i] - 96;
        }
        else if(s[i] >= 100 && s[i] <= 102)
        {
            count += s[i] - 99;
        }
        else if(s[i] >= 103 && s[i] <= 105)
        {
            count += s[i] - 102;
        }
        else if(s[i] >= 106 && s[i] <= 108)
        {
            count += s[i] - 105;
        }
        else if(s[i] >= 109 && s[i] <= 111)
        {
            count += s[i] - 108;
        }
        else if(s[i] >= 112 && s[i] <= 115)
        {
            count += s[i] - 111;
        }
        else if(s[i] >= 116 && s[i] <= 118)
        {
            count += s[i] - 115;
        }
        else if(s[i] >= 119 && s[i] <= 122)    
        {
            count += s[i] - 118;
        }
    }

    printf("%d",count);

    return 0;
}
