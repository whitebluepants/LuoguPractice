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
    int a = read();
    char ch;

    scanf(" %c",&ch);

    int r = (int)(1.0 * a / 2 + 0.5);

    for(int i = 0;i < r;i ++)
    {
        if(i == 0 || i == r - 1)
        {
            for(int j = 0;j < a;j ++)
            {
                printf("%c",ch);
            }
            if(i == 0)
            {
                printf("\n");
            }
        }
        else
        {
            printf("%c",ch);
            for(int i = 0;i < a - 2;i ++)
            {
                printf(" ");
            }
            printf("%c\n",ch);
        }
    }

    return 0;
}