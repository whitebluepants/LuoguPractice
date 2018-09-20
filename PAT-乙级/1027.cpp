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
    int n = read();
    char ch;
    scanf(" %c",&ch);

    int level = 0,cnt = 0,l,m;

    for(int i = 1;;i += 2)
    {
        if(i == 1)
        {
            cnt += i;
            level ++;
            m = 1;
        }
        else
        {
            if(cnt + 2*i <= n)
            {
                cnt += 2 * i;
                m += 2;
                level ++;
            }
            else
            {
                l = n - cnt;
                break;
            }
        }
    }
    
    int flag = 0;
    for(int i = 0;i < 2 * level - 1;i ++)
    {
        if(i == level - 1)
        {
            for(int j = 0;j < level - 1;j ++)
            {
                printf(" ");
            }
            printf("%c\n",ch);
            flag = 1;
        }
        else
        {
            if(flag == 0)
            {
                for(int j = 0;j < i;j ++)
                {
                    printf(" ");
                }
                for(int j = 0;j < m - 2*i;j ++)
                {
                    printf("%c",ch);
                }
                printf("\n");
            }
            else
            {
                for(int j = 0;j < 2*level- 2 - i;j ++)
                {
                    printf(" ");
                }
                for(int j = 0;j < m - (2 * (2*level-2 - i));j ++)
                {
                    printf("%c",ch);
                }
                printf("\n");
            }
        }
    }

    printf("%d",l);

    
    return 0;
}