#include <stdio.h>
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
    char s[105] = {};
    scanf("%s",s);

    int num1 = 0,num2 = 0;
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'o')
        {
            num1 ++;
        }
        else if(s[i] == '-')
        {
            num2 ++;
        }
    }
    
    if(num1 <= 1 || num2 == 0)
    {
        printf("YES");
    }
    else if(num2 >= num1 && num2 % num1 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}