#include <stdio.h>
#include <string.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    char s[300] = {};
    scanf("%s",s);
    int count = 0,len = strlen(s),flag = 0;

    for(int i = 0;s[i + 1] != '\0';i ++)
    {
        if(s[i] != s[i + 1])
        {
            count ++;
            if(i + 1 == len - 1)
            {
                flag = 1;
            }
        }
    }
    if(flag == 1 && s[len - 1] == '0' || s[len - 1] == '0' && s[len - 2] == '0')
    {
        count ++;
    }
    if(len == 1 && s[len - 1] == '0')
    {
        count = 1;
    }
    printf("%d",count);

    return 0;
}